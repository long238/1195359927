#pragma once

#include <QLabel>
#include <QPropertyAnimation>

class RootContatltem : public QLabel
{
	Q_OBJECT

	//箭头角度
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
	QString m_titleText;	//显示文本
	int m_rotation;			//箭头的角度
	bool m_hasArrow;		//是否有箭头
};
