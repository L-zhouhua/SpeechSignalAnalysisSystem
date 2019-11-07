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
private slots:
	void onClickDrawRect();
	void onClickDrawHan();
	void onClickDrawHam();
	void onClickDrawBm();
	void onClickDrawBmH();
	void onClickDrawKai();
};
