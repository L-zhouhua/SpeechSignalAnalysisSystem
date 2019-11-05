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
    QVBoxLayout *verticalLayout;
    QCustomPlot *spectrogram_widget_1;

    void setupUi(QWidget *Spectrogram)
    {
        if (Spectrogram->objectName().isEmpty())
            Spectrogram->setObjectName(QString::fromUtf8("Spectrogram"));
        Spectrogram->resize(1409, 626);
        verticalLayout = new QVBoxLayout(Spectrogram);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        spectrogram_widget_1 = new QCustomPlot(Spectrogram);
        spectrogram_widget_1->setObjectName(QString::fromUtf8("spectrogram_widget_1"));

        verticalLayout->addWidget(spectrogram_widget_1);


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
