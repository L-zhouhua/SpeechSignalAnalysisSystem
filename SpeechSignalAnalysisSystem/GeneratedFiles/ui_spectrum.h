/********************************************************************************
** Form generated from reading UI file 'spectrum.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTRUM_H
#define UI_SPECTRUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Spectrum
{
public:
    QAction *action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *specturm_wdo;
    QPushButton *zoomIn_but;
    QPushButton *zoomOut_but;
    QPushButton *reset_but;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Spectrum)
    {
        if (Spectrum->objectName().isEmpty())
            Spectrum->setObjectName(QString::fromUtf8("Spectrum"));
        Spectrum->resize(1032, 692);
        action = new QAction(Spectrum);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(Spectrum);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        specturm_wdo = new QCustomPlot(centralwidget);
        specturm_wdo->setObjectName(QString::fromUtf8("specturm_wdo"));

        gridLayout->addWidget(specturm_wdo, 0, 0, 1, 3);

        zoomIn_but = new QPushButton(centralwidget);
        zoomIn_but->setObjectName(QString::fromUtf8("zoomIn_but"));

        gridLayout->addWidget(zoomIn_but, 1, 0, 1, 1);

        zoomOut_but = new QPushButton(centralwidget);
        zoomOut_but->setObjectName(QString::fromUtf8("zoomOut_but"));

        gridLayout->addWidget(zoomOut_but, 1, 1, 1, 1);

        reset_but = new QPushButton(centralwidget);
        reset_but->setObjectName(QString::fromUtf8("reset_but"));

        gridLayout->addWidget(reset_but, 1, 2, 1, 1);

        Spectrum->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Spectrum);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Spectrum->setStatusBar(statusbar);

        retranslateUi(Spectrum);

        QMetaObject::connectSlotsByName(Spectrum);
    } // setupUi

    void retranslateUi(QMainWindow *Spectrum)
    {
        Spectrum->setWindowTitle(QCoreApplication::translate("Spectrum", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("Spectrum", "\347\252\227\345\217\243\344\277\241\346\201\257", nullptr));
        zoomIn_but->setText(QCoreApplication::translate("Spectrum", "\346\224\276\345\244\247", nullptr));
        zoomOut_but->setText(QCoreApplication::translate("Spectrum", "\347\274\251\345\260\217", nullptr));
        reset_but->setText(QCoreApplication::translate("Spectrum", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spectrum: public Ui_Spectrum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTRUM_H
