#include "record.h"

Record::Record(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	audioRecorder = new QAudioRecorder(this);

	connect(ui.startRecord_but, SIGNAL(clicked()), this, SLOT(onClickRecord()));
	connect(ui.pause_but, SIGNAL(clicked()), this, SLOT(onClickPause()));
	connect(ui.output_but, SIGNAL(clicked()), this, SLOT(setOutputLocation()));
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
	/*����λ��*/
	ui.bitrateBox->addItem(QString::fromLocal8Bit("Ĭ��"), QVariant(0));
	ui.bitrateBox->addItem(QStringLiteral("32000"), QVariant(32000));
	ui.bitrateBox->addItem(QStringLiteral("64000"), QVariant(64000));
	ui.bitrateBox->addItem(QStringLiteral("96000"), QVariant(96000));
	ui.bitrateBox->addItem(QStringLiteral("128000"), QVariant(128000));

	connect(audioRecorder, &QAudioRecorder::durationChanged, this, &Record::updateProgress);
	connect(audioRecorder, &QAudioRecorder::statusChanged, this, &Record::updateStatus);
	connect(audioRecorder, &QAudioRecorder::stateChanged, this, &Record::onStateChanged);
	connect(audioRecorder, QOverload<QMediaRecorder::Error>::of(&QAudioRecorder::error), this,
		&Record::displayErrorMessage);
}
/*��ʾ¼��ʱ��*/
void Record::updateProgress(qint64 duration)
{
	if (audioRecorder->error() != QMediaRecorder::NoError || duration < 2000)
		return;

	ui.statusbar->showMessage(QString::fromLocal8Bit("%1��").arg(duration / 1000));
}
/**/
void Record::updateStatus(QMediaRecorder::Status status)
{
	QString statusMessage;
	switch (status)
	{
	case QMediaRecorder::RecordingStatus:
		statusMessage = QString::fromLocal8Bit("������%1").arg(audioRecorder->actualLocation().toString());
		break;
	case QMediaRecorder::PausedStatus:
		//clearAudioLevels();
		statusMessage = QString::fromLocal8Bit("��ͣ");
		break;
	//case QMediaRecorder::UnloadedStatus:
	case QMediaRecorder::RecordingState:
	case QMediaRecorder::LoadedStatus:
		//clearAudioLevels();
		statusMessage = QString::fromLocal8Bit("����");
		break;
	default:
		break;
	}
	if (audioRecorder->error() == QMediaRecorder::NoError)
		ui.statusbar->showMessage(statusMessage);
}
void Record::onStateChanged(QMediaRecorder::State state)
{
	switch (state) {
	case QMediaRecorder::RecordingState:
		ui.startRecord_but->setText(QString::fromLocal8Bit("ֹͣ"));
		ui.pause_but->setText(QString::fromLocal8Bit("��ͣ"));
		break;
	case QMediaRecorder::PausedState:
		ui.startRecord_but->setText(QString::fromLocal8Bit("ֹͣ"));
		ui.pause_but->setText(QString::fromLocal8Bit("����"));
		break;
	case QMediaRecorder::StoppedState:
		ui.startRecord_but->setText(QString::fromLocal8Bit("¼��"));
		ui.pause_but->setText(QString::fromLocal8Bit("��ͣ"));
		break;
	}

	ui.pause_but->setEnabled(audioRecorder->state() != QMediaRecorder::StoppedState);
}
void Record::displayErrorMessage()
{
	ui.statusbar->showMessage(audioRecorder->errorString());
}
/*��ȡ��������ʹ�õ��豸*/
static QVariant boxValue(const QComboBox *box)
{
	int idx = box->currentIndex();
	if (idx == -1)
		return QVariant();

	return box->itemData(idx);
}
void Record::onClickRecord()
{
	if (audioRecorder->state() == QMediaRecorder::StoppedState) {
		audioRecorder->setAudioInput(boxValue(ui.audioDeviceBox).toString());

		QAudioEncoderSettings settings;
		settings.setCodec(boxValue(ui.audioCodecBox).toString());
		settings.setSampleRate(boxValue(ui.sampleRateBox).toInt());
		settings.setBitRate(boxValue(ui.bitrateBox).toInt());
		settings.setChannelCount(boxValue(ui.channelsBox).toInt());
		settings.setQuality(QMultimedia::EncodingQuality(ui.qualitySlider->value()));
		settings.setEncodingMode(ui.constantQualityRadioButton->isChecked() ?
			QMultimedia::ConstantQualityEncoding :
			QMultimedia::ConstantBitRateEncoding);

		QString container = boxValue(ui.containerBox).toString();

		audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), container);
		audioRecorder->record();
	}
	else {
		audioRecorder->stop();
	}
}
void Record::onClickPause()
{
	if (audioRecorder->state() != QMediaRecorder::PausedState)
		audioRecorder->pause();
	else
		audioRecorder->record();
}
void::Record::stopRecording()
{
	audioRecorder->stop();
	//outputFile->close();
	qDebug() << QString::fromLocal8Bit("ֹͣ¼��") << endl;
}
void Record::setOutputLocation()
{
#ifdef Q_OS_WINRT
	// UWP does not allow to store outside the sandbox
	const QString cacheDir = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
	if (!QDir().mkpath(cacheDir)) {
		qWarning() << "Failed to create cache directory";
		return;
	}
	QString fileName = cacheDir + QLatin1String("/output.wav");
#else
	QString fileName = QFileDialog::getSaveFileName(this, tr("save audio"),"", tr("Audio (*.wav)"));
#endif
	audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));
	outputLocationSet = true;
}