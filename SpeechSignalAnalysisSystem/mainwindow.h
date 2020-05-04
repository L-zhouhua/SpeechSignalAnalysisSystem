#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <sndfile.h>
#include <QtMultimedia/QSound>
#include<QMessageBox>
#include"wavinfo.h"
#include<iostream>
#include <assistant.h>
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
	QCPItemTracer *tracer;
	Assistant *assistant; //帮助文档
	//QCPItemStraightLine *line = NULL;
	//QCPItemStraightLine *line_2 = NULL;
	int mousePressFlag = 0;//判断鼠标左键状态，0为松开，1为按下
	int isOpenWav = 0; //判断是否打开了wav文件
private:
	void testDraw();
	void testDraw_2();
	boolean checkIsOpenWav(int isOpenWav);
private slots:
	void onClickChooseWavFile();
	void onClickOpenfilterWindow();
	void onClickOpenrecordWindow();
	void onClickOpenspectrumWindow();
	void startAssistant();
	void my_mouseMoveEvent(QMouseEvent * event);
	void my_mousePressEvent(QMouseEvent* event);
	void my_mouseReleaseEvent(QMouseEvent* event);
	void onClickZoomIn();
	void onClickZoomOut();
	void onClickReset();
	void onClickPlayWav();
	/*void onClickOpenSpectrogramWindow();*/
	void onClickOpenfreqRespWindow();
	void onClickOpenWinFuncWindow();	
};
