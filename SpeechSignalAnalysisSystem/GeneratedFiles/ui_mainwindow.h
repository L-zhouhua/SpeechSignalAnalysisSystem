/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *play_act;
    QAction *periodwind_open_act;
    QAction *spectrumwind_open_act;
    QAction *filterwind_open_act;
    QAction *readwav_act;
    QAction *newsinglewav_act;
    QAction *newdoublewav_act;
    QAction *windowopen;
    QAction *spectrogram_act;
    QAction *freqResp_act;
    QWidget *centralWidget;
    QCustomPlot *waveform_wid_1;
    QCustomPlot *waveform_wid_2;
    QPushButton *zoomIn_but;
    QPushButton *zoomOut_but;
    QPushButton *reset_but;
    QScrollBar *horizontalScrollBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *newWindow_menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1349, 793);
        play_act = new QAction(MainWindowClass);
        play_act->setObjectName(QString::fromUtf8("play_act"));
        periodwind_open_act = new QAction(MainWindowClass);
        periodwind_open_act->setObjectName(QString::fromUtf8("periodwind_open_act"));
        spectrumwind_open_act = new QAction(MainWindowClass);
        spectrumwind_open_act->setObjectName(QString::fromUtf8("spectrumwind_open_act"));
        filterwind_open_act = new QAction(MainWindowClass);
        filterwind_open_act->setObjectName(QString::fromUtf8("filterwind_open_act"));
        readwav_act = new QAction(MainWindowClass);
        readwav_act->setObjectName(QString::fromUtf8("readwav_act"));
        newsinglewav_act = new QAction(MainWindowClass);
        newsinglewav_act->setObjectName(QString::fromUtf8("newsinglewav_act"));
        newdoublewav_act = new QAction(MainWindowClass);
        newdoublewav_act->setObjectName(QString::fromUtf8("newdoublewav_act"));
        windowopen = new QAction(MainWindowClass);
        windowopen->setObjectName(QString::fromUtf8("windowopen"));
        spectrogram_act = new QAction(MainWindowClass);
        spectrogram_act->setObjectName(QString::fromUtf8("spectrogram_act"));
        freqResp_act = new QAction(MainWindowClass);
        freqResp_act->setObjectName(QString::fromUtf8("freqResp_act"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        waveform_wid_1 = new QCustomPlot(centralWidget);
        waveform_wid_1->setObjectName(QString::fromUtf8("waveform_wid_1"));
        waveform_wid_1->setGeometry(QRect(20, 10, 1311, 311));
        waveform_wid_2 = new QCustomPlot(centralWidget);
        waveform_wid_2->setObjectName(QString::fromUtf8("waveform_wid_2"));
        waveform_wid_2->setGeometry(QRect(20, 320, 1311, 311));
        zoomIn_but = new QPushButton(centralWidget);
        zoomIn_but->setObjectName(QString::fromUtf8("zoomIn_but"));
        zoomIn_but->setGeometry(QRect(50, 670, 93, 28));
        zoomOut_but = new QPushButton(centralWidget);
        zoomOut_but->setObjectName(QString::fromUtf8("zoomOut_but"));
        zoomOut_but->setGeometry(QRect(210, 670, 93, 28));
        reset_but = new QPushButton(centralWidget);
        reset_but->setObjectName(QString::fromUtf8("reset_but"));
        reset_but->setGeometry(QRect(370, 670, 93, 28));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(830, 670, 481, 31));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1349, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        newWindow_menu = new QMenu(menuBar);
        newWindow_menu->setObjectName(QString::fromUtf8("newWindow_menu"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(newWindow_menu->menuAction());
        menu->addAction(play_act);
        menu->addSeparator();
        menu->addAction(periodwind_open_act);
        menu->addAction(spectrumwind_open_act);
        menu->addAction(filterwind_open_act);
        menu->addAction(spectrogram_act);
        menu->addAction(freqResp_act);
        menu_2->addAction(readwav_act);
        menu_3->addAction(newsinglewav_act);
        menu_3->addAction(newdoublewav_act);
        newWindow_menu->addAction(windowopen);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        play_act->setText(QApplication::translate("MainWindowClass", "\346\222\255\346\224\276", nullptr));
        periodwind_open_act->setText(QApplication::translate("MainWindowClass", "\345\221\250\346\234\237\345\210\206\346\236\220", nullptr));
        spectrumwind_open_act->setText(QApplication::translate("MainWindowClass", "\351\242\221\350\260\261\345\210\206\346\236\220", nullptr));
        filterwind_open_act->setText(QApplication::translate("MainWindowClass", "\346\273\244\346\263\242", nullptr));
        readwav_act->setText(QApplication::translate("MainWindowClass", "\344\273\216\346\226\207\344\273\266\350\257\273\345\217\226\357\274\210.wav\357\274\211", nullptr));
        newsinglewav_act->setText(QApplication::translate("MainWindowClass", "\345\275\225\345\210\266\345\215\225\345\243\260\351\201\223", nullptr));
        newdoublewav_act->setText(QApplication::translate("MainWindowClass", "\345\275\225\345\210\266\345\217\214\345\243\260\351\201\223", nullptr));
        windowopen->setText(QApplication::translate("MainWindowClass", "open", nullptr));
        spectrogram_act->setText(QApplication::translate("MainWindowClass", "\350\257\255\350\260\261\345\233\276", nullptr));
        freqResp_act->setText(QApplication::translate("MainWindowClass", "\351\242\221\347\216\207\345\223\215\345\272\224", nullptr));
        zoomIn_but->setText(QApplication::translate("MainWindowClass", "\346\224\276\345\244\247", nullptr));
        zoomOut_but->setText(QApplication::translate("MainWindowClass", "\347\274\251\345\260\217", nullptr));
        reset_but->setText(QApplication::translate("MainWindowClass", "\351\207\215\347\275\256", nullptr));
        menu->setTitle(QApplication::translate("MainWindowClass", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindowClass", "\346\211\223\345\274\200", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindowClass", "\346\226\260\345\273\272", nullptr));
        newWindow_menu->setTitle(QApplication::translate("MainWindowClass", "\346\226\260\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
