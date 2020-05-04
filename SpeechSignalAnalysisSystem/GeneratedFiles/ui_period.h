/********************************************************************************
** Form generated from reading UI file 'period.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIOD_H
#define UI_PERIOD_H

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

class Ui_Period
{
public:
    QAction *action;
    QWidget *centralwidget;
    QPushButton *reset_but;
    QScrollBar *horizontalScrollBar;
    QPushButton *zoomOut_but;
    QPushButton *zoomIn_but;
    QWidget *period_wid;
    QMenuBar *menubar;
    QMenu *menucaidan;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Period)
    {
        if (Period->objectName().isEmpty())
            Period->setObjectName(QString::fromUtf8("Period"));
        Period->resize(1226, 708);
        action = new QAction(Period);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(Period);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        reset_but = new QPushButton(centralwidget);
        reset_but->setObjectName(QString::fromUtf8("reset_but"));
        reset_but->setGeometry(QRect(350, 620, 93, 28));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(710, 620, 481, 31));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        zoomOut_but = new QPushButton(centralwidget);
        zoomOut_but->setObjectName(QString::fromUtf8("zoomOut_but"));
        zoomOut_but->setGeometry(QRect(190, 620, 93, 28));
        zoomIn_but = new QPushButton(centralwidget);
        zoomIn_but->setObjectName(QString::fromUtf8("zoomIn_but"));
        zoomIn_but->setGeometry(QRect(30, 620, 93, 28));
        period_wid = new QWidget(centralwidget);
        period_wid->setObjectName(QString::fromUtf8("period_wid"));
        period_wid->setGeometry(QRect(10, 10, 1201, 591));
        Period->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Period);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1226, 26));
        menucaidan = new QMenu(menubar);
        menucaidan->setObjectName(QString::fromUtf8("menucaidan"));
        Period->setMenuBar(menubar);
        statusbar = new QStatusBar(Period);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Period->setStatusBar(statusbar);

        menubar->addAction(menucaidan->menuAction());
        menucaidan->addAction(action);

        retranslateUi(Period);

        QMetaObject::connectSlotsByName(Period);
    } // setupUi

    void retranslateUi(QMainWindow *Period)
    {
        Period->setWindowTitle(QCoreApplication::translate("Period", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("Period", "\347\252\227\345\217\243\344\277\241\346\201\257", nullptr));
        reset_but->setText(QCoreApplication::translate("Period", "\351\207\215\347\275\256", nullptr));
        zoomOut_but->setText(QCoreApplication::translate("Period", "\347\274\251\345\260\217", nullptr));
        zoomIn_but->setText(QCoreApplication::translate("Period", "\346\224\276\345\244\247", nullptr));
        menucaidan->setTitle(QCoreApplication::translate("Period", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Period: public Ui_Period {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIOD_H
