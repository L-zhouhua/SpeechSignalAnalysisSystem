#pragma once

#include <QWidget>
#include "ui_finalmainwindow.h"

class FinalMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	FinalMainWindow(QWidget *parent = Q_NULLPTR);
	~FinalMainWindow();

private:
	Ui::finalMainWindow ui;
};
