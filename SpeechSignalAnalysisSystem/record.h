#pragma once

#include <QWidget>
#include "ui_record.h"

class Record : public QMainWindow
{
	Q_OBJECT

public:
	Record(QWidget *parent = Q_NULLPTR);
	~Record();

private:
	Ui::Record ui;
};
