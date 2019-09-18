/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Record
{
public:
    QAction *action_WAV;
    QAction *action_AIFC;
    QAction *action;
    QWidget *centralwidget;
    QLabel *label_2;
    QRadioButton *radioButton_7;
    QPushButton *pushButton;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_3;
    QLabel *label;
    QRadioButton *radioButton_8;
    QPushButton *pushButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_9;
    QWidget *widget;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Record)
    {
        if (Record->objectName().isEmpty())
            Record->setObjectName(QString::fromUtf8("Record"));
        Record->resize(888, 631);
        action_WAV = new QAction(Record);
        action_WAV->setObjectName(QString::fromUtf8("action_WAV"));
        action_AIFC = new QAction(Record);
        action_AIFC->setObjectName(QString::fromUtf8("action_AIFC"));
        action = new QAction(Record);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(Record);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 190, 72, 15));
        radioButton_7 = new QRadioButton(centralwidget);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        radioButton_7->setGeometry(QRect(120, 440, 115, 19));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 440, 89, 28));
        radioButton_4 = new QRadioButton(centralwidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(120, 290, 115, 19));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 120, 115, 19));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(380, 510, 89, 28));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(120, 80, 115, 19));
        radioButton_6 = new QRadioButton(centralwidget);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(120, 390, 115, 19));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(670, 440, 89, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 72, 15));
        radioButton_8 = new QRadioButton(centralwidget);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setGeometry(QRect(120, 490, 115, 19));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(530, 440, 89, 28));
        pushButton_2->setCheckable(false);
        pushButton_2->setChecked(false);
        pushButton_2->setAutoRepeat(false);
        pushButton_2->setAutoExclusive(false);
        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(120, 240, 115, 19));
        radioButton_5 = new QRadioButton(centralwidget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(120, 340, 115, 19));
        radioButton_9 = new QRadioButton(centralwidget);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));
        radioButton_9->setGeometry(QRect(120, 530, 115, 19));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(340, 80, 451, 301));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(670, 510, 89, 28));
        Record->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Record);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 888, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Record->setMenuBar(menubar);
        statusbar = new QStatusBar(Record);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Record->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_WAV);
        menu->addAction(action_AIFC);
        menu->addAction(action);

        retranslateUi(Record);

        QMetaObject::connectSlotsByName(Record);
    } // setupUi

    void retranslateUi(QMainWindow *Record)
    {
        Record->setWindowTitle(QApplication::translate("Record", "MainWindow", nullptr));
        action_WAV->setText(QApplication::translate("Record", "\344\277\235\345\255\230\344\270\272WAV\346\226\207\344\273\266", nullptr));
        action_AIFC->setText(QApplication::translate("Record", "\344\277\235\345\255\230\344\270\272AIFC\346\226\207\344\273\266", nullptr));
        action->setText(QApplication::translate("Record", "\345\205\263\351\227\255", nullptr));
        label_2->setText(QApplication::translate("Record", "\351\207\207\346\240\267\351\242\221\347\216\207\357\274\232", nullptr));
        radioButton_7->setText(QApplication::translate("Record", "44100Hz", nullptr));
        pushButton->setText(QApplication::translate("Record", "\345\275\225\345\210\266", nullptr));
        radioButton_4->setText(QApplication::translate("Record", "11025Hz", nullptr));
        radioButton_2->setText(QApplication::translate("Record", "\345\217\214\345\243\260\351\201\223", nullptr));
        pushButton_4->setText(QApplication::translate("Record", "\344\277\235\345\255\230", nullptr));
        radioButton->setText(QApplication::translate("Record", "\345\215\225\345\243\260\351\201\223", nullptr));
        radioButton_6->setText(QApplication::translate("Record", "32000Hz", nullptr));
        pushButton_3->setText(QApplication::translate("Record", "\346\222\255\346\224\276", nullptr));
        label->setText(QApplication::translate("Record", "\345\243\260\351\201\223\357\274\232", nullptr));
        radioButton_8->setText(QApplication::translate("Record", "48000Hz", nullptr));
        pushButton_2->setText(QApplication::translate("Record", "\345\201\234\346\255\242", nullptr));
        radioButton_3->setText(QApplication::translate("Record", "8000Hz", nullptr));
        radioButton_5->setText(QApplication::translate("Record", "22050Hz", nullptr));
        radioButton_9->setText(QApplication::translate("Record", "96000Hz", nullptr));
        pushButton_5->setText(QApplication::translate("Record", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("Record", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
