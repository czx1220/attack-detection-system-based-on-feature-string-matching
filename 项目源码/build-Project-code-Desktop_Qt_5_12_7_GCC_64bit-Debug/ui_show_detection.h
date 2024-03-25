/********************************************************************************
** Form generated from reading UI file 'show_detection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_DETECTION_H
#define UI_SHOW_DETECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_show_detection
{
public:
    QTreeWidget *detection_output;
    QPushButton *start_detection;

    void setupUi(QWidget *show_detection)
    {
        if (show_detection->objectName().isEmpty())
            show_detection->setObjectName(QString::fromUtf8("show_detection"));
        show_detection->resize(800, 1200);
        show_detection->setMinimumSize(QSize(800, 1200));
        show_detection->setMaximumSize(QSize(800, 1200));
        detection_output = new QTreeWidget(show_detection);
        QFont font;
        font.setPointSize(15);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(2, font);
        __qtreewidgetitem->setFont(1, font);
        __qtreewidgetitem->setFont(0, font);
        detection_output->setHeaderItem(__qtreewidgetitem);
        detection_output->setObjectName(QString::fromUtf8("detection_output"));
        detection_output->setGeometry(QRect(80, 220, 621, 671));
        start_detection = new QPushButton(show_detection);
        start_detection->setObjectName(QString::fromUtf8("start_detection"));
        start_detection->setGeometry(QRect(250, 70, 261, 71));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        start_detection->setFont(font1);
        start_detection->setStyleSheet(QString::fromUtf8("QPushButton:hover {background-color: rgb(168, 152, 175);}"));

        retranslateUi(show_detection);

        QMetaObject::connectSlotsByName(show_detection);
    } // setupUi

    void retranslateUi(QWidget *show_detection)
    {
        show_detection->setWindowTitle(QApplication::translate("show_detection", "\347\211\271\345\276\201\344\270\262\346\224\273\345\207\273\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = detection_output->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("show_detection", "Target IP", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("show_detection", "Attacker", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("show_detection", "Attack type", nullptr));
        start_detection->setText(QApplication::translate("show_detection", "Start detection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show_detection: public Ui_show_detection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_DETECTION_H
