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
	QCPGraph *pGraph2;
	QCPGraph *pGraph3;
	WavInfo *wavinfo;
private slots:
	void onClickAffirm();
	void onClickfirAffirm();
	void onClickChangeLPEdit();
	void onClickChangeHPEdit();
	void onClickChangeBPEdit();
	void onClickChangeBSEdit();
};
