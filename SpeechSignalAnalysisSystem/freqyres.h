#pragma once

#include <QWidget>
#include "ui_freqyres.h"
#include"wavinfo.h"
class FreqyRes : public QWidget
{
	Q_OBJECT

public:
	FreqyRes(QWidget *parent = Q_NULLPTR);
	FreqyRes(QWidget *parent,WavInfo *m_wavinfo);
	~FreqyRes();

private:
	Ui::FreqyRes ui;
	QCPGraph *pGraph;
	WavInfo *wavinfo;
	double *a;
	double *b;
};
