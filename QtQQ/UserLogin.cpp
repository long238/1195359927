#include "UserLogin.h"
#include "CCMainWindow.h"
#include <QMessagebox>
#include <QSqlDatabase>
#include <QSqlQuery>

QString gLoginEmployeeID;//登录者QQ号（员工号）

UserLogin::UserLogin(QWidget *parent)
	: BasicWindow(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	initTitleBar(MIN_MAX_BUTTON);
	setTitleBarTitle("", ":/Resources/MainWindow/qqlogoclassic.png");
	loadStyleSheet("UserLogin");
	initControl();
}

UserLogin::~UserLogin()
{
}

void UserLogin::initControl()
{
	QLabel *headlabel = new QLabel(this);
	headlabel->setFixedSize(68, 68);
	QPixmap pix(":/Resources/MainWindow/head_mask.png");
	headlabel->setPixmap(getRoundImage(QPixmap(":/Resources/MainWindow/app/logo.ico"), pix, headlabel->size()));
	headlabel->move(width() / 2 - 34, ui.titleWidget->height() - 34);
	connect(ui.loginBtn, &QPushButton::clicked, this, &UserLogin::onLoginBtnClicked);
	
	//连接数据库
	if (!connectMySql())
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("连接数据库失败"));
		close();
	}
}

bool UserLogin::connectMySql()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setDatabaseName("qtqq");
	db.setHostName("localhost");
	db.setUserName("root");
	db.setPassword("123456");
	db.setPort(3306);

	if (db.open())
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

bool UserLogin::veryfyAccountCode(bool &isAccountLogin, QString &strAccount)
{
	QString strAccountInput = ui.editUserAccount->text();
	QString strCodeInput = ui.editPassword->text();

	//输入员工号(QQ号登录)
	QString strSqlCode = QString("SELECT code FROM tab_accounts WHERE employeeID = %1;").arg(strAccountInput);
	QSqlQuery querEmployeeID(strSqlCode);
	querEmployeeID.exec();
	
	if (querEmployeeID.first())//指向结果集第一条
	{
		//数据库中QQ号对应的密码
		QString strCode = querEmployeeID.value(0).toString();
		
		if (strCode == strCodeInput)
		{
			gLoginEmployeeID = strAccountInput;
			isAccountLogin = false;
			strAccount = strAccountInput;
			return true;
		}
		else
		{
			return false;
		}
	}

	//账号登录
	strSqlCode = QString("SELECT code,employeeID FROM tab_accounts WHERE account = '%1';").arg(strAccountInput);

	QSqlQuery queryAccount(strSqlCode);
	queryAccount.exec();
	if (queryAccount.first())
	{
		QString strCode = queryAccount.value(0).toString();

		if (strCode == strCodeInput)
		{
			gLoginEmployeeID = queryAccount.value(1).toString();
			isAccountLogin = true;
			strAccount = strAccountInput;
			return true;
		}
		else
		{
			return false;
		}
	}


	return false;
}

void UserLogin::onLoginBtnClicked()
{
	bool isAccountLogin;
	QString strAccoun;
	if (!veryfyAccountCode(isAccountLogin,strAccoun))
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您输入的账号或密码有误,请重新输入!"));
		//ui.editPassword->setText("");
		//ui.editUserAccount->setText("");
		return;
	}

	//更新登录状态为登录
	QString strSqlStatus = QString("UPDATE tab_employees SET online = 2 WHERE employeeID = %1").arg(gLoginEmployeeID);
	QSqlQuery sqlStatus(strSqlStatus);
	sqlStatus.exec();
	
	
	close();
	CCMainWindow *mainWindow = new CCMainWindow(strAccoun, isAccountLogin);
	mainWindow->show();
}
      