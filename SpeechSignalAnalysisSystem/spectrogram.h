#pragma once

#include <QWidget>
#include "ui_spectrogram.h"
#include"winfun.h"
#include"wavinfo.h"
#include"filter.h"
class Spectrogram : public QWidget
{
	Q_OBJECT

public:
	Spectrogram(QWidget *parent = Q_NULLPTR);
	Spectrogram(QWidget * parent, WavInfo * m_wavinfo);
	void testDraw();
	~Spectrogram();

private:
	Ui::Spectrogram ui;
	WavInfo *wavinfo;
	QCPGraph *pGraph;

	QCPColorMap *pColorMap;

	QCPItemPixmap *pixmap;
};