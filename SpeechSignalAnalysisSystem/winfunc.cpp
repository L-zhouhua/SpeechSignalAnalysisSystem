#include "winfunc.h"
#include"winfun.h"
#include"filter.h"
#define pi 3.1415926
WinFunc::WinFunc(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->resize(QSize(2800, 1400)); //���ó�ʼ���ڴ�С
	connect(ui.winfunc_Box, SIGNAL(currentIndexChanged(int)), this, SLOT(onClickDrawWinFunc()));
	connect(ui.kai_but, SIGNAL(clicked()), this, SLOT(onClickDrawKai()));
	w = new double[3];
	pGraph = ui.winFunc_wid->addGraph();
	pGraph->setPen(QPen(QColor(16, 78, 139)));
	ui.winFunc_wid->xAxis->setLabel(QString::fromLocal8Bit("x"));
	ui.winFunc_wid->yAxis->setLabel(QString::fromLocal8Bit("y"));

	pGraph2 = ui.winFunc_wid_2->addGraph();
	pGraph2->setPen(QPen(QColor(16, 78, 139)));
	ui.winFunc_wid_2->xAxis->setLabel(QString::fromLocal8Bit("Ƶ��(Hz)"));
	ui.winFunc_wid_2->yAxis->setLabel(QString::fromLocal8Bit("����(dB)"));

	//��ȡqss�ļ���������
	QFile file("winfuncStyle.qss");
	file.open(QFile::ReadOnly);
	QTextStream filetext(&file);
	QString stylesheet = filetext.readAll();
	this->setStyleSheet(stylesheet);
	file.close();
}
void WinFunc::onClickDrawKai()
{
	w[2] = ui.kai_edit->text().toDouble();
	win = getwincoef<double>(n, w, KAISER);
	DrawDB();
}
void WinFunc::onClickDrawWinFunc()
{
	QString box_text = ui.winfunc_Box->currentText(); //��ȡ�������ı�
	if (box_text == QString::fromLocal8Bit("���δ�"))
	{
		win = getwincoef<double>(n, w, RECTWIN);
		ui.kai_edit->setEnabled(false);
		ui.kai_lab->setEnabled(false);
		ui.kai_but->setEnabled(false);
	}
	else if (box_text == QString::fromLocal8Bit("hanning��"))
	{
		win = getwincoef<double>(n, w, HANNING);
		ui.kai_edit->setEnabled(false);
		ui.kai_lab->setEnabled(false);
		ui.kai_but->setEnabled(false);
	}
	else if (box_text == QString::fromLocal8Bit("hamming��"))
	{
		win = getwincoef<double>(n, w, HAMMING);
		ui.kai_edit->setEnabled(false);
		ui.kai_lab->setEnabled(false);
		ui.kai_but->setEnabled(false);
	}
	else if (box_text == QString::fromLocal8Bit("Blackman��"))
	{
		win = getwincoef<double>(n, w, BLACKMAN);
		ui.kai_edit->setEnabled(false);
		ui.kai_lab->setEnabled(false);
		ui.kai_but->setEnabled(false);
	}
	else if (box_text == QString::fromLocal8Bit("BlackmanHarris��"))
	{
		win = getwincoef<double>(n, w, BLACKMANHARISS);
		ui.kai_edit->setEnabled(false);
		ui.kai_lab->setEnabled(false);
		ui.kai_but->setEnabled(false);
	}
	DrawDB();
	if (box_text == QString::fromLocal8Bit("Kaiser��"))
	{
		ui.kai_edit->setEnabled(true);
		ui.kai_lab->setEnabled(true);
		ui.kai_but->setEnabled(true);
	}
}
void WinFunc::DrawDB()
{
	double *winfre; //����Ƶ��
	double *windb; //ת��Ϊ����
	complex<double> *fre = firfreqz(win, 30, ifft); //����30
	winfre = magnitude(fre, ifft);
	windb = convert2db(winfre, ifft);

	//���ں���ͼ
	QVector<double> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = win[i];
	}
	ui.winFunc_wid->graph(0)->data()->clear();
	ui.winFunc_wid->graph(0)->setData(x, y);
	ui.winFunc_wid->rescaleAxes();
	/*ui.winFunc_wid->yAxis->setRange(0, 2);*/
	ui.winFunc_wid->replot();

	//���ڹ�����
	QVector<double> x2(ifft), y2(ifft);
	for (int i = 0; i < ifft; i++)
	{
		x2[i] = i / (double)ifft;
		y2[i] = windb[i];
	}
	ui.winFunc_wid_2->graph(0)->data()->clear();
	ui.winFunc_wid_2->graph(0)->setData(x2, y2);
	ui.winFunc_wid_2->rescaleAxes();
	ui.winFunc_wid_2->replot();
}
WinFunc::~WinFunc()
{
}
