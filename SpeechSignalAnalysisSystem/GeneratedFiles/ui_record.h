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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
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
    QGroupBox *groupBox;
    QSlider *qualitySlider;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QComboBox *bitrateBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *containerBox;
    QComboBox *audioDeviceBox;
    QComboBox *channelsBox;
    QLabel *label_2;
    QComboBox *audioCodecBox;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_5;
    QComboBox *sampleRateBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *save_but;
    QPushButton *startRecord_but;
    QPushButton *pause_but;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Record)
    {
        if (Record->objectName().isEmpty())
            Record->setObjectName(QString::fromUtf8("Record"));
        Record->resize(620, 530);
        action_WAV = new QAction(Record);
        action_WAV->setObjectName(QString::fromUtf8("action_WAV"));
        action_AIFC = new QAction(Record);
        action_AIFC->setObjectName(QString::fromUtf8("action_AIFC"));
        action = new QAction(Record);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(Record);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 260, 491, 171));
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        qualitySlider = new QSlider(groupBox);
        qualitySlider->setObjectName(QString::fromUtf8("qualitySlider"));
        qualitySlider->setGeometry(QRect(70, 60, 391, 22));
        qualitySlider->setOrientation(Qt::Horizontal);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 30, 115, 19));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 100, 115, 19));
        bitrateBox = new QComboBox(groupBox);
        bitrateBox->setObjectName(QString::fromUtf8("bitrateBox"));
        bitrateBox->setGeometry(QRect(70, 130, 391, 22));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 10, 491, 241));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        containerBox = new QComboBox(layoutWidget);
        containerBox->setObjectName(QString::fromUtf8("containerBox"));
        containerBox->setFont(font);

        gridLayout->addWidget(containerBox, 2, 1, 1, 1);

        audioDeviceBox = new QComboBox(layoutWidget);
        audioDeviceBox->setObjectName(QString::fromUtf8("audioDeviceBox"));
        audioDeviceBox->setFont(font);

        gridLayout->addWidget(audioDeviceBox, 0, 1, 1, 1);

        channelsBox = new QComboBox(layoutWidget);
        channelsBox->setObjectName(QString::fromUtf8("channelsBox"));
        channelsBox->setFont(font);

        gridLayout->addWidget(channelsBox, 4, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        audioCodecBox = new QComboBox(layoutWidget);
        audioCodecBox->setObjectName(QString::fromUtf8("audioCodecBox"));
        audioCodecBox->setFont(font);

        gridLayout->addWidget(audioCodecBox, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        sampleRateBox = new QComboBox(layoutWidget);
        sampleRateBox->setObjectName(QString::fromUtf8("sampleRateBox"));
        sampleRateBox->setFont(font);

        gridLayout->addWidget(sampleRateBox, 3, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 5);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 440, 511, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        save_but = new QPushButton(layoutWidget1);
        save_but->setObjectName(QString::fromUtf8("save_but"));
        save_but->setFont(font);

        horizontalLayout->addWidget(save_but);

        startRecord_but = new QPushButton(layoutWidget1);
        startRecord_but->setObjectName(QString::fromUtf8("startRecord_but"));
        startRecord_but->setFont(font);

        horizontalLayout->addWidget(startRecord_but);

        pause_but = new QPushButton(layoutWidget1);
        pause_but->setObjectName(QString::fromUtf8("pause_but"));
        pause_but->setEnabled(false);
        pause_but->setFont(font);

        horizontalLayout->addWidget(pause_but);

        Record->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Record);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 620, 26));
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
        groupBox->setTitle(QApplication::translate("Record", "\347\274\226\347\240\201\346\250\241\345\274\217", nullptr));
        radioButton->setText(QApplication::translate("Record", "\351\237\263\350\264\250\357\274\232", nullptr));
        radioButton_2->setText(QApplication::translate("Record", "\344\275\215\347\216\207\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Record", "\351\237\263\351\242\221\347\274\226\350\247\243\347\240\201\345\231\250\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Record", "\351\207\207\346\240\267\347\216\207\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Record", "\346\226\207\344\273\266\345\256\271\345\231\250\357\274\232", nullptr));
        label->setText(QApplication::translate("Record", "\350\276\223\345\205\245\350\256\276\345\244\207\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Record", "\345\243\260\351\201\223\346\225\260\357\274\232", nullptr));
        save_but->setText(QApplication::translate("Record", "\344\277\235\345\255\230", nullptr));
        startRecord_but->setText(QApplication::translate("Record", "\345\275\225\351\237\263", nullptr));
        pause_but->setText(QApplication::translate("Record", "\346\232\202\345\201\234", nullptr));
        menu->setTitle(QApplication::translate("Record", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
