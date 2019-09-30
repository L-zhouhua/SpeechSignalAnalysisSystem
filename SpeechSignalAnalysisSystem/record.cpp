#include "record.h"

Record::Record(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	audioRecorder = new QAudioRecorder(this);

	connect(ui.startRecord_but, SIGNAL(clicked()), this, SLOT(onClickPlay()));
	/*ȥ���Ի������*/
	this->setFixedSize(this->width(), this->height());

	/*�����豸*/
	ui.audioDeviceBox->addItem(QString::fromLocal8Bit("Ĭ��"), QVariant(QString()));
	for (auto &device : audioRecorder->audioInputs())
	{
		ui.audioDeviceBox->addItem(device, QVariant(device));
	}
	/*��������*/
	ui.containerBox->addItem(QString::fromLocal8Bit("Ĭ��"), QVariant(QString()));
	for (auto &containerName : audioRecorder->supportedContainers())
	{
		qDebug() << containerName << endl;
		ui.containerBox->addItem(containerName, QVariant(containerName));
	}
	/*���ò�����*/
	ui.sampleRateBox->addItem(QString::fromLocal8Bit("Ĭ��"), QVariant(0));
	for (int sampleRete : audioRecorder->supportedAudioSampleRates())
	{
		ui.sampleRateBox->addItem(QString::number(sampleRete), QVariant(sampleRete));
	}
	/*���ñ�����*/
	ui.audioCodecBox->addItem(QString::fromLocal8Bit("Ĭ��"), QVariant(QString()));
	for (auto &codecName : audioRecorder->supportedAudioCodecs()) {
		ui.audioCodecBox->addItem(codecName, QVariant(codecName));
	}
	/*��������ͨ����*/
	ui.channelsBox->addItem(QString::fromLocal8Bit("Ĭ��"), QVariant(-1));
	ui.channelsBox->addItem(QStringLiteral("1"), QVariant(1));
	ui.channelsBox->addItem(QStringLiteral("2"), QVariant(2));
	ui.channelsBox->addItem(QStringLiteral("4"), QVariant(4));
	/*��������*/
	ui.qualitySlider->setRange(0, int(QMultimedia::VeryHighQuality));
	ui.qualitySlider->setValue(int(QMultimedia::NormalQuality));
}

void Record::onClickPlay()
{
	if (!audioRecorder->setOutputLocation(QUrl::fromLocalFile("test1.wav"))) {

		qDebug() << "�ļ������ж����˳���";
		exit(1);
	}

	audioRecorder->setAudioInput("��˷�����(Realtek High Definition Audio)");
	QAudioEncoderSettings settings;
	settings.setCodec("audio/pcm");
	settings.setSampleRate(16000); 
	settings.setBitRate(128000);
	settings.setQuality(QMultimedia::HighQuality);
	
	settings.setEncodingMode(QMultimedia::ConstantBitRateEncoding);
	audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings());
	audioRecorder->record();
	qDebug() << QString::fromLocal8Bit("��ʼ¼��...") << endl;
	/*QEventLoop loop;
	QTimer::singleShot(5 * 1000, &loop, SLOT(quit()));
	loop.exec();*/
	QTimer::singleShot(5000, this, SLOT(stopRecording()));
	//audioRecorder->stop();

	//delete audioRecorder;

	//qDebug() << "over";
}
void::Record::stopRecording()
{
	audioRecorder->stop();
	//outputFile->close();
	qDebug() << QString::fromLocal8Bit("ֹͣ¼��") << endl;
}
void Record::onClickStop()
{

}