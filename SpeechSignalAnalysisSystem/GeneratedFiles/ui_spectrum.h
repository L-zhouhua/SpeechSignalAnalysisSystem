/********************************************************************************
** Form generated from reading UI file 'spectrum.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTRUM_H
#define UI_SPECTRUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spectrum
{
public:
    QAction *action;
    QWidget *centralwidget;
    QPushButton *zoomOut_but;
    QPushButton *reset_but;
    QScrollBar *horizontalScrollBar;
    QPushButton *zoomIn_but;
    QWidget *widget;
    QMenuBar *menubar;
    QMenu *menu;
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
        zoomOut_but = new QPushButton(centralwidget);
        zoomOut_but->setObjectName(QString::fromUtf8("zoomOut_but"));
        zoomOut_but->setGeometry(QRect(180, 600, 93, 28));
        reset_but = new QPushButton(centralwidget);
        reset_but->setObjectName(QString::fromUtf8("reset_but"));
        reset_but->setGeometry(QRect(340, 600, 93, 28));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(510, 600, 481, 31));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        zoomIn_but = new QPushButton(centralwidget);
        zoomIn_but->setObjectName(QString::fromUtf8("zoomIn_but"));
        zoomIn_but->setGeometry(QRect(20, 600, 93, 28));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1001, 561));
        Spectrum->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Spectrum);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1032, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Spectrum->setMenuBar(menubar);
        statusbar = new QStatusBar(Spectrum);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Spectrum->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(Spectrum);

        QMetaObject::connectSlotsByName(Spectrum);
    } // setupUi

    void retranslateUi(QMainWindow *Spectrum)
    {
        Spectrum->setWindowTitle(QApplication::translate("Spectrum", "MainWindow", nullptr));
        action->setText(QApplication::translate("Spectrum", "\347\252\227\345\217\243\344\277\241\346\201\257", nullptr));
        zoomOut_but->setText(QApplication::translate("Spectrum", "\347\274\251\345\260\217", nullptr));
        reset_but->setText(QApplication::translate("Spectrum", "\351\207\215\347\275\256", nullptr));
        zoomIn_but->setText(QApplication::translate("Spectrum", "\346\224\276\345\244\247", nullptr));
        menu->setTitle(QApplication::translate("Spectrum", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spectrum: public Ui_Spectrum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTRUM_H
