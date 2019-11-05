#include "freqyres.h"
#include"iir.h"
#include"filter.h"

FreqyRes::FreqyRes(QWidget *parent, WavInfo *m_wavinfo)
	: QWidget(parent)
{
	ui.setupUi(this);
	wavinfo = new WavInfo();
	wavinfo = m_wavinfo;
	FilterType ft = T_LP;
	a = new double[wavinfo->length];
	b = new double[wavinfo->length];
	double *c = new double[0];
	c[0] = 0.5;
	butter(2, c, ft, b, a, 1);
	for (int i = 0; i < 10; i++)
	{
		qDebug() << "a:" << a[i] << "b:" << b[i];
	}
	int an = sizeof(a) / sizeof(double);
	int bn = sizeof(b) / sizeof(double);
	complex<double> *iirfre = iirfreqz(b, bn, a, an, 512);
}

FreqyRes::~FreqyRes()
{
}
