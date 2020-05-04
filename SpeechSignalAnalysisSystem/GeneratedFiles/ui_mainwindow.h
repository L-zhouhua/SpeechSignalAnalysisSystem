/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
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
    QAction *winFunc_act;
    QAction *actionp;
    QAction *actionp_2;
    QAction *helpAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCustomPlot *waveform_wid_1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *zoomIn_but;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *zoomOut_but;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *reset_but;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *newWindow_menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1279, 738);
        MainWindowClass->setMouseTracking(false);
        MainWindowClass->setToolButtonStyle(Qt::ToolButtonIconOnly);
        play_act = new QAction(MainWindowClass);
        play_act->setObjectName(QString::fromUtf8("play_act"));
        QFont font;
        font.setPointSize(10);
        play_act->setFont(font);
        periodwind_open_act = new QAction(MainWindowClass);
        periodwind_open_act->setObjectName(QString::fromUtf8("periodwind_open_act"));
        spectrumwind_open_act = new QAction(MainWindowClass);
        spectrumwind_open_act->setObjectName(QString::fromUtf8("spectrumwind_open_act"));
        spectrumwind_open_act->setFont(font);
        filterwind_open_act = new QAction(MainWindowClass);
        filterwind_open_act->setObjectName(QString::fromUtf8("filterwind_open_act"));
        readwav_act = new QAction(MainWindowClass);
        readwav_act->setObjectName(QString::fromUtf8("readwav_act"));
        readwav_act->setFont(font);
        newsinglewav_act = new QAction(MainWindowClass);
        newsinglewav_act->setObjectName(QString::fromUtf8("newsinglewav_act"));
        newsinglewav_act->setFont(font);
        newdoublewav_act = new QAction(MainWindowClass);
        newdoublewav_act->setObjectName(QString::fromUtf8("newdoublewav_act"));
        newdoublewav_act->setFont(font);
        windowopen = new QAction(MainWindowClass);
        windowopen->setObjectName(QString::fromUtf8("windowopen"));
        spectrogram_act = new QAction(MainWindowClass);
        spectrogram_act->setObjectName(QString::fromUtf8("spectrogram_act"));
        freqResp_act = new QAction(MainWindowClass);
        freqResp_act->setObjectName(QString::fromUtf8("freqResp_act"));
        freqResp_act->setFont(font);
        winFunc_act = new QAction(MainWindowClass);
        winFunc_act->setObjectName(QString::fromUtf8("winFunc_act"));
        winFunc_act->setFont(font);
        actionp = new QAction(MainWindowClass);
        actionp->setObjectName(QString::fromUtf8("actionp"));
        actionp_2 = new QAction(MainWindowClass);
        actionp_2->setObjectName(QString::fromUtf8("actionp_2"));
        helpAction = new QAction(MainWindowClass);
        helpAction->setObjectName(QString::fromUtf8("helpAction"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, -1);
        waveform_wid_1 = new QCustomPlot(centralWidget);
        waveform_wid_1->setObjectName(QString::fromUtf8("waveform_wid_1"));
        waveform_wid_1->setMouseTracking(false);

        gridLayout->addWidget(waveform_wid_1, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        zoomIn_but = new QPushButton(centralWidget);
        zoomIn_but->setObjectName(QString::fromUtf8("zoomIn_but"));

        horizontalLayout->addWidget(zoomIn_but);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        zoomOut_but = new QPushButton(centralWidget);
        zoomOut_but->setObjectName(QString::fromUtf8("zoomOut_but"));

        horizontalLayout->addWidget(zoomOut_but);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        reset_but = new QPushButton(centralWidget);
        reset_but->setObjectName(QString::fromUtf8("reset_but"));

        horizontalLayout->addWidget(reset_but);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1279, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        newWindow_menu = new QMenu(menuBar);
        newWindow_menu->setObjectName(QString::fromUtf8("newWindow_menu"));
        newWindow_menu->setEnabled(true);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(newWindow_menu->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(readwav_act);
        menu->addAction(play_act);
        menu->addSeparator();
        menu_3->addAction(newsinglewav_act);
        menu_2->addAction(spectrumwind_open_act);
        menu_4->addAction(freqResp_act);
        menu_4->addAction(winFunc_act);
        menu_5->addAction(helpAction);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        play_act->setText(QCoreApplication::translate("MainWindowClass", "\346\222\255\346\224\276", nullptr));
        periodwind_open_act->setText(QCoreApplication::translate("MainWindowClass", "\345\221\250\346\234\237\345\210\206\346\236\220", nullptr));
        spectrumwind_open_act->setText(QCoreApplication::translate("MainWindowClass", "\351\242\221\350\260\261\345\210\206\346\236\220", nullptr));
        filterwind_open_act->setText(QCoreApplication::translate("MainWindowClass", "\346\273\244\346\263\242", nullptr));
        readwav_act->setText(QCoreApplication::translate("MainWindowClass", "\344\273\216\346\226\207\344\273\266\350\257\273\345\217\226\357\274\210.wav\357\274\211", nullptr));
        newsinglewav_act->setText(QCoreApplication::translate("MainWindowClass", "\346\226\260\345\273\272wav", nullptr));
        windowopen->setText(QCoreApplication::translate("MainWindowClass", "open", nullptr));
        spectrogram_act->setText(QCoreApplication::translate("MainWindowClass", "\350\257\255\350\260\261\345\210\206\346\236\220", nullptr));
        freqResp_act->setText(QCoreApplication::translate("MainWindowClass", "\351\242\221\347\216\207\345\223\215\345\272\224", nullptr));
        winFunc_act->setText(QCoreApplication::translate("MainWindowClass", "\347\252\227\345\217\243\345\207\275\346\225\260", nullptr));
        actionp->setText(QCoreApplication::translate("MainWindowClass", "\351\242\221\350\260\261\345\210\206\346\236\220", nullptr));
        actionp_2->setText(QCoreApplication::translate("MainWindowClass", "\350\257\255\350\260\261\345\210\206\346\236\220", nullptr));
        helpAction->setText(QCoreApplication::translate("MainWindowClass", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        zoomIn_but->setText(QCoreApplication::translate("MainWindowClass", "\346\224\276\345\244\247", nullptr));
        zoomOut_but->setText(QCoreApplication::translate("MainWindowClass", "\347\274\251\345\260\217", nullptr));
        reset_but->setText(QCoreApplication::translate("MainWindowClass", "\351\207\215\347\275\256", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindowClass", "\350\217\234\345\215\225", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindowClass", "\346\226\260\345\273\272", nullptr));
        newWindow_menu->setTitle(QString());
        menu_2->setTitle(QCoreApplication::translate("MainWindowClass", "\345\210\206\346\236\220", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindowClass", "\351\242\221\347\216\207\345\223\215\345\272\224", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindowClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
