#include "widget.h"
#include "ui_widget.h"

#include "set_parameters.h"
#include "ui_set_parameters.h"


Attackpattern::Attackpattern() :next(NULL) {
	bzero(attackdes, 256);
	bzero(attackdes, 256);
}


Node::Node() :category(0), next(NULL) {
	bzero(attackcontent, 256);
}


ACNode::ACNode() :isEnd(0), fail(NULL) {
	for (int i = 0; i < 256; i++)
		children[i] = NULL;
}


Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/new/prefix1/project_resource/picture1.jpg").scaled(    // 缩放背景图.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));    // 使用平滑的缩放方式
	this->setPalette(palette);

}


Widget::~Widget()
{
	delete ui;
}



void Widget::on_actionbutton_clicked()
{
	set_parameters* newwidget = new set_parameters;
	newwidget->show(); //打开新的页面
	this->close(); //关闭此页面
}


void Widget::on_exitbutton_clicked()
{
	this->close();

}



