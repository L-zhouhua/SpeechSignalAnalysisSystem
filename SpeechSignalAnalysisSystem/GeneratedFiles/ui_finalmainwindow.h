/********************************************************************************
** Form generated from reading UI file 'finalmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALMAINWINDOW_H
#define UI_FINALMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_finalMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_18;
    QPushButton *pushButton_14;
    QPushButton *pushButton_19;
    QPushButton *pushButton_12;
    QPushButton *pushButton_17;
    QPushButton *pushButton_16;
    QSlider *horizontalSlider;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QWidget *widget_5;
    QLabel *label;
    QWidget *widget_6;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QToolBox *toolBox_2;
    QWidget *page_4;
    QPushButton *pushButton_15;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QWidget *page_5;
    QWidget *page_6;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QScrollBar *horizontalScrollBar;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget1;
    QCustomPlot *widget_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *finalMainWindow)
    {
        if (finalMainWindow->objectName().isEmpty())
            finalMainWindow->setObjectName(QString::fromUtf8("finalMainWindow"));
        finalMainWindow->resize(1405, 801);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(finalMainWindow->sizePolicy().hasHeightForWidth());
        finalMainWindow->setSizePolicy(sizePolicy);
        finalMainWindow->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    border-radius:17;\n"
"	\n"
"}\n"
"QPushButton:hover\n"
"{ \n"
"	background-color: rgb(131, 197, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgb(14 , 135 , 228);\n"
"}\n"
""));
        centralwidget = new QWidget(finalMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(15, 23));
        widget_4->setMaximumSize(QSize(184, 145));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_11 = new QPushButton(widget_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy2);
        pushButton_11->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/4yq5jAD2pn.png);"));

        gridLayout_3->addWidget(pushButton_11, 0, 0, 1, 1);

        pushButton_13 = new QPushButton(widget_4);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        sizePolicy2.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy2);
        pushButton_13->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/7.png);"));

        gridLayout_3->addWidget(pushButton_13, 0, 2, 1, 1);

        pushButton_18 = new QPushButton(widget_4);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        sizePolicy2.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pushButton_18, 1, 2, 1, 1);

        pushButton_14 = new QPushButton(widget_4);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy2.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pushButton_14, 0, 3, 1, 1);

        pushButton_19 = new QPushButton(widget_4);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        sizePolicy2.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pushButton_19, 1, 3, 1, 1);

        pushButton_12 = new QPushButton(widget_4);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy2.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy2);
        pushButton_12->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/o73MEPWr3B.png);"));

        gridLayout_3->addWidget(pushButton_12, 0, 1, 1, 1);

        pushButton_17 = new QPushButton(widget_4);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        sizePolicy2.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pushButton_17, 1, 1, 1, 1);

        pushButton_16 = new QPushButton(widget_4);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy2.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pushButton_16, 1, 0, 1, 1);


        gridLayout->addWidget(widget_4, 2, 1, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 4);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy3);
        widget_3->setMaximumSize(QSize(225, 100));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/1.png);"));

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/3.png);"));

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_4->setAutoDefault(false);

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);
        pushButton_5->setFocusPolicy(Qt::StrongFocus);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_5->setAutoRepeat(false);

        gridLayout_2->addWidget(pushButton_5, 0, 4, 1, 1);

        pushButton_7 = new QPushButton(widget_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);
        pushButton_7->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/6.png);"));

        gridLayout_2->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(widget_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy2.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy2);
        pushButton_8->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/5.png);"));

        gridLayout_2->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_6->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/2.png);"));

        gridLayout_2->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_10 = new QPushButton(widget_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy2.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy2);
        pushButton_10->setStyleSheet(QString::fromUtf8("border-image: url(:/MainWindow/C:/Users/12860/Desktop/image/4.png);"));

        gridLayout_2->addWidget(pushButton_10, 1, 3, 1, 1);

        pushButton_9 = new QPushButton(widget_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy2.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pushButton_9, 1, 4, 1, 1);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout->addWidget(widget_3, 2, 0, 1, 1);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 30, 241, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(25);
        label->setFont(font);

        gridLayout->addWidget(widget_5, 2, 2, 1, 1);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMaximumSize(QSize(225, 16777215));

        gridLayout->addWidget(widget_6, 2, 3, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        sizePolicy1.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy1);
        toolBox->setMaximumSize(QSize(130, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 130, 502));
        toolBox_2 = new QToolBox(page);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        toolBox_2->setGeometry(QRect(10, 0, 101, 481));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 101, 391));
        pushButton_15 = new QPushButton(page_4);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(0, 290, 93, 28));
        widget = new QWidget(page_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 101, 251));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_3->addWidget(lineEdit_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        toolBox_2->addItem(page_4, QString::fromUtf8("\346\261\211\345\256\201\347\252\227"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 101, 391));
        toolBox_2->addItem(page_5, QString::fromUtf8("\346\261\211\346\230\216\347\252\227"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 101, 391));
        toolBox_2->addItem(page_6, QString::fromUtf8("\351\253\230\346\226\257\347\252\227"));
        toolBox->addItem(page, QString::fromUtf8("\347\252\227\345\207\275\346\225\260"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 130, 502));
        toolBox->addItem(page_2, QString::fromUtf8("\346\273\244\346\263\242\345\231\250"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 130, 502));
        toolBox->addItem(page_3, QString::fromUtf8("\345\205\266\344\273\226"));
        splitter->addWidget(toolBox);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalScrollBar = new QScrollBar(layoutWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 120, 132);"));
        horizontalScrollBar->setSingleStep(4);
        horizontalScrollBar->setPageStep(10);
        horizontalScrollBar->setSliderPosition(0);
        horizontalScrollBar->setTracking(false);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalScrollBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(horizontalScrollBar);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget1 = new QCustomPlot(layoutWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));

        verticalLayout->addWidget(widget1);

        widget_2 = new QCustomPlot(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addLayout(verticalLayout);

        splitter->addWidget(layoutWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 4);

        finalMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(finalMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1405, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        finalMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(finalMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        finalMainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(finalMainWindow);

        toolBox->setCurrentIndex(0);
        toolBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(finalMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *finalMainWindow)
    {
        finalMainWindow->setWindowTitle(QApplication::translate("finalMainWindow", "MainWindow", nullptr));
        pushButton_11->setText(QString());
        pushButton_13->setText(QString());
        pushButton_18->setText(QString());
        pushButton_14->setText(QString());
        pushButton_19->setText(QString());
        pushButton_12->setText(QString());
        pushButton_17->setText(QString());
        pushButton_16->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        pushButton_10->setText(QString());
        pushButton_9->setText(QString());
        pushButton->setText(QString());
        label->setText(QApplication::translate("finalMainWindow", "TimeRunning", nullptr));
        pushButton_15->setText(QApplication::translate("finalMainWindow", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("finalMainWindow", "\345\217\202\346\225\2601\357\274\232", nullptr));
        label_3->setText(QApplication::translate("finalMainWindow", "\345\217\202\346\225\2602\357\274\232", nullptr));
        label_4->setText(QApplication::translate("finalMainWindow", "\345\217\202\346\225\2603\357\274\232", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_4), QApplication::translate("finalMainWindow", "\346\261\211\345\256\201\347\252\227", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_5), QApplication::translate("finalMainWindow", "\346\261\211\346\230\216\347\252\227", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_6), QApplication::translate("finalMainWindow", "\351\253\230\346\226\257\347\252\227", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("finalMainWindow", "\347\252\227\345\207\275\346\225\260", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("finalMainWindow", "\346\273\244\346\263\242\345\231\250", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("finalMainWindow", "\345\205\266\344\273\226", nullptr));
        menu->setTitle(QApplication::translate("finalMainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class finalMainWindow: public Ui_finalMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALMAINWINDOW_H
