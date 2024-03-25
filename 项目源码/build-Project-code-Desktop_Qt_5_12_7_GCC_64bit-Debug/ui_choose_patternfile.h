/********************************************************************************
** Form generated from reading UI file 'choose_patternfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_PATTERNFILE_H
#define UI_CHOOSE_PATTERNFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choose_patternfile
{
public:
    QLineEdit *patternfilelineEdit;
    QLabel *label;
    QPushButton *confirmbutton;
    QPushButton *cancelbutton;

    void setupUi(QWidget *choose_patternfile)
    {
        if (choose_patternfile->objectName().isEmpty())
            choose_patternfile->setObjectName(QString::fromUtf8("choose_patternfile"));
        choose_patternfile->resize(800, 1200);
        choose_patternfile->setMinimumSize(QSize(800, 1200));
        choose_patternfile->setMaximumSize(QSize(800, 1200));
        QFont font;
        font.setItalic(true);
        choose_patternfile->setFont(font);
        patternfilelineEdit = new QLineEdit(choose_patternfile);
        patternfilelineEdit->setObjectName(QString::fromUtf8("patternfilelineEdit"));
        patternfilelineEdit->setGeometry(QRect(240, 450, 279, 60));
        patternfilelineEdit->setMinimumSize(QSize(279, 60));
        patternfilelineEdit->setMaximumSize(QSize(270, 60));
        QFont font1;
        font1.setPointSize(30);
        font1.setItalic(true);
        patternfilelineEdit->setFont(font1);
        patternfilelineEdit->setCursor(QCursor(Qt::IBeamCursor));
        label = new QLabel(choose_patternfile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, 200, 811, 201));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lohit Assamese"));
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label->setFont(font2);
        confirmbutton = new QPushButton(choose_patternfile);
        confirmbutton->setObjectName(QString::fromUtf8("confirmbutton"));
        confirmbutton->setGeometry(QRect(150, 620, 180, 60));
        confirmbutton->setMinimumSize(QSize(180, 60));
        confirmbutton->setMaximumSize(QSize(180, 60));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        confirmbutton->setFont(font3);
        confirmbutton->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}"));
        cancelbutton = new QPushButton(choose_patternfile);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setGeometry(QRect(440, 620, 180, 60));
        cancelbutton->setMinimumSize(QSize(180, 60));
        cancelbutton->setMaximumSize(QSize(180, 60));
        cancelbutton->setFont(font3);
        cancelbutton->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}"));

        retranslateUi(choose_patternfile);

        QMetaObject::connectSlotsByName(choose_patternfile);
    } // setupUi

    void retranslateUi(QWidget *choose_patternfile)
    {
        choose_patternfile->setWindowTitle(QApplication::translate("choose_patternfile", "\347\211\271\345\276\201\344\270\262\346\224\273\345\207\273\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        patternfilelineEdit->setText(QString());
        label->setText(QApplication::translate("choose_patternfile", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">Please enter the name of </span></p><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">the feature string file you have selected</span></p></body></html>", nullptr));
        confirmbutton->setText(QApplication::translate("choose_patternfile", "CONFIRM", nullptr));
        cancelbutton->setText(QApplication::translate("choose_patternfile", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choose_patternfile: public Ui_choose_patternfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_PATTERNFILE_H
