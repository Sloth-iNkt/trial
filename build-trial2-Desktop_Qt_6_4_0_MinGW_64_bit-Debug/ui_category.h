/********************************************************************************
** Form generated from reading UI file 'category.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORY_H
#define UI_CATEGORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_category
{
public:
    QLabel *cat_title;
    QPushButton *alg_btn;
    QPushButton *geo_btn;
    QPushButton *trig_btn;
    QPushButton *cus_btn;
    QPushButton *back_btn;

    void setupUi(QWidget *category)
    {
        if (category->objectName().isEmpty())
            category->setObjectName("category");
        category->resize(400, 300);
        cat_title = new QLabel(category);
        cat_title->setObjectName("cat_title");
        cat_title->setGeometry(QRect(140, 10, 111, 31));
        QFont font;
        font.setPointSize(12);
        cat_title->setFont(font);
        cat_title->setAlignment(Qt::AlignCenter);
        alg_btn = new QPushButton(category);
        alg_btn->setObjectName("alg_btn");
        alg_btn->setGeometry(QRect(150, 80, 93, 29));
        geo_btn = new QPushButton(category);
        geo_btn->setObjectName("geo_btn");
        geo_btn->setGeometry(QRect(150, 120, 93, 29));
        trig_btn = new QPushButton(category);
        trig_btn->setObjectName("trig_btn");
        trig_btn->setGeometry(QRect(150, 160, 101, 29));
        cus_btn = new QPushButton(category);
        cus_btn->setObjectName("cus_btn");
        cus_btn->setGeometry(QRect(150, 200, 101, 29));
        back_btn = new QPushButton(category);
        back_btn->setObjectName("back_btn");
        back_btn->setGeometry(QRect(150, 240, 101, 29));

        retranslateUi(category);

        QMetaObject::connectSlotsByName(category);
    } // setupUi

    void retranslateUi(QWidget *category)
    {
        category->setWindowTitle(QCoreApplication::translate("category", "Category", nullptr));
        cat_title->setText(QCoreApplication::translate("category", "CATEGORY", nullptr));
        alg_btn->setText(QCoreApplication::translate("category", "Algebra", nullptr));
        geo_btn->setText(QCoreApplication::translate("category", "Geometry", nullptr));
        trig_btn->setText(QCoreApplication::translate("category", "Trigonometry", nullptr));
        cus_btn->setText(QCoreApplication::translate("category", "Customized", nullptr));
        back_btn->setText(QCoreApplication::translate("category", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class category: public Ui_category {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORY_H
