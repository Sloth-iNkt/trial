/********************************************************************************
** Form generated from reading UI file 'howtoplay.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTOPLAY_H
#define UI_HOWTOPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_howtoplay
{
public:
    QLabel *label;
    QPushButton *backBtn;

    void setupUi(QDialog *howtoplay)
    {
        if (howtoplay->objectName().isEmpty())
            howtoplay->setObjectName("howtoplay");
        howtoplay->resize(400, 300);
        label = new QLabel(howtoplay);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 30, 231, 141));
        label->setAlignment(Qt::AlignCenter);
        backBtn = new QPushButton(howtoplay);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(160, 240, 80, 21));

        retranslateUi(howtoplay);

        QMetaObject::connectSlotsByName(howtoplay);
    } // setupUi

    void retranslateUi(QDialog *howtoplay)
    {
        howtoplay->setWindowTitle(QCoreApplication::translate("howtoplay", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("howtoplay", "How to Play", nullptr));
        backBtn->setText(QCoreApplication::translate("howtoplay", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class howtoplay: public Ui_howtoplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTOPLAY_H
