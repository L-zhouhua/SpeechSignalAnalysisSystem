/********************************************************************************
** Form generated from reading UI file 'spectrogram.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTROGRAM_H
#define UI_SPECTROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Spectrogram
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget1;
    QCustomPlot *widget_2;

    void setupUi(QWidget *Spectrogram)
    {
        if (Spectrogram->objectName().isEmpty())
            Spectrogram->setObjectName(QString::fromUtf8("Spectrogram"));
        Spectrogram->resize(975, 633);
        widget = new QWidget(Spectrogram);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 941, 451));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget1 = new QCustomPlot(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));

        verticalLayout->addWidget(widget1);

        widget_2 = new QCustomPlot(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);


        retranslateUi(Spectrogram);

        QMetaObject::connectSlotsByName(Spectrogram);
    } // setupUi

    void retranslateUi(QWidget *Spectrogram)
    {
        Spectrogram->setWindowTitle(QApplication::translate("Spectrogram", "Spectrogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spectrogram: public Ui_Spectrogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTROGRAM_H
