#pragma once

#include <QWidget>
#include "ui_filter.h"

class Filter : public QMainWindow
{
	Q_OBJECT

public:
	Filter(QWidget *parent = Q_NULLPTR);
	~Filter();

private:
	Ui::Filter ui;
};
