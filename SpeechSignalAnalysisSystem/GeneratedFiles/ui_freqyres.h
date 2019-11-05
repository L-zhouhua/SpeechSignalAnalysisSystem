/********************************************************************************
** Form generated from reading UI file 'freqyres.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQYRES_H
#define UI_FREQYRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FreqyRes
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLineEdit *parameter_edit;
    QLineEdit *order_edit;
    QLabel *parameter_lab;
    QLabel *type_lab;
    QLineEdit *type_edit;
    QLabel *order_lab;
    QPushButton *affirm_but;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;

    void setupUi(QWidget *FreqyRes)
    {
        if (FreqyRes->objectName().isEmpty())
            FreqyRes->setObjectName(QString::fromUtf8("FreqyRes"));
        FreqyRes->resize(1339, 476);
        gridLayout_2 = new QGridLayout(FreqyRes);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(FreqyRes);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);


        gridLayout_2->addWidget(groupBox, 0, 1, 2, 1);

        groupBox_3 = new QGroupBox(FreqyRes);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(200, 16777215));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        parameter_edit = new QLineEdit(groupBox_3);
        parameter_edit->setObjectName(QString::fromUtf8("parameter_edit"));

        gridLayout->addWidget(parameter_edit, 2, 1, 1, 1);

        order_edit = new QLineEdit(groupBox_3);
        order_edit->setObjectName(QString::fromUtf8("order_edit"));

        gridLayout->addWidget(order_edit, 1, 1, 1, 1);

        parameter_lab = new QLabel(groupBox_3);
        parameter_lab->setObjectName(QString::fromUtf8("parameter_lab"));

        gridLayout->addWidget(parameter_lab, 2, 0, 1, 1);

        type_lab = new QLabel(groupBox_3);
        type_lab->setObjectName(QString::fromUtf8("type_lab"));

        gridLayout->addWidget(type_lab, 0, 0, 1, 1);

        type_edit = new QLineEdit(groupBox_3);
        type_edit->setObjectName(QString::fromUtf8("type_edit"));

        gridLayout->addWidget(type_edit, 0, 1, 1, 1);

        order_lab = new QLabel(groupBox_3);
        order_lab->setObjectName(QString::fromUtf8("order_lab"));

        gridLayout->addWidget(order_lab, 1, 0, 1, 1);

        affirm_but = new QPushButton(groupBox_3);
        affirm_but->setObjectName(QString::fromUtf8("affirm_but"));
        affirm_but->setMaximumSize(QSize(16777215, 16777215));
        affirm_but->setIconSize(QSize(20, 20));

        gridLayout->addWidget(affirm_but, 3, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 0, 2, 1);

        groupBox_4 = new QGroupBox(FreqyRes);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(200, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 4, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 0, 2, 2, 1);


        retranslateUi(FreqyRes);

        QMetaObject::connectSlotsByName(FreqyRes);
    } // setupUi

    void retranslateUi(QWidget *FreqyRes)
    {
        FreqyRes->setWindowTitle(QApplication::translate("FreqyRes", "FreqyRes", nullptr));
        groupBox->setTitle(QApplication::translate("FreqyRes", "IIR\345\223\215\345\272\224\351\242\221\347\216\207", nullptr));
        groupBox_3->setTitle(QApplication::translate("FreqyRes", "\350\276\223\345\205\245\344\277\241\346\201\257", nullptr));
        parameter_lab->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        type_lab->setText(QApplication::translate("FreqyRes", "\347\261\273\345\236\213\357\274\232", nullptr));
        order_lab->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        affirm_but->setText(QApplication::translate("FreqyRes", "\347\241\256\350\256\244", nullptr));
        groupBox_4->setTitle(QApplication::translate("FreqyRes", "\347\252\227\345\217\243\344\277\241\346\201\257", nullptr));
        label_4->setText(QApplication::translate("FreqyRes", "\347\261\273\345\236\213\357\274\232", nullptr));
        label->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        label_2->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("FreqyRes", "a\357\274\232", nullptr));
        label_9->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_8->setText(QApplication::translate("FreqyRes", "b\357\274\232", nullptr));
        label_10->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FreqyRes: public Ui_FreqyRes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQYRES_H
