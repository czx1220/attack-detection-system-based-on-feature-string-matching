/********************************************************************************
** Form generated from reading UI file 'set_parameters.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_PARAMETERS_H
#define UI_SET_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set_parameters
{
public:
    QPushButton *device_detection;
    QTreeWidget *device_output;
    QTreeWidget *choose_level;
    QLabel *label;
    QPushButton *parameters_confirm;
    QFrame *frame;

    void setupUi(QWidget *set_parameters)
    {
        if (set_parameters->objectName().isEmpty())
            set_parameters->setObjectName(QString::fromUtf8("set_parameters"));
        set_parameters->resize(800, 1200);
        set_parameters->setMinimumSize(QSize(800, 1200));
        set_parameters->setMaximumSize(QSize(800, 1200));
        device_detection = new QPushButton(set_parameters);
        device_detection->setObjectName(QString::fromUtf8("device_detection"));
        device_detection->setGeometry(QRect(160, 150, 200, 70));
        device_detection->setMinimumSize(QSize(200, 70));
        device_detection->setMaximumSize(QSize(200, 70));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Serif CJK JP"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        device_detection->setFont(font);
        device_detection->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}"));
        device_output = new QTreeWidget(set_parameters);
        QFont font1;
        font1.setPointSize(15);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(1, font1);
        __qtreewidgetitem->setFont(0, font1);
        device_output->setHeaderItem(__qtreewidgetitem);
        device_output->setObjectName(QString::fromUtf8("device_output"));
        device_output->setGeometry(QRect(60, 250, 411, 501));
        device_output->setColumnCount(2);
        choose_level = new QTreeWidget(set_parameters);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setFont(0, font1);
        choose_level->setHeaderItem(__qtreewidgetitem1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Jamrul"));
        font2.setPointSize(15);
        font2.setItalic(false);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(choose_level);
        __qtreewidgetitem2->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(choose_level);
        __qtreewidgetitem3->setFont(0, font2);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(choose_level);
        __qtreewidgetitem4->setFont(0, font2);
        choose_level->setObjectName(QString::fromUtf8("choose_level"));
        choose_level->setGeometry(QRect(540, 250, 201, 181));
        label = new QLabel(set_parameters);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 761, 51));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label->setFont(font3);
        parameters_confirm = new QPushButton(set_parameters);
        parameters_confirm->setObjectName(QString::fromUtf8("parameters_confirm"));
        parameters_confirm->setGeometry(QRect(290, 810, 171, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Light"));
        font4.setPointSize(30);
        font4.setBold(false);
        font4.setItalic(true);
        font4.setWeight(50);
        parameters_confirm->setFont(font4);
        parameters_confirm->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}"));
        frame = new QFrame(set_parameters);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 230, 741, 541));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(254, 253, 253, 70);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        device_detection->raise();
        device_output->raise();
        choose_level->raise();
        label->raise();
        parameters_confirm->raise();

        retranslateUi(set_parameters);

        QMetaObject::connectSlotsByName(set_parameters);
    } // setupUi

    void retranslateUi(QWidget *set_parameters)
    {
        set_parameters->setWindowTitle(QApplication::translate("set_parameters", "\347\211\271\345\276\201\344\270\262\346\224\273\345\207\273\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        device_detection->setText(QApplication::translate("set_parameters", "Device detection", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = device_output->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("set_parameters", "Device name", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("set_parameters", "Device ID", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = choose_level->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("set_parameters", "Set security level", nullptr));

        const bool __sortingEnabled = choose_level->isSortingEnabled();
        choose_level->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = choose_level->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("set_parameters", "Level1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = choose_level->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("set_parameters", "Level2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = choose_level->topLevelItem(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("set_parameters", "Level3", nullptr));
        choose_level->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("set_parameters", "<html><head/><body><p><span style=\" font-style:italic; color:#ffffff;\">Please select a device, set the security level, and click OK to confirm</span></p></body></html>", nullptr));
        parameters_confirm->setText(QApplication::translate("set_parameters", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class set_parameters: public Ui_set_parameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_PARAMETERS_H
