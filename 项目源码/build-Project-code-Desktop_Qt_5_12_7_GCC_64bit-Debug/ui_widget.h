/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *actionbutton;
    QPushButton *exitbutton;
    QFrame *frame;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 1200);
        Widget->setMinimumSize(QSize(800, 1200));
        Widget->setMaximumSize(QSize(800, 1200));
        Widget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 280, 681, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Mono CJK SC"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 690, 261, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        actionbutton = new QPushButton(layoutWidget);
        actionbutton->setObjectName(QString::fromUtf8("actionbutton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sawasdee"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        actionbutton->setFont(font1);
        actionbutton->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}\n"
"\n"
""));
        actionbutton->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(actionbutton);

        exitbutton = new QPushButton(layoutWidget);
        exitbutton->setObjectName(QString::fromUtf8("exitbutton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sawasdee"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        font2.setKerning(true);
        exitbutton->setFont(font2);
        exitbutton->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}\n"
""));

        verticalLayout->addWidget(exitbutton);

        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 710, 341, 221));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(254, 253, 253, 70);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        layoutWidget->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\347\211\271\345\276\201\344\270\262\346\224\273\345\207\273\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600; font-style:italic; color:#ffffff;\">Welcome to use </span></p><p align=\"center\"><span style=\" font-size:26pt; font-weight:600; font-style:italic; color:#ffffff;\">Feature string Attack Detection System</span></p></body></html>", nullptr));
        actionbutton->setText(QApplication::translate("Widget", "ACTION", nullptr));
        exitbutton->setText(QApplication::translate("Widget", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
