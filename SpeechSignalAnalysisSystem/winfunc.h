#pragma once

#include <QWidget>
#include "ui_winfunc.h"

class WinFunc : public QWidget
{
	Q_OBJECT

public:
	WinFunc(QWidget *parent = Q_NULLPTR);
	~WinFunc();
private:
	Ui::winFunc ui;
	QCPGraph *pGraph;
	QCPGraph *pGraph2;
	double *w;
	double *win; //´°¿ÚÖµ
	int ifft = 512; //ifft=512
	int n = 100; //n=100
private:
	void DrawDB();
private slots:
	void onClickDrawWinFunc();
	void onClickDrawKai();
};
