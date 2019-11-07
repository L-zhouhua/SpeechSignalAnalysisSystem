/********************************************************************************
** Form generated from reading UI file 'freqyres.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQYRES_H
#define UI_FREQYRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FreqyRes
{
public:
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QToolBox *type_toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *order_edit_LP;
    QLabel *label_3;
    QLineEdit *parameter_edit_LP;
    QPushButton *affirm_but_LP;
    QWidget *page_4;
    QLineEdit *parameter_edit_HP;
    QLineEdit *order_edit_HP;
    QLabel *label_9;
    QPushButton *affirm_but_HP;
    QLabel *label_10;
    QWidget *page_3;
    QLineEdit *parameter_edit_BP;
    QLineEdit *order_edit_BP;
    QLabel *label_11;
    QPushButton *affirm_but_BP;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *parameter_edit_2_BP;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QLineEdit *order_edit_BS;
    QLabel *label_14;
    QLineEdit *parameter_edit_BS;
    QLabel *label_16;
    QLineEdit *parameter_edit_2_BS;
    QPushButton *affirm_but_BS;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCustomPlot *freqyres_widget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QCustomPlot *freqyres_widget_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *type_lab;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *order_lab;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *parameter_lab;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QLabel *parameter_lab_2;
    QPlainTextEdit *plainTextEdit;
    QWidget *tab_6;

    void setupUi(QWidget *FreqyRes)
    {
        if (FreqyRes->objectName().isEmpty())
            FreqyRes->setObjectName(QString::fromUtf8("FreqyRes"));
        FreqyRes->resize(1339, 468);
        verticalLayout_7 = new QVBoxLayout(FreqyRes);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget = new QTabWidget(FreqyRes);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_2 = new QGridLayout(tab_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(200, 16777215));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        type_toolBox = new QToolBox(groupBox_3);
        type_toolBox->setObjectName(QString::fromUtf8("type_toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 176, 237));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(label_2);

        order_edit_LP = new QLineEdit(page);
        order_edit_LP->setObjectName(QString::fromUtf8("order_edit_LP"));
        order_edit_LP->setFocusPolicy(Qt::StrongFocus);
        order_edit_LP->setEchoMode(QLineEdit::Normal);

        verticalLayout_3->addWidget(order_edit_LP);

        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(label_3);

        parameter_edit_LP = new QLineEdit(page);
        parameter_edit_LP->setObjectName(QString::fromUtf8("parameter_edit_LP"));

        verticalLayout_3->addWidget(parameter_edit_LP);

        affirm_but_LP = new QPushButton(page);
        affirm_but_LP->setObjectName(QString::fromUtf8("affirm_but_LP"));
        affirm_but_LP->setEnabled(true);
        affirm_but_LP->setMaximumSize(QSize(16777215, 16777215));
        affirm_but_LP->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(affirm_but_LP);

        type_toolBox->addItem(page, QString::fromUtf8("\344\275\216\351\200\232\346\273\244\346\263\242\345\231\250"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 176, 237));
        parameter_edit_HP = new QLineEdit(page_4);
        parameter_edit_HP->setObjectName(QString::fromUtf8("parameter_edit_HP"));
        parameter_edit_HP->setGeometry(QRect(10, 178, 154, 24));
        order_edit_HP = new QLineEdit(page_4);
        order_edit_HP->setObjectName(QString::fromUtf8("order_edit_HP"));
        order_edit_HP->setGeometry(QRect(10, 68, 154, 24));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 110, 154, 50));
        label_9->setMaximumSize(QSize(16777215, 50));
        affirm_but_HP = new QPushButton(page_4);
        affirm_but_HP->setObjectName(QString::fromUtf8("affirm_but_HP"));
        affirm_but_HP->setEnabled(true);
        affirm_but_HP->setGeometry(QRect(10, 220, 154, 28));
        affirm_but_HP->setMaximumSize(QSize(16777215, 16777215));
        affirm_but_HP->setIconSize(QSize(20, 20));
        label_10 = new QLabel(page_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 0, 154, 50));
        label_10->setMaximumSize(QSize(16777215, 50));
        type_toolBox->addItem(page_4, QString::fromUtf8("\351\253\230\351\200\232\346\273\244\346\263\242\345\231\250"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 176, 237));
        parameter_edit_BP = new QLineEdit(page_3);
        parameter_edit_BP->setObjectName(QString::fromUtf8("parameter_edit_BP"));
        parameter_edit_BP->setGeometry(QRect(0, 130, 154, 24));
        order_edit_BP = new QLineEdit(page_3);
        order_edit_BP->setObjectName(QString::fromUtf8("order_edit_BP"));
        order_edit_BP->setGeometry(QRect(0, 50, 154, 24));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 80, 154, 50));
        label_11->setMaximumSize(QSize(16777215, 50));
        affirm_but_BP = new QPushButton(page_3);
        affirm_but_BP->setObjectName(QString::fromUtf8("affirm_but_BP"));
        affirm_but_BP->setEnabled(true);
        affirm_but_BP->setGeometry(QRect(0, 260, 154, 28));
        affirm_but_BP->setMaximumSize(QSize(16777215, 16777215));
        affirm_but_BP->setIconSize(QSize(20, 20));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 154, 50));
        label_12->setMaximumSize(QSize(16777215, 50));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, 150, 154, 50));
        label_13->setMaximumSize(QSize(16777215, 50));
        parameter_edit_2_BP = new QLineEdit(page_3);
        parameter_edit_2_BP->setObjectName(QString::fromUtf8("parameter_edit_2_BP"));
        parameter_edit_2_BP->setGeometry(QRect(0, 210, 154, 24));
        type_toolBox->addItem(page_3, QString::fromUtf8("\345\270\246\351\200\232\346\273\244\346\263\242\345\231\250"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 176, 237));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(label_15);

        order_edit_BS = new QLineEdit(page_2);
        order_edit_BS->setObjectName(QString::fromUtf8("order_edit_BS"));

        verticalLayout_4->addWidget(order_edit_BS);

        label_14 = new QLabel(page_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(label_14);

        parameter_edit_BS = new QLineEdit(page_2);
        parameter_edit_BS->setObjectName(QString::fromUtf8("parameter_edit_BS"));

        verticalLayout_4->addWidget(parameter_edit_BS);

        label_16 = new QLabel(page_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(label_16);

        parameter_edit_2_BS = new QLineEdit(page_2);
        parameter_edit_2_BS->setObjectName(QString::fromUtf8("parameter_edit_2_BS"));

        verticalLayout_4->addWidget(parameter_edit_2_BS);

        affirm_but_BS = new QPushButton(page_2);
        affirm_but_BS->setObjectName(QString::fromUtf8("affirm_but_BS"));
        affirm_but_BS->setEnabled(true);
        affirm_but_BS->setMaximumSize(QSize(16777215, 16777215));
        affirm_but_BS->setIconSize(QSize(20, 20));

        verticalLayout_4->addWidget(affirm_but_BS);

        type_toolBox->addItem(page_2, QString::fromUtf8("\345\270\246\351\230\273\346\273\244\346\263\242\345\231\250"));

        gridLayout->addWidget(type_toolBox, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 0, 1, 1);

        widget = new QWidget(tab_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        freqyres_widget = new QCustomPlot(groupBox);
        freqyres_widget->setObjectName(QString::fromUtf8("freqyres_widget"));

        verticalLayout->addWidget(freqyres_widget);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        freqyres_widget_2 = new QCustomPlot(groupBox_2);
        freqyres_widget_2->setObjectName(QString::fromUtf8("freqyres_widget_2"));

        verticalLayout_5->addWidget(freqyres_widget_2);


        verticalLayout_6->addWidget(groupBox_2);


        gridLayout_2->addWidget(widget, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(200, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        type_lab = new QLabel(groupBox_4);
        type_lab->setObjectName(QString::fromUtf8("type_lab"));

        horizontalLayout->addWidget(type_lab);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        order_lab = new QLabel(groupBox_4);
        order_lab->setObjectName(QString::fromUtf8("order_lab"));

        horizontalLayout_2->addWidget(order_lab);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        parameter_lab = new QLabel(groupBox_4);
        parameter_lab->setObjectName(QString::fromUtf8("parameter_lab"));

        horizontalLayout_3->addWidget(parameter_lab);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_4->addWidget(label_17);

        parameter_lab_2 = new QLabel(groupBox_4);
        parameter_lab_2->setObjectName(QString::fromUtf8("parameter_lab_2"));

        horizontalLayout_4->addWidget(parameter_lab_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(true);
        plainTextEdit->setMaximumSize(QSize(16777215, 224));
        plainTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(plainTextEdit);


        gridLayout_2->addWidget(groupBox_4, 0, 2, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());

        verticalLayout_7->addWidget(tabWidget);

        QWidget::setTabOrder(order_edit_LP, parameter_edit_LP);
        QWidget::setTabOrder(parameter_edit_LP, affirm_but_LP);
        QWidget::setTabOrder(affirm_but_LP, order_edit_HP);
        QWidget::setTabOrder(order_edit_HP, parameter_edit_HP);
        QWidget::setTabOrder(parameter_edit_HP, affirm_but_HP);
        QWidget::setTabOrder(affirm_but_HP, order_edit_BP);
        QWidget::setTabOrder(order_edit_BP, parameter_edit_BP);
        QWidget::setTabOrder(parameter_edit_BP, parameter_edit_2_BP);
        QWidget::setTabOrder(parameter_edit_2_BP, affirm_but_BP);
        QWidget::setTabOrder(affirm_but_BP, order_edit_BS);
        QWidget::setTabOrder(order_edit_BS, parameter_edit_BS);
        QWidget::setTabOrder(parameter_edit_BS, parameter_edit_2_BS);
        QWidget::setTabOrder(parameter_edit_2_BS, affirm_but_BS);

        retranslateUi(FreqyRes);

        type_toolBox->setCurrentIndex(0);
        type_toolBox->layout()->setSpacing(7);


        QMetaObject::connectSlotsByName(FreqyRes);
    } // setupUi

    void retranslateUi(QWidget *FreqyRes)
    {
        FreqyRes->setWindowTitle(QApplication::translate("FreqyRes", "FreqyRes", nullptr));
        groupBox_3->setTitle(QApplication::translate("FreqyRes", "\350\276\223\345\205\245\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        affirm_but_LP->setText(QApplication::translate("FreqyRes", "\347\241\256\350\256\244", nullptr));
        type_toolBox->setItemText(type_toolBox->indexOf(page), QApplication::translate("FreqyRes", "\344\275\216\351\200\232\346\273\244\346\263\242\345\231\250", nullptr));
        label_9->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        affirm_but_HP->setText(QApplication::translate("FreqyRes", "\347\241\256\350\256\244", nullptr));
        label_10->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        type_toolBox->setItemText(type_toolBox->indexOf(page_4), QApplication::translate("FreqyRes", "\351\253\230\351\200\232\346\273\244\346\263\242\345\231\250", nullptr));
        label_11->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        affirm_but_BP->setText(QApplication::translate("FreqyRes", "\347\241\256\350\256\244", nullptr));
        label_12->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        label_13->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\2602\357\274\232", nullptr));
        type_toolBox->setItemText(type_toolBox->indexOf(page_3), QApplication::translate("FreqyRes", "\345\270\246\351\200\232\346\273\244\346\263\242\345\231\250", nullptr));
        label_15->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        label_14->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        label_16->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\2602\357\274\232", nullptr));
        affirm_but_BS->setText(QApplication::translate("FreqyRes", "\347\241\256\350\256\244", nullptr));
        type_toolBox->setItemText(type_toolBox->indexOf(page_2), QApplication::translate("FreqyRes", "\345\270\246\351\230\273\346\273\244\346\263\242\345\231\250", nullptr));
        groupBox->setTitle(QApplication::translate("FreqyRes", "IIR\351\242\221\347\216\207\345\223\215\345\272\224\342\205\240", nullptr));
        groupBox_2->setTitle(QApplication::translate("FreqyRes", "IIR\351\242\221\347\216\207\345\223\215\345\272\224\342\205\241", nullptr));
        groupBox_4->setTitle(QApplication::translate("FreqyRes", "\347\252\227\345\217\243\344\277\241\346\201\257", nullptr));
        label_4->setText(QApplication::translate("FreqyRes", "\347\261\273\345\236\213\357\274\232", nullptr));
        type_lab->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("FreqyRes", "\351\230\266\346\225\260\357\274\232", nullptr));
        order_lab->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\260\357\274\232", nullptr));
        parameter_lab->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        label_17->setText(QApplication::translate("FreqyRes", "\345\217\202\346\225\2602\357\274\232", nullptr));
        parameter_lab_2->setText(QApplication::translate("FreqyRes", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("FreqyRes", "IIR\351\242\221\347\216\207\345\223\215\345\272\224", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("FreqyRes", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FreqyRes: public Ui_FreqyRes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQYRES_H
