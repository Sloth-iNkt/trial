/********************************************************************************
** Form generated from reading UI file 'review.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEW_H
#define UI_REVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_review
{
public:
    QPushButton *backBtn;

    void setupUi(QDialog *review)
    {
        if (review->objectName().isEmpty())
            review->setObjectName("review");
        review->resize(400, 300);
        backBtn = new QPushButton(review);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(160, 250, 80, 21));

        retranslateUi(review);

        QMetaObject::connectSlotsByName(review);
    } // setupUi

    void retranslateUi(QDialog *review)
    {
        review->setWindowTitle(QCoreApplication::translate("review", "Dialog", nullptr));
        backBtn->setText(QCoreApplication::translate("review", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class review: public Ui_review {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEW_H
