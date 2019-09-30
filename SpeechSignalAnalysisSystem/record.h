#pragma once

#include <QWidget>
#include "ui_record.h"
#include<QDebug>
#include<QTimer>
#include<QAudioRecorder>
#include<QUrl>
class Record : public QMainWindow
{
	Q_OBJECT

public:
	Record(QWidget *parent = Q_NULLPTR);
	void onClickStop();

private:
	Ui::Record ui;
	//QFile *outputFile;
	//QAudioInput* audio;

	QAudioRecorder *audioRecorder;
	bool is_start, is_pause;
private slots:
	void onClickPlay();
	void stopRecording();
};
