#pragma once

#include <QWidget>
#include "ui_record.h"
#include<QDebug>
#include<QAudioRecorder>
#include<QUrl>
#include<QMediaRecorder>
#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>
class Record : public QMainWindow
{
	Q_OBJECT

public:
	Record(QWidget *parent = Q_NULLPTR);
private:
	Ui::Record ui;
	//QFile *outputFile;
	//QAudioInput* audio;

	QAudioRecorder *audioRecorder;
	bool outputLocationSet = false;

private slots:
	void onClickRecord();
	void stopRecording();
	void updateProgress(qint64 duration);
	void updateStatus(QMediaRecorder::Status status);
	void onStateChanged(QMediaRecorder::State state);
	void displayErrorMessage();
	void onClickPause();
	void setOutputLocation();
};
