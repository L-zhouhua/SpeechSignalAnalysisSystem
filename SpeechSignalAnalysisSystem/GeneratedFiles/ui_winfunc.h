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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_winFunc
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *rect_but;
    QPushButton *han_but;
    QPushButton *ham_but;
    QPushButton *kai_but;
    QPushButton *bmh_but;
    QPushButton *bm_but;
    QCustomPlot *winFunc_wid;

    void setupUi(QWidget *winFunc)
    {
        if (winFunc->objectName().isEmpty())
            winFunc->setObjectName(QString::fromUtf8("winFunc"));
        winFunc->resize(821, 466);
        horizontalLayout = new QHBoxLayout(winFunc);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(winFunc);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(160, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rect_but = new QPushButton(groupBox);
        rect_but->setObjectName(QString::fromUtf8("rect_but"));

        verticalLayout->addWidget(rect_but);

        han_but = new QPushButton(groupBox);
        han_but->setObjectName(QString::fromUtf8("han_but"));

        verticalLayout->addWidget(han_but);

        ham_but = new QPushButton(groupBox);
        ham_but->setObjectName(QString::fromUtf8("ham_but"));

        verticalLayout->addWidget(ham_but);

        kai_but = new QPushButton(groupBox);
        kai_but->setObjectName(QString::fromUtf8("kai_but"));

        verticalLayout->addWidget(kai_but);

        bmh_but = new QPushButton(groupBox);
        bmh_but->setObjectName(QString::fromUtf8("bmh_but"));

        verticalLayout->addWidget(bmh_but);

        bm_but = new QPushButton(groupBox);
        bm_but->setObjectName(QString::fromUtf8("bm_but"));

        verticalLayout->addWidget(bm_but);


        horizontalLayout->addWidget(groupBox);

        winFunc_wid = new QCustomPlot(winFunc);
        winFunc_wid->setObjectName(QString::fromUtf8("winFunc_wid"));

        horizontalLayout->addWidget(winFunc_wid);


        retranslateUi(winFunc);

        QMetaObject::connectSlotsByName(winFunc);
    } // setupUi

    void retranslateUi(QWidget *winFunc)
    {
        winFunc->setWindowTitle(QApplication::translate("winFunc", "winFunc", nullptr));
        groupBox->setTitle(QApplication::translate("winFunc", "\347\252\227\345\217\243\345\207\275\346\225\260", nullptr));
        rect_but->setText(QApplication::translate("winFunc", "\347\237\251\345\275\242\347\252\227", nullptr));
        han_but->setText(QApplication::translate("winFunc", "hanning\347\252\227", nullptr));
        ham_but->setText(QApplication::translate("winFunc", "hamming\347\252\227", nullptr));
        kai_but->setText(QApplication::translate("winFunc", "Kaiser\347\252\227", nullptr));
        bmh_but->setText(QApplication::translate("winFunc", "BlackmanHarris\347\252\227", nullptr));
        bm_but->setText(QApplication::translate("winFunc", "Blackman\347\252\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winFunc: public Ui_winFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINFUNC_H
