#include "winfunc.h"
#include"winfun.h"

WinFunc::WinFunc(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.rect_but, SIGNAL(clicked()), this, SLOT(onClickDrawRect()));
	connect(ui.han_but, SIGNAL(clicked()), this, SLOT(onClickDrawHan()));
	connect(ui.ham_but, SIGNAL(clicked()), this, SLOT(onClickDrawHam()));
	connect(ui.bm_but, SIGNAL(clicked()), this, SLOT(onClickDrawBm()));
	connect(ui.bmh_but, SIGNAL(clicked()), this, SLOT(onClickDrawBmH()));
	connect(ui.kai_but, SIGNAL(clicked()), this, SLOT(onClickDrawKai()));
	pGraph = ui.winFunc_wid->addGraph();
	pGraph->setPen(QPen(QColor(16, 78, 139)));

}
void WinFunc::onClickDrawRect()
{
	double *w = new double[3];
	int n = 100;
	double *rect = getwincoef<double>(n, w, RECTWIN);
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = rect[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setBrush(QBrush(QColor(16 ,78, 139)));
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	ui.winFunc_wid->yAxis->setRange(0, 2);
	ui.winFunc_wid->replot();
}
void WinFunc::onClickDrawHan()
{
	double *w = new double[3];
	int n = 100;
	double *rect = getwincoef<double>(n, w, HANNING);
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = rect[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setBrush(QBrush(QColor(16, 78, 139)));
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	ui.winFunc_wid->yAxis->setRange(0, 2);
	ui.winFunc_wid->replot();
}
void WinFunc::onClickDrawHam()
{
	double *w = new double[3];
	int n = 100;
	double *rect = getwincoef<double>(n, w, HAMMING);
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = rect[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setBrush(QBrush(QColor(16, 78, 139)));
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	ui.winFunc_wid->yAxis->setRange(0, 2);
	ui.winFunc_wid->replot();
}
void WinFunc::onClickDrawBm()
{
	double *w = new double[3];
	int n = 100;
	double *rect = getwincoef<double>(n, w, BLACKMAN);
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = rect[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setBrush(QBrush(QColor(16, 78, 139)));
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	ui.winFunc_wid->yAxis->setRange(0, 2);
	ui.winFunc_wid->replot();
}
void WinFunc::onClickDrawBmH()
{
	double *w = new double[3];
	int n = 100;
	double *rect = getwincoef<double>(n, w, BLACKMANHARISS);
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = rect[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setBrush(QBrush(QColor(16, 78, 139)));
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	ui.winFunc_wid->yAxis->setRange(0, 2);
	ui.winFunc_wid->replot();
}
void WinFunc::onClickDrawKai()
{
	double *w = new double[3];
	w[0] = 0.5;
	w[1] = 0.5;
	w[2] = 0.8;
	int n = 100;
	double *rect = getwincoef<double>(n, w, KAISER);
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = rect[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setBrush(QBrush(QColor(16, 78, 139)));
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	ui.winFunc_wid->yAxis->setRange(0, 2);
	ui.winFunc_wid->replot();
}
WinFunc::~WinFunc()
{
}
