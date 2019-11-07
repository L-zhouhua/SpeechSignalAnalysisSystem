#include "freqyres.h"
#include"iir.h"
#include"filter.h"
#include<QDebug>
#define pi 3.1415926

FreqyRes::FreqyRes(QWidget *parent, WavInfo *m_wavinfo)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.affirm_but_LP, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	connect(ui.affirm_but_HP, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	connect(ui.affirm_but_BP, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	connect(ui.affirm_but_BS, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	
	// 1
	pGraph = ui.freqyres_widget->addGraph();
	ui.freqyres_widget->yAxis->setLabel("dB");
	ui.freqyres_widget->xAxis->setLabel(QString::fromLocal8Bit("π"));
	//ui.freqyres_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	// 2
	pGraph2 = ui.freqyres_widget_2->addGraph();
	ui.freqyres_widget_2->yAxis->setLabel("dB");
	ui.freqyres_widget_2->xAxis->setLabel(QString::fromLocal8Bit("π"));
	//ui.freqyres_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	pGraph2->setPen(QPen(QColor(32, 178, 170)));

	wavinfo = new WavInfo();
	wavinfo = m_wavinfo;
}
void FreqyRes::onClickAffirm()
{
	double *a;
	double *b;
	int type_index = ui.type_toolBox->currentIndex();
	int order;  //阶数
	double *para = new double[2];  //参数
	QString type;
	FilterType filter_type; //类型
	int an, bn;
	if (type_index == 0)
	{
		filter_type = T_LP;
		order = ui.order_edit_LP->text().toInt(); 
		para[0] = ui.parameter_edit_LP->text().toDouble();
		a = new double[order + 1];
		b = new double[order + 1];
		type = QString::fromLocal8Bit("低通滤波器");
		an = order + 1;
		bn = order + 1;
	}
	else if (type_index == 1)
	{
		filter_type = HP;
		order = ui.order_edit_HP->text().toInt();
		para[0] = ui.parameter_edit_HP->text().toDouble();
		a = new double[order + 1];
		b = new double[order + 1];
		type = QString::fromLocal8Bit("高通滤波器");
		an = order + 1;
		bn = order + 1;
	}
	else if (type_index == 2)
	{
		filter_type = BP;
		order = ui.order_edit_BP->text().toInt();
		para[0] = ui.parameter_edit_BP->text().toDouble();
		para[1] = ui.parameter_edit_2_BP->text().toDouble();
		a = new double[2*order + 1];
		b = new double[2*order + 1];
		type = QString::fromLocal8Bit("带通滤波器");
		an = 2*order + 1;
		bn = 2*order + 1;
	}
	else if (type_index == 3)
	{
		filter_type = BS;
		order = ui.order_edit_BS->text().toInt();
		para[0] = ui.parameter_edit_BS->text().toDouble();
		para[1] = ui.parameter_edit_2_BS->text().toDouble();
		a = new double[2*order + 1];
		b = new double[2*order + 1];
		type = QString::fromLocal8Bit("带阻滤波器");
		an = 2*order + 1;
		bn = 2*order + 1;
	}
	butter(order, para, filter_type, b, a, 1);
	/*for (int i = 0; i < 10; i++)
	{
		qDebug() << "a:" << a[i] << "b:" << b[i];
	}*/

	//iir频率响应 Ⅰ
	complex<double> *iirfre = iirfreqz(b, bn, a, an, 512);
	double *mag = magnitude(iirfre, 512);
	//int iirn = sizeof(iirfre) / sizeof(double);
	QVector<double> x(512), y(512);
	for (int i = 0; i < 512; i++)
	{
		x[i] = i / 512.0 / pi;
		y[i] = mag[i];
	}
	ui.freqyres_widget->graph()->data()->clear();
	ui.freqyres_widget->graph(0)->setData(x, y); //设置xy轴
	ui.freqyres_widget->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
	ui.freqyres_widget->replot();//重绘

	//iir频率响应 Ⅱ 
	complex<double> *ifft = iirfreqz_fft(b, bn, a, an, 512);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			qDebug() << i << "imag:" << ifft[i].imag() << "real:" << ifft[i].real();
	}
	double *mag2 = magnitude(ifft, 512);
	QVector<double> x2(512), y2(512);
	for (int i = 0; i < 512; i++)
	{
		x2[i] = i / 512.0 / pi;
		y2[i] = mag2[i];
	}
	ui.freqyres_widget_2->graph()->data()->clear();
	ui.freqyres_widget_2->graph(0)->setData(x2, y2); //设置xy轴
	ui.freqyres_widget_2->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
	ui.freqyres_widget_2->replot();//重绘

	//添加右边数据
	ui.type_lab->setText(type);
	ui.order_lab->setText(QString::number(order));
	ui.parameter_lab->setText(QString::number(para[0]));
	if(para[1]<0.00000001)
		ui.parameter_lab_2->setText("None");
	else
		ui.parameter_lab_2->setText(QString::number(para[1]));

	ui.plainTextEdit->clear();
	ui.plainTextEdit->appendPlainText("a:");
	for (int i = 0; i < an; i++)
	{
		ui.plainTextEdit->appendPlainText(QString::number(a[i]));
	}
	ui.plainTextEdit->appendPlainText("\nb:");
	for (int i = 0; i <  an; i++)
	{
		ui.plainTextEdit->appendPlainText(QString::number(b[i]));
	}

	


	free(a);
	free(b);
	a = NULL;
	b = NULL;
}
FreqyRes::~FreqyRes()
{
}
