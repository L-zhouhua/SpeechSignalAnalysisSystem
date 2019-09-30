#include "record.h"

Record::Record(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	audioRecorder = new QAudioRecorder(this);

	connect(ui.startRecord_but, SIGNAL(clicked()), this, SLOT(onClickPlay()));
	/*去掉对话框最大化*/
	this->setFixedSize(this->width(), this->height());

	/*输入设备*/
	ui.audioDeviceBox->addItem(QString::fromLocal8Bit("默认"), QVariant(QString()));
	for (auto &device : audioRecorder->audioInputs())
	{
		ui.audioDeviceBox->addItem(device, QVariant(device));
	}
	/*设置容器*/
	ui.containerBox->addItem(QString::fromLocal8Bit("默认"), QVariant(QString()));
	for (auto &containerName : audioRecorder->supportedContainers())
	{
		qDebug() << containerName << endl;
		ui.containerBox->addItem(containerName, QVariant(containerName));
	}
	/*设置采样率*/
	ui.sampleRateBox->addItem(QString::fromLocal8Bit("默认"), QVariant(0));
	for (int sampleRete : audioRecorder->supportedAudioSampleRates())
	{
		ui.sampleRateBox->addItem(QString::number(sampleRete), QVariant(sampleRete));
	}
	/*设置编码器*/
	ui.audioCodecBox->addItem(QString::fromLocal8Bit("默认"), QVariant(QString()));
	for (auto &codecName : audioRecorder->supportedAudioCodecs()) {
		ui.audioCodecBox->addItem(codecName, QVariant(codecName));
	}
	/*设置声音通道数*/
	ui.channelsBox->addItem(QString::fromLocal8Bit("默认"), QVariant(-1));
	ui.channelsBox->addItem(QStringLiteral("1"), QVariant(1));
	ui.channelsBox->addItem(QStringLiteral("2"), QVariant(2));
	ui.channelsBox->addItem(QStringLiteral("4"), QVariant(4));
	/*设置音质*/
	ui.qualitySlider->setRange(0, int(QMultimedia::VeryHighQuality));
	ui.qualitySlider->setValue(int(QMultimedia::NormalQuality));
}

void Record::onClickPlay()
{
	if (!audioRecorder->setOutputLocation(QUrl::fromLocalFile("test1.wav"))) {

		qDebug() << "文件保存有毒！退出！";
		exit(1);
	}

	audioRecorder->setAudioInput("麦克风阵列(Realtek High Definition Audio)");
	QAudioEncoderSettings settings;
	settings.setCodec("audio/pcm");
	settings.setSampleRate(16000); 
	settings.setBitRate(128000);
	settings.setQuality(QMultimedia::HighQuality);
	
	settings.setEncodingMode(QMultimedia::ConstantBitRateEncoding);
	audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings());
	audioRecorder->record();
	qDebug() << QString::fromLocal8Bit("开始录音...") << endl;
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
	qDebug() << QString::fromLocal8Bit("停止录音") << endl;
}
void Record::onClickStop()
{

}