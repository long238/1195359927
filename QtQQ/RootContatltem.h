#pragma once

#include <QLabel>
#include <QPropertyAnimation>

class RootContatltem : public QLabel
{
	Q_OBJECT

	//��ͷ�Ƕ�
	Q_PROPERTY(int rotation READ rotation WRITE setRotation)

public:
	RootContatltem(bool hasArrow = true,QWidget *parent= nullptr);
	~RootContatltem();

public:
	void setText(const QString& title);
	void setExpanded(bool expand);

private:
	int rotation();
	void setRotation(int rotation);

protected:
	void paintEvent(QPaintEvent* event);

private:
	QPropertyAnimation *m_animation;
	QString m_titleText;	//��ʾ�ı�
	int m_rotation;			//��ͷ�ĽǶ�
	bool m_hasArrow;		//�Ƿ��м�ͷ
};
