#pragma once

#include <QWidget>
#include "ui_spectrum.h"

class Spectrum : public QMainWindow
{
	Q_OBJECT

public:
	Spectrum(QWidget *parent = Q_NULLPTR);
	~Spectrum();

private:
	Ui::Spectrum ui;
};
