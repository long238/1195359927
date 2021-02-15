//#include "CCMainWindow.h"
#include <QtWidgets/QApplication>
#include "UserLogin.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*CCMainWindow w;
	w.show();*/

	//当最后一个窗口关闭时，应用程序是否隐式退出
	//默认是true,
	a.setQuitOnLastWindowClosed(false);

	UserLogin *userLogin = new UserLogin();
	userLogin->show();
	return a.exec();
}
