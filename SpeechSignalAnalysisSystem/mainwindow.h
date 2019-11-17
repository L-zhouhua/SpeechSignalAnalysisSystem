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
