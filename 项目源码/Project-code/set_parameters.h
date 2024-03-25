#ifndef SET_PARAMETERS_H
#define SET_PARAMETERS_H

#include "widget.h"


namespace Ui {
	class set_parameters;
}


class set_parameters : public QWidget
{
	Q_OBJECT

public:
	explicit set_parameters(QWidget* parent = nullptr);
	~set_parameters();

private slots:

	void on_device_detection_clicked();

	void on_parameters_confirm_clicked();

private:
	Ui::set_parameters* ui;


};


#endif // SET_PARAMETERS_H
