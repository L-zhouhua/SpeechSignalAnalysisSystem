/********************************************************************************
** Form generated from reading UI file 'winfunc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINFUNC_H
#define UI_WINFUNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_winFunc
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *kai_but;
    QLabel *kai_lab;
    QLineEdit *kai_edit;
    QComboBox *winfunc_Box;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *winFunc_wid;
    QCustomPlot *winFunc_wid_2;

    void setupUi(QWidget *winFunc)
    {
        if (winFunc->objectName().isEmpty())
            winFunc->setObjectName(QString::fromUtf8("winFunc"));
        winFunc->resize(827, 453);
        horizontalLayout = new QHBoxLayout(winFunc);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(winFunc);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 11, -1, 11);
        kai_but = new QPushButton(groupBox);
        kai_but->setObjectName(QString::fromUtf8("kai_but"));
        kai_but->setEnabled(false);

        gridLayout->addWidget(kai_but, 4, 0, 1, 1);

        kai_lab = new QLabel(groupBox);
        kai_lab->setObjectName(QString::fromUtf8("kai_lab"));
        kai_lab->setEnabled(false);

        gridLayout->addWidget(kai_lab, 2, 0, 1, 1);

        kai_edit = new QLineEdit(groupBox);
        kai_edit->setObjectName(QString::fromUtf8("kai_edit"));
        kai_edit->setEnabled(false);

        gridLayout->addWidget(kai_edit, 3, 0, 1, 1);

        winfunc_Box = new QComboBox(groupBox);
        winfunc_Box->addItem(QString());
        winfunc_Box->addItem(QString());
        winfunc_Box->addItem(QString());
        winfunc_Box->addItem(QString());
        winfunc_Box->addItem(QString());
        winfunc_Box->addItem(QString());
        winfunc_Box->addItem(QString());
        winfunc_Box->setObjectName(QString::fromUtf8("winfunc_Box"));

        gridLayout->addWidget(winfunc_Box, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        widget = new QWidget(winFunc);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        winFunc_wid = new QCustomPlot(widget);
        winFunc_wid->setObjectName(QString::fromUtf8("winFunc_wid"));

        verticalLayout->addWidget(winFunc_wid);

        winFunc_wid_2 = new QCustomPlot(widget);
        winFunc_wid_2->setObjectName(QString::fromUtf8("winFunc_wid_2"));

        verticalLayout->addWidget(winFunc_wid_2);


        horizontalLayout->addWidget(widget);


        retranslateUi(winFunc);

        QMetaObject::connectSlotsByName(winFunc);
    } // setupUi

    void retranslateUi(QWidget *winFunc)
    {
        winFunc->setWindowTitle(QApplication::translate("winFunc", "winFunc", nullptr));
        groupBox->setTitle(QApplication::translate("winFunc", "\347\252\227\345\217\243\345\207\275\346\225\260\347\261\273\345\236\213", nullptr));
        kai_but->setText(QApplication::translate("winFunc", "\347\241\256\345\256\232", nullptr));
        kai_lab->setText(QApplication::translate("winFunc", "Kaiser\345\217\202\346\225\260\357\274\232", nullptr));
        winfunc_Box->setItemText(0, QApplication::translate("winFunc", "\350\257\267\351\200\211\346\213\251\347\252\227\345\217\243\347\261\273\345\236\213", nullptr));
        winfunc_Box->setItemText(1, QApplication::translate("winFunc", "\347\237\251\345\275\242\347\252\227", nullptr));
        winfunc_Box->setItemText(2, QApplication::translate("winFunc", "hanning\347\252\227", nullptr));
        winfunc_Box->setItemText(3, QApplication::translate("winFunc", "hamming\347\252\227", nullptr));
        winfunc_Box->setItemText(4, QApplication::translate("winFunc", "Blackman\347\252\227", nullptr));
        winfunc_Box->setItemText(5, QApplication::translate("winFunc", "BlackmanHarris\347\252\227", nullptr));
        winfunc_Box->setItemText(6, QApplication::translate("winFunc", "Kaiser\347\252\227", nullptr));

    } // retranslateUi

};

namespace Ui {
    class winFunc: public Ui_winFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINFUNC_H
