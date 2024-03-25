#include "wait.h"
#include "ui_wait.h"

wait::wait(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::wait)
{
	ui->setupUi(this);
}

wait::~wait()
{
	delete ui;
}
