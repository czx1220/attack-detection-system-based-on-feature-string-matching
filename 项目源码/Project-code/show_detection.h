#ifndef SHOW_DETECTION_H
#define SHOW_DETECTION_H

#include "widget.h"


namespace Ui {
	class show_detection;
}

class workThread : public QThread
{
public:
	void run();
};


class show_detection : public QWidget
{
	Q_OBJECT

public:
	explicit show_detection(QWidget* parent = nullptr);
	void closeEvent(QCloseEvent* event);
	~show_detection();

	friend void output_alert_1(int category, const struct tcp_stream* const tcp_connection, int direction);
	friend void output_alert_2_3(const Attackpattern* const pOnepattern, const struct tcp_stream* const tcp_connection, int direction);


private slots:

	void on_start_detection_clicked();

private:
	Ui::show_detection* ui;
	bool flag;
	workThread* thread;

};



#endif // SHOW_DETECTION_H
