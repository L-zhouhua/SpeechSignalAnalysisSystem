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
	double *buf = NULL;       //������
	int samplerate; //�����ʣ�ÿ�������������λHz��
	int frames;     //ÿ�������Ĳ�����
	int length;     //�ܲ����㣨frame*channels��
	int channels;   //������
	double duration;   //����
	
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
