#include "set_parameters.h"
#include "ui_set_parameters.h"


#include "choose_patternfile.h"
#include "ui_choose_patternfile.h"


int level;


set_parameters::set_parameters(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::set_parameters)
{
	ui->setupUi(this);
	setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/new/prefix1/project_resource/picture2.jpg").scaled(    // 缩放背景图.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));    // 使用平滑的缩放方式
	this->setPalette(palette);
}

set_parameters::~set_parameters()
{
	delete ui;
}



void set_parameters::on_device_detection_clicked()
{
	QTreeWidget* device_output = ui->device_output;
	device_output->clear(); // 清空 device_output 中的所有记录
	int num = 0;
	pcap_if_t* allDev, * pdev;
	char buf[1024];

	pcap_findalldevs(&allDev, buf);//找到所有的设备

	//依次输出设备
	for (pdev = allDev; pdev; pdev = pdev->next)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem(device_output);
		QFont font("Jamrul", 15);
		item->setFont(0, font); // 将第0列的字体设置为Arial 12号字体
		item->setFont(1, font); // 将第1列的字体设置为Arial 12号字体
		item->setText(0, QString::number(num)); // 设置设备号
		item->setText(1, pdev->name); // 设置设备名称
		device_output->addTopLevelItem(item);
		num++;
	}

	if (num == 0) {
		QMessageBox::information(this, tr("Information"), tr("No available devices found！"));
	}



}


void set_parameters::on_parameters_confirm_clicked()
{
	//设置Device
	QTreeWidget* device_output = ui->device_output;
	QTreeWidgetItem* item1 = device_output->currentItem();
	if (item1 != nullptr) {
		QString device_name = item1->text(1); //从item1的第二列获取文本，并将其存储在QString类型的device_name变量中
		QByteArray tmp = device_name.toLatin1(); //将device_name转换为Latin-1编码的QByteArray类型的tmp变量
		char* p = new char[32];
		bzero(p, 32);
		strncpy(p, tmp.data(), 32); //将tmp.data()中的数据复制到p指向的内存中，最多复制32个字节
		nids_params.device = p; //将所选择的设备名传给nids_params.device

	}
	else {
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setFixedSize(600, 360);
		msgBox.setText(tr("No device selected!")); //未选择设备提醒
		msgBox.setWindowTitle(tr("Information"));
		QFont font0("Arial", 16);
		msgBox.setFont(font0);
		msgBox.exec();
		return;
	}


	//设置Level
	QTreeWidget* choose_level = ui->choose_level;
	QTreeWidgetItem* item2 = choose_level->currentItem();
	if (item2 != nullptr) {
		QString level_name = item2->text(0);
		if (level_name == "Level1") {
			level = 1;
		}
		else if (level_name == "Level2") {
			level = 2;
		}
		else if (level_name == "Level3") {
			level = 3;
		}
		else printf("fail");

	}
	else {
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setFixedSize(600, 360);
		msgBox.setText(tr("No security level set!")); //未选择level提醒
		msgBox.setWindowTitle(tr("Information"));
		QFont font0("Arial", 16);
		msgBox.setFont(font0);
		msgBox.exec();
		return;
	}

	choose_patternfile* newwidget = new choose_patternfile;
	newwidget->show();

	this->close();
}

