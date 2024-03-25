/********************************************************************************
** Form generated from reading UI file 'wait.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_H
#define UI_WAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_wait
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *wait)
    {
        if (wait->objectName().isEmpty())
            wait->setObjectName(QString::fromUtf8("wait"));
        wait->resize(595, 339);
        textBrowser = new QTextBrowser(wait);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(-10, 0, 611, 341));
        QFont font;
        font.setPointSize(30);
        textBrowser->setFont(font);

        retranslateUi(wait);

        QMetaObject::connectSlotsByName(wait);
    } // setupUi

    void retranslateUi(QDialog *wait)
    {
        wait->setWindowTitle(QApplication::translate("wait", "Dialog", nullptr));
        textBrowser->setHtml(QApplication::translate("wait", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">\346\255\243\345\234\250\350\257\273\345\217\226\346\226\207\344\273\266</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">\350\257\267\347\250\215\345\200\231</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wait: public Ui_wait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_H
