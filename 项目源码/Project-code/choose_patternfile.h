#ifndef CHOOSE_PATTERNFILE_H
#define CHOOSE_PATTERNFILE_H

#include "widget.h"

char* find_attackcontent(Node* const head, int category); //��show_detection.cpp�л��õ������ڴ�������

namespace Ui {
	class choose_patternfile;
}

class choose_patternfile : public QWidget
{
	Q_OBJECT

public:
	explicit choose_patternfile(QWidget* parent = nullptr);
	~choose_patternfile();

private slots:


	void on_cancelbutton_clicked();

	void on_confirmbutton_clicked();


private:
	Ui::choose_patternfile* ui;
};

#endif // CHOOSE_PATTERNFILE_H
