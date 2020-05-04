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
	QString filename; //�ļ�·��
	QCPGraph *pGraph; //ͼ��
	QCPGraph *pGraph2;
	SF_INFO sf_info;  //��ȡ�������ص�����
	SNDFILE *snd_file;  //��ȡ����
	WavInfo *wavinfo=NULL;  //���������࣬���ڴ�����������
	QCPColorMap *pColorMap = NULL; //���ڻ�������ͼ
	QCPItemPixmap *pixmap;//���ڻ�������ͼ
	QCPAxis *xAxis;//����ͼx��
	QCPAxis *yAxis;//����ͼy��
	QCPItemTracer *tracer;
	Assistant *assistant; //�����ĵ�
	//QCPItemStraightLine *line = NULL;
	//QCPItemStraightLine *line_2 = NULL;
	int mousePressFlag = 0;//�ж�������״̬��0Ϊ�ɿ���1Ϊ����
	int isOpenWav = 0; //�ж��Ƿ����wav�ļ�
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
