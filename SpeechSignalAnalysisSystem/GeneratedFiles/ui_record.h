/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
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
#include <QtWidgets/QSpacerItem>
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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *containerBox;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *audioCodecBox;
    QLabel *label_3;
    QComboBox *audioDeviceBox;
    QComboBox *channelsBox;
    QComboBox *sampleRateBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *constantQualityRadioButton;
    QSlider *qualitySlider;
    QRadioButton *constantBitrateRadioButton;
    QComboBox *bitrateBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *output_but;
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
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        containerBox = new QComboBox(centralwidget);
        containerBox->setObjectName(QString::fromUtf8("containerBox"));
        QFont font;
        font.setPointSize(11);
        containerBox->setFont(font);

        gridLayout->addWidget(containerBox, 4, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        audioCodecBox = new QComboBox(centralwidget);
        audioCodecBox->setObjectName(QString::fromUtf8("audioCodecBox"));
        audioCodecBox->setFont(font);

        gridLayout->addWidget(audioCodecBox, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        audioDeviceBox = new QComboBox(centralwidget);
        audioDeviceBox->setObjectName(QString::fromUtf8("audioDeviceBox"));
        audioDeviceBox->setFont(font);

        gridLayout->addWidget(audioDeviceBox, 0, 1, 1, 1);

        channelsBox = new QComboBox(centralwidget);
        channelsBox->setObjectName(QString::fromUtf8("channelsBox"));
        channelsBox->setFont(font);

        gridLayout->addWidget(channelsBox, 8, 1, 1, 1);

        sampleRateBox = new QComboBox(centralwidget);
        sampleRateBox->setObjectName(QString::fromUtf8("sampleRateBox"));
        sampleRateBox->setFont(font);

        gridLayout->addWidget(sampleRateBox, 6, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 7, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 5);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        constantQualityRadioButton = new QRadioButton(groupBox);
        constantQualityRadioButton->setObjectName(QString::fromUtf8("constantQualityRadioButton"));
        constantQualityRadioButton->setChecked(true);

        gridLayout_3->addWidget(constantQualityRadioButton, 0, 0, 1, 1);

        qualitySlider = new QSlider(groupBox);
        qualitySlider->setObjectName(QString::fromUtf8("qualitySlider"));
        qualitySlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(qualitySlider, 1, 0, 1, 1);

        constantBitrateRadioButton = new QRadioButton(groupBox);
        constantBitrateRadioButton->setObjectName(QString::fromUtf8("constantBitrateRadioButton"));

        gridLayout_3->addWidget(constantBitrateRadioButton, 2, 0, 1, 1);

        bitrateBox = new QComboBox(groupBox);
        bitrateBox->setObjectName(QString::fromUtf8("bitrateBox"));
        bitrateBox->setEnabled(false);

        gridLayout_3->addWidget(bitrateBox, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        output_but = new QPushButton(centralwidget);
        output_but->setObjectName(QString::fromUtf8("output_but"));
        output_but->setFont(font);

        horizontalLayout->addWidget(output_but);

        startRecord_but = new QPushButton(centralwidget);
        startRecord_but->setObjectName(QString::fromUtf8("startRecord_but"));
        startRecord_but->setFont(font);

        horizontalLayout->addWidget(startRecord_but);

        pause_but = new QPushButton(centralwidget);
        pause_but->setObjectName(QString::fromUtf8("pause_but"));
        pause_but->setEnabled(false);
        pause_but->setFont(font);

        horizontalLayout->addWidget(pause_but);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        Record->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Record);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 620, 23));
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
        QObject::connect(constantQualityRadioButton, SIGNAL(toggled(bool)), qualitySlider, SLOT(setEnabled(bool)));
        QObject::connect(constantBitrateRadioButton, SIGNAL(toggled(bool)), bitrateBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Record);
    } // setupUi

    void retranslateUi(QMainWindow *Record)
    {
        Record->setWindowTitle(QCoreApplication::translate("Record", "MainWindow", nullptr));
        action_WAV->setText(QCoreApplication::translate("Record", "\344\277\235\345\255\230\344\270\272WAV\346\226\207\344\273\266", nullptr));
        action_AIFC->setText(QCoreApplication::translate("Record", "\344\277\235\345\255\230\344\270\272AIFC\346\226\207\344\273\266", nullptr));
        action->setText(QCoreApplication::translate("Record", "\345\205\263\351\227\255", nullptr));
        label_4->setText(QCoreApplication::translate("Record", "\351\207\207\346\240\267\347\216\207\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Record", "\345\243\260\351\201\223\346\225\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Record", "\346\226\207\344\273\266\345\256\271\345\231\250\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Record", "\350\276\223\345\205\245\350\256\276\345\244\207\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Record", "\351\237\263\351\242\221\347\274\226\350\247\243\347\240\201\345\231\250\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Record", "\347\274\226\347\240\201\346\250\241\345\274\217", nullptr));
        constantQualityRadioButton->setText(QCoreApplication::translate("Record", "\351\237\263\350\264\250\357\274\232", nullptr));
        constantBitrateRadioButton->setText(QCoreApplication::translate("Record", "\344\275\215\347\216\207\357\274\232", nullptr));
        output_but->setText(QCoreApplication::translate("Record", "\344\277\235\345\255\230", nullptr));
        startRecord_but->setText(QCoreApplication::translate("Record", "\345\275\225\351\237\263", nullptr));
        pause_but->setText(QCoreApplication::translate("Record", "\346\232\202\345\201\234", nullptr));
        menu->setTitle(QCoreApplication::translate("Record", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
