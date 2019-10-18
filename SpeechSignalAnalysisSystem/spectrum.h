#pragma once

#include <QWidget>
#include "ui_spectrum.h"
#include<fftw3.h>
#include<QDebug>
class Spectrum : public QMainWindow
{
	Q_OBJECT

public:
	Spectrum(QWidget *parent = Q_NULLPTR);
	~Spectrum();
	void getFramesOnWindow(int m_frames);
	void getBufOnMainWindow(double *m_buf);
	void getLengthOnMainWindow(int m_length);
	void getSamplerateOnMainWindow(int m_samplerate);
	void drawSpecturm();
private:
	Ui::Spectrum ui;
	QCPGraph *pGraph;
	double *buf = NULL;
	int length;
	int frames;
	double samplerate;  
	fftw_complex *out;
	fftw_plan p;
private slots:
};
