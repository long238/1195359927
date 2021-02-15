#pragma once

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
	Q_OBJECT

public:
	TcpSocket();
	~TcpSocket();
	void run();

signals:
	void signalGetDataFromClient(QByteArray&, int);//�ӿͻ����յ����ݺ����źŸ���server������Ҫ����
	void signalCilentDisconnect(int);//����server�пͻ��˶˿�����

private slots:
	void onReceiveData();		//����readyRead�źŶ�ȡ������
	void onClientDisconnect();	//����ͻ��˶Ͽ�����



private:
	int m_descriptor;//������������Ψһ��־

};
