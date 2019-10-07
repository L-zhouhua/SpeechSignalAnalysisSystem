#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <sndfile.h>

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
	SF_INFO sf_info;
	SNDFILE *snd_file;
	double *buf;       //采样点
	int samplerate; //采样率
	int frames;     //每个声道的采样点
	int length;     //总采样点（frame*channels）
	int channels;   //音道数
	double duration;   //周期

private slots:
	void onClickChooseWavFile();
	void onClickOpenfilterWindow();
	void onClickOpenperiodWindow();
	void onClickOpenrecordWindow();
	void onClickOpenspectrumWindow();
};
