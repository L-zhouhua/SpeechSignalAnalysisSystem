#pragma once

#include <QWidget>
#include "ui_filter.h"

class FilterM : public QMainWindow
{
	Q_OBJECT

public:
	FilterM(QWidget *parent = Q_NULLPTR);
	~FilterM();

private:
	Ui::Filter ui;
};
