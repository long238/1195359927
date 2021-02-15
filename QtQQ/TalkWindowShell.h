#pragma once

#include "BasicWindow.h"
#include "ui_TalkWindowShell.h"
#include <QMap>
#include <QTcpSocket>
#include <QUdpSocket>

class TalkWindow;
class TalkWindowItem;
class QListWidgetItem;
class EmotionWindow;

const int gtcpPort = 8888;

enum GroupType {
	COMPANY = 0,	//��˾Ⱥ
	PERSONELGROUP,	//���²�
	DEVELOPMENTGROUP,//�з���
	MARKETGROUP,	//�г���
	PTOP			//ͬ��֮�䵥������
};

class TalkWindowShell : public BasicWindow
{
	Q_OBJECT

public:
	TalkWindowShell(QWidget *parent = Q_NULLPTR);
	~TalkWindowShell();

public:
	//����µ�����
	void addTalkWindow(TalkWindow* talkWindow, TalkWindowItem* talkWindowItem ,const QString & uid /*,GroupType grouptype*/);
	//���õ�ǰ���촰��
	void setCurrentWidget(QWidget* widget);

	const QMap<QListWidgetItem*, QWidget*>& getTalkWindowItemMap() const;

private:
	void initControl();	//��ʼ���ؼ�
	void initTcpSocket();	//��ʼ��TCP
	void initUdpSocket();	//��ʼ��UDP
	void getEmployeesID(QStringList& employeesList);	//��ȡ����Ա��QQ��
	bool createJSFile(QStringList &employeesList);
	void handleReceivedMsg(int senderEmployeeID, int msgType, QString strMsg);

public slots:
	void onEmotionBtnClicked(bool);//���鰴ť�����ִ�еĲۺ���

	//�ͻ��˷���tcp���ݣ����ݣ��������ͣ��ļ���
	void updateSendTcpMsg(QString &strData, int &msgType, QString fileName = "");

private slots:
	void onTalkWindowItemClicked(QListWidgetItem* item);//����б�����ִ�еĲۺ���
	void onEmotionItemClicked(int emotionNum);//���鱻ѡ��
	void processPendingData();//����UDP�㲥�յ�������

private:
	Ui::TalkWindowClass ui;
	QMap<QListWidgetItem*, QWidget*> m_talkwindowItemMap;//�򿪵����촰��
	EmotionWindow* m_emotionWindow;//���鴰��

private:
	QTcpSocket *m_tcpClientSocket;	//TCP�ͻ���
	QUdpSocket *m_udpReceiver;		//udp���ն�

};
