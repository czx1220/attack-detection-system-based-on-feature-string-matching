#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QMessageBox>
#include <QTextEdit>
#include <QLabel>
#include <QApplication>
#include <QDebug>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include <nids.h>
#include <qthread.h>



class Attackpattern {
public:
	char attackdes[256]; // 攻击类别
	char patterncontent[256]; // 特征串内容
	//int patternlen; // 攻击类别长度
	Attackpattern* next;
public:
	Attackpattern();
};


class Node {
public:
	int category; // 设定攻击编号
	char attackcontent[256];
	Node* next;
public:
	Node();
};



class ACNode {
public:
	ACNode* children[256]; // 用于存储的子节点
	int isEnd; // 用于标记是否是模式串的结尾,如果结尾的话是那种类型
	ACNode* fail; // 用于存储失配指针
public:
	ACNode();
};


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent = nullptr);
	~Widget();

private slots:

	void on_actionbutton_clicked();

	void on_exitbutton_clicked();

private:
	Ui::Widget* ui;

};


#endif // WIDGET_H
