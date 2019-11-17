#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <sndfile.h>
#include <QtMultimedia/QSound>
#include<QMessageBox>
#include"wavinfo.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
private:
	Ui::MainWindowClass ui;
	QString filename; //文件路径
	QCPGraph *pGraph; //图表
	QCPGraph *pGraph2;
	SF_INFO sf_info;  //读取语音返回的数据
	SNDFILE *snd_file;  //读取语音
	WavInfo *wavinfo=NULL;  //语音对象类，用于储存语音数据
	QCPColorMap *pColorMap = NULL; //用于绘制语谱图
	QCPItemPixmap *pixmap;//用于绘制语谱图
	QCPAxis *xAxis;//语谱图x轴
	QCPAxis *yAxis;//语谱图y轴

private:
	void testDraw();
	void testDraw_2();
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
	void onClickOpenSpectrogramWindow();
	void onClickOpenfreqRespWindow();
	void onClickOpenWinFuncWindow();
};
