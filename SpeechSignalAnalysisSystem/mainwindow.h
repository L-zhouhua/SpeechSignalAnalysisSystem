#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <sndfile.h>
#include <QtMultimedia/QSound>
#include<QMessageBox>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
private:
	Ui::MainWindowClass ui;
	QString filename;
	QCPGraph *pGraph;
	QCPGraph *pGraph2;
	SF_INFO sf_info;
	SNDFILE *snd_file;
	double *buf = NULL;       //采样点
	int samplerate; //采样率（每秒采样个数，单位Hz）
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
	void onClickOpenNewWindow();
	void onClickZoomIn();
	void onClickZoomOut();
	void onClickReset();
	void onClickPlayWav();
};
