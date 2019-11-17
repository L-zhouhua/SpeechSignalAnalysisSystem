#include "freqyres.h"
#include"iir.h"
#include"fir.h"
#include"filter.h"
#include<QDebug>
#define pi 3.1415926

FreqyRes::FreqyRes(QWidget *parent, WavInfo *m_wavinfo)
	: QWidget(parent)
{
	ui.setupUi(this);
	//iir
	connect(ui.affirm_but_LP, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	connect(ui.affirm_but_HP, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	connect(ui.affirm_but_BP, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	connect(ui.affirm_but_BS, SIGNAL(clicked()), this, SLOT(onClickAffirm()));
	//fir
	connect(ui.affirm_but_fir_LP, SIGNAL(clicked()), this, SLOT(onClickfirAffirm()));
	connect(ui.affirm_but_fir_HP, SIGNAL(clicked()), this, SLOT(onClickfirAffirm()));
	connect(ui.affirm_but_fir_BP, SIGNAL(clicked()), this, SLOT(onClickfirAffirm()));
	connect(ui.affirm_but_fir_BS, SIGNAL(clicked()), this, SLOT(onClickfirAffirm()));

	//监控下拉框，实现选择Kaiser窗时的参数控件激活还是没激活状态
	connect(ui.winfunc_box_LP, SIGNAL(currentIndexChanged(int)), this, SLOT(onClickChangeLPEdit()));
	connect(ui.winfunc_box_HP, SIGNAL(currentIndexChanged(int)), this, SLOT(onClickChangeHPEdit()));
	connect(ui.winfunc_box_BP, SIGNAL(currentIndexChanged(int)), this, SLOT(onClickChangeBPEdit()));
	connect(ui.winfunc_box_BS, SIGNAL(currentIndexChanged(int)), this, SLOT(onClickChangeBSEdit()));
	// iir1
	pGraph = ui.freqyres_widget->addGraph();
	ui.freqyres_widget->yAxis->setLabel("dB");
	ui.freqyres_widget->xAxis->setLabel(QString::fromLocal8Bit("π"));
	//ui.freqyres_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	// iir2
	pGraph2 = ui.freqyres_widget_2->addGraph();
	ui.freqyres_widget_2->yAxis->setLabel("dB");
	ui.freqyres_widget_2->xAxis->setLabel(QString::fromLocal8Bit("π"));
	ui.freqyres_widget_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	pGraph2->setPen(QPen(QColor(32, 178, 170)));
	//fir
	pGraph3 = ui.freqyres_widget_fir->addGraph();
	ui.freqyres_widget_fir->yAxis->setLabel("dB");
	ui.freqyres_widget_fir->xAxis->setLabel(QString::fromLocal8Bit("π"));
	pGraph2->setPen(QPen(QColor(32, 178, 170)));

	wavinfo = new WavInfo();
	wavinfo = m_wavinfo;
}
void FreqyRes::onClickChangeLPEdit()
{
	if (ui.winfunc_box_LP->currentIndex() == 5)
	{
		ui.kai_lab_LP->setEnabled(true);
		ui.kai_edit_LP->setEnabled(true);
	}
	else
	{
		ui.kai_lab_LP->setEnabled(false);
		ui.kai_edit_LP->setEnabled(false);
	}

}
void FreqyRes::onClickChangeHPEdit()
{
	if (ui.winfunc_box_HP->currentIndex() == 5)
	{
		ui.kai_lab_HP->setEnabled(true);
		ui.kai_edit_HP->setEnabled(true);
	}
	else
	{
		ui.kai_lab_HP->setEnabled(false);
		ui.kai_edit_HP->setEnabled(false);
	}
}
void FreqyRes::onClickChangeBPEdit()
{
	if (ui.winfunc_box_BP->currentIndex() == 5)
	{
		ui.kai_lab_BP->setEnabled(true);
		ui.kai_edit_BP->setEnabled(true);
	}
	else
	{
		ui.kai_lab_BP->setEnabled(false);
		ui.kai_edit_BP->setEnabled(false);
	}
}
void FreqyRes::onClickChangeBSEdit()
{
	if (ui.winfunc_box_BS->currentIndex() == 5)
	{
		ui.kai_lab_BS->setEnabled(true);
		ui.kai_edit_BS->setEnabled(true);
	}
	else
	{
		ui.kai_lab_BS->setEnabled(false);
		ui.kai_edit_BS->setEnabled(false);
	}
}
void FreqyRes::onClickAffirm()
{
	double *a;
	double *b;
	int type_index = ui.type_toolBox->currentIndex();//toolBox下标
	int order;  //阶数
	double *para = new double[2];  //参数
	QString type;
	FilterType filter_type; //滤波器类型
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
	double *db = convert2db(mag, 512);
	//int iirn = sizeof(iirfre) / sizeof(double);
	QVector<double> x(512), y(512);
	for (int i = 0; i < 512; i++)
	{
		x[i] = i / 512.0 / pi;
		y[i] = db[i];
	}
	ui.freqyres_widget->graph()->data()->clear();
	ui.freqyres_widget->graph(0)->setData(x, y); //设置xy轴
	ui.freqyres_widget->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
	ui.freqyres_widget->replot();//重绘

	//iir频率响应 Ⅱ 
	complex<double> *ifft = iirfreqz(b, bn, a, an, 512);
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			qDebug() << i << "imag:" << ifft[i].imag() << "real:" << ifft[i].real();
	}*/
	double *mag2 = phase(ifft, 512);
	//double *db2 = convert2db(mag2, 512);
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
void FreqyRes::onClickfirAffirm()
{
	int type_index = ui.type_toolBox_fir->currentIndex();//toolBox下标
	int order;  //阶数
	double *para = new double[3];  //参数
	QString type;
	FilterType filter_type; //滤波器类型
	WinType wintype;   //窗口类型
	if (type_index == 0)
	{
		filter_type = T_LP;
		order = ui.order_edit_fir_LP->text().toInt();
		para[0] = ui.parameter_edit_fir_LP->text().toDouble();
		if (ui.winfunc_box_LP->currentIndex()==0)
			wintype = RECTWIN;
		else if (ui.winfunc_box_LP->currentIndex()==1)
			wintype = HANNING;
		else if (ui.winfunc_box_LP->currentIndex() == 2)
			wintype  = HAMMING;
		else if (ui.winfunc_box_LP->currentIndex() == 3)
			wintype = BLACKMAN;
		else if (ui.winfunc_box_LP->currentIndex() == 4)
			wintype = BLACKMANHARISS;
		else if (ui.winfunc_box_LP->currentIndex() == 5) {
			wintype = KAISER;
			para[2] = ui.kai_edit_LP->text().toDouble();
		}
			
	}
	else if (type_index == 1)
	{
		filter_type = HP;
		order = ui.order_edit_fir_HP->text().toInt();
		para[0] = ui.parameter_edit_fir_HP->text().toDouble();
		if (ui.winfunc_box_HP->currentIndex() == 0)
			wintype = RECTWIN;
		else if (ui.winfunc_box_HP->currentIndex() == 1)
			wintype = HANNING;
		else if (ui.winfunc_box_HP->currentIndex() == 2)
			wintype = HAMMING;
		else if (ui.winfunc_box_HP->currentIndex() == 3)
			wintype = BLACKMAN;
		else if (ui.winfunc_box_HP->currentIndex() == 4)
			wintype = BLACKMANHARISS;
		else if (ui.winfunc_box_HP->currentIndex() == 5) {
			para[2] = ui.kai_edit_HP->text().toDouble();
			wintype = KAISER;
		}
			
	}
	else if (type_index == 2)
	{
		filter_type = BP;
		order = ui.order_edit_fir_BP->text().toInt();
		para[0] = ui.parameter_edit_fir_BP->text().toDouble();
		para[1] = ui.parameter_edit_2_fir__BP->text().toDouble();
		if (ui.winfunc_box_BP->currentIndex() == 0)
			wintype = RECTWIN;
		else if (ui.winfunc_box_BP->currentIndex() == 1)
			wintype = HANNING;
		else if (ui.winfunc_box_BP->currentIndex() == 2)
			wintype = HAMMING;
		else if (ui.winfunc_box_BP->currentIndex() == 3)
			wintype = BLACKMAN;
		else if (ui.winfunc_box_BP->currentIndex() == 4)
			wintype = BLACKMANHARISS;
		else if (ui.winfunc_box_BP->currentIndex() == 5) {
			para[2] = ui.kai_edit_BP->text().toDouble();
			wintype = KAISER;
		}
	}
	else if (type_index == 3)
	{
		filter_type = BS;
		order = ui.order_edit_fir_BS->text().toInt();
		para[0] = ui.parameter_edit_fir_BS->text().toDouble();
		para[1] = ui.parameter_edit_2_fir_BS->text().toDouble();
		if (ui.winfunc_box_BS->currentIndex() == 0)
			wintype = RECTWIN;
		else if (ui.winfunc_box_BS->currentIndex() == 1)
			wintype = HANNING;
		else if (ui.winfunc_box_BS->currentIndex() == 2)
			wintype = HAMMING;
		else if (ui.winfunc_box_BS->currentIndex() == 3)
			wintype = BLACKMAN;
		else if (ui.winfunc_box_BS->currentIndex() == 4)
			wintype = BLACKMANHARISS;
		else if (ui.winfunc_box_BS->currentIndex() == 5) {
			para[2] = ui.kai_edit_BS->text().toDouble();
			wintype = KAISER;
		}
	}
	
	double *fir = new double[order];
	fir = fir1(order, para, filter_type, wintype);
	complex<double> *firfre = firfreqz(fir, order, 512);
	for (int i = 0; i < 20; i++)
	{
		qDebug() << i << "imag:" << firfre[i].imag() << "real:" << firfre[i].real();
	}
	double *mag = magnitude(firfre, 512);
	double *db = convert2db(mag, 512);
	QVector<double> x(512), y(512);
	for (int i = 0; i < 512; i++)
	{
		x[i] = i / 512.0 / pi;
		y[i] = db[i];
	}
	ui.freqyres_widget_fir->graph()->data()->clear();
	ui.freqyres_widget_fir->graph(0)->setData(x, y);
	ui.freqyres_widget_fir->rescaleAxes(true);
	ui.freqyres_widget_fir->replot();

	//添加右边数据
	ui.type_lab_fir->setText(type);
	ui.order_lab_fir->setText(QString::number(order));
	ui.parameter_lab_fir->setText(QString::number(para[0]));
	if (para[1] < 0.00000001)
		ui.parameter_lab_fir_2->setText("None");
	else
		ui.parameter_lab_fir_2->setText(QString::number(para[1]));

	ui.plainTextEdit_fir->clear();
	ui.plainTextEdit_fir->appendPlainText("a:");
	for (int i = 0; i < order; i++)
	{
		ui.plainTextEdit_fir->appendPlainText(QString::number(fir[i]));
	}

	free(fir);
	fir = NULL;
}
FreqyRes::~FreqyRes()
{
}
