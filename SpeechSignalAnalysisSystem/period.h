#pragma once

#include <QWidget>
#include "ui_period.h"

class Period : public QMainWindow
{
	Q_OBJECT

public:
	Period(QWidget *parent = Q_NULLPTR);
	~Period();

private:
	Ui::Period ui;
};
