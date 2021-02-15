#pragma once

#include "basicwindow.h"
#include "ui_CCMainWindow.h"

class QTreeWidgetItem;

class CCMainWindow : public BasicWindow
{
	Q_OBJECT

public:
	CCMainWindow(QString account,bool isAccountLogin,QWidget *parent = Q_NULLPTR);
	~CCMainWindow();

public:
	void initContactTree();//��ʼ����ϵ��
	void setUserName(const QString &userName);			//�����û���
	void setLevelPixmap(int level);						//���õȼ�	
	void setHeadPixmap(const QString& headPath);		//����ͷ��
	void setStatusMenuIcon(const QString& statusPath);	//����״̬
	//���Ӧ�ò���(appͼƬ·��,app������)
	QWidget* addOtherAppExtension(const QString& appPath, const QString& appName);

private:
	void initControl();
	void initTimer();	//��ʼ����ʱ��
	QString getHeadPicturePath();
	void updateSeachStyle();//����������ʽ
	void addCompanyDeps(QTreeWidgetItem* pRootGroupItem, int DepID);

private:
	void resizeEvent(QResizeEvent * event);
	bool eventFilter(QObject* obj, QEvent* event);
	void mousePressEvent(QMouseEvent* event);

private slots:
	void onAppIconClicked();
	void onItemClicked(QTreeWidgetItem* item, int colume);
	void onItemExpanded(QTreeWidgetItem* item);
	void onItemCollapsed(QTreeWidgetItem* item);
	void onItemDoubleClicked(QTreeWidgetItem* item, int colime);

private:
	Ui::CCMainWindowClass ui;
	bool m_isAccountLogin;
	QString m_account;		//��¼���˺Ż���QQ��
//	QMap<QTreeWidgetItem*, QString> m_groupMap;//���з���ķ�����
};
