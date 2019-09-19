#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qcustomplot.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
	QString filename;
	QCPGraph *pGraph;
	QCPGraph *pGraph2;
	double samplerate; //������
	double length;     //�����㳤��
	double channels;   //������
	double duration;   //����

private slots:
	void onClickChooseWavFile();
	void onClickOpenfilterWindow();
	void onClickOpenperiodWindow();
	void onClickOpenrecordWindow();
	void onClickOpenspectrumWindow();
};
