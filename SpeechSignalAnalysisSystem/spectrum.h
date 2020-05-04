#pragma once

#include <QWidget>
#include "ui_spectrum.h"
#include<fftw3.h>
#include<QDebug>
#include"wavinfo.h"
class Spectrum : public QMainWindow
{
	Q_OBJECT

public:
	Spectrum(QWidget *parent = Q_NULLPTR);
	Spectrum(QWidget *parent, WavInfo *m_wavinfo);
	~Spectrum();
	
private:
	Ui::Spectrum ui;
	QCPGraph *pGraph;
	WavInfo *wavinfo;
	fftw_complex *out;
	fftw_plan p;
private slots:
	void onClickZoomIn();

	void onClickZoomOut();

	void onClickReset();
};
