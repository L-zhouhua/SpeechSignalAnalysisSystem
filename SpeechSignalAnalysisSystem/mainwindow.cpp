#include "mainwindow.h"
#include "QFileDialog"	
#include "filter.h"
#include "period.h"
#include "record.h"
#include "spectrum.h"
#include"finalmainwindow.h"

using std::string;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->width(), this->height());
	/*�ź���۵�����*/
	connect(ui.readwav_act, SIGNAL(triggered()), this, SLOT(onClickChooseWavFile()));
	connect(ui.filterwind_open_act, SIGNAL(triggered()), this, SLOT(onClickOpenfilterWindow()));
	connect(ui.periodwind_open_act, SIGNAL(triggered()), this, SLOT(onClickOpenperiodWindow()));
	connect(ui.newdoublewav_act, SIGNAL(triggered()), this, SLOT(onClickOpenrecordWindow()));
	connect(ui.newsinglewav_act, SIGNAL(triggered()), this, SLOT(onClickOpenrecordWindow()));
	connect(ui.spectrumwind_open_act, SIGNAL(triggered()), this, SLOT(onClickOpenspectrumWindow()));
	connect(ui.play_act, SIGNAL(triggered()), this, SLOT(onClickPlayWav()));

	connect(ui.reset_but, SIGNAL(clicked()), this, SLOT(onClickReset()));
	connect(ui.zoomIn_but, SIGNAL(clicked()), this, SLOT(onClickZoomIn()));
	connect(ui.zoomOut_but, SIGNAL(clicked()), this, SLOT(onClickZoomOut()));

	connect(ui.windowopen, SIGNAL(triggered()), this, SLOT(onClickOpenNewWindow()));

	pGraph = ui.waveform_wid_1->addGraph();
	/*��������ɫ*/
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	/*������ʾ�ϱߺ��ұߵ���*/
	ui.waveform_wid_1->axisRect()->setupFullAxesBox(true);
	ui.waveform_wid_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	ui.waveform_wid_1->yAxis->setRange(-1, 1);//����y��

	pGraph2 = ui.waveform_wid_2->addGraph();
	/*��������ɫ*/
	pGraph2->setPen(QPen(QColor(32, 178, 170)));
	ui.waveform_wid_2->axisRect()->setupFullAxesBox(true);
	/*����ѡ�������*/
	ui.waveform_wid_2->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));//����
	ui.waveform_wid_2->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));//��͸��ǳ��
	/*����ѡ�����ģʽ*/
	ui.waveform_wid_2->setSelectionRectMode(QCP::SelectionRectMode::srmCustom);
	/*�����û�������ʽ*/
	ui.waveform_wid_2->setInteractions(QCP::iRangeZoom);
	ui.waveform_wid_2->yAxis->setRange(-1, 1);//����y��

	//ui.waveform_wid_1->xAxis->setLabel("X");//x������
	//ui.waveform_wid_1->yAxis->setLabel("Y");//y������ 
}
void MainWindow::onClickZoomIn()
{
	ui.waveform_wid_1->xAxis->scaleRange(0.5);
	ui.waveform_wid_1->yAxis->scaleRange(0.5);
	ui.waveform_wid_2->xAxis->scaleRange(0.5);
	ui.waveform_wid_2->yAxis->scaleRange(0.5);
	//ui.waveform_wid_1->axisRect()->setRangeZoomFactor(1.2, 1.2);
	ui.waveform_wid_1->replot();
	ui.waveform_wid_2->replot();
}
void MainWindow::onClickZoomOut()
{
	ui.waveform_wid_1->xAxis->scaleRange(2);
	ui.waveform_wid_1->yAxis->scaleRange(2);
	ui.waveform_wid_2->xAxis->scaleRange(2);
	ui.waveform_wid_2->yAxis->scaleRange(2);
	ui.waveform_wid_1->replot();
	ui.waveform_wid_2->replot();
}
void MainWindow::onClickReset()
{
	ui.waveform_wid_1->graph(0)->rescaleAxes();
	ui.waveform_wid_2->graph(0)->rescaleAxes();
	ui.waveform_wid_1->yAxis->setRange(-1, 1);
	ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);
	ui.waveform_wid_2->yAxis->setRange(-1, 1);
	ui.waveform_wid_2->xAxis->setRange(0.0, (double)duration);
	ui.waveform_wid_1->replot();
	ui.waveform_wid_2->replot();
}
void MainWindow::onClickPlayWav()
{

	if (filename == NULL)
	{
		QMessageBox::about(NULL, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ȴ�wav�ļ���"));
	}
	else
	{
		QSound::play(filename);
	}
}
void MainWindow::onClickChooseWavFile()
{
	/*���ļ�*/
	filename = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("wavFile(*.wav)"));
	if (filename != NULL)
	{
		/*��QStringתΪString*/
		string fileUrl = filename.toUtf8().data();
		/*��StringתΪchar*/
		const char* ch_fileUrl = fileUrl.c_str();
		/*��formatԤ������Ϊ0*/
		sf_info.format = 0;
		/*��ȡwav�ļ�*/
		snd_file = sf_open(ch_fileUrl, SFM_READ,&sf_info);
		/*��ȡ������*/
		samplerate = sf_info.samplerate;
		/*��ȡ���������Ĳ�����*/
		frames = sf_info.frames;
		/*��ȡ������*/
		channels = sf_info.channels;
		/*��ȡ�ܲ�������*/
		length = frames * channels;
		/*��������Ϊlength��double*/
		buf = new double[length];
		/*��������ڣ�X��*/
		duration = (double)length / samplerate;
		/*�ж�������*/
		if (channels == 1)
		{
			/*����������x��y*/
			QVector<double> x(length), y(length);
			sf_readf_double(snd_file, buf, sf_info.frames);
			/*��ֵ��x��*/
			for (int i = 0; i < length; i++)
			{
				x[i] = (double)i / samplerate;
			}
			/*��ֵ��y��*/
			for (int i = 0; i < length; i++)
			{
				y[i] = (double)buf[i];
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_1->graph(0)->setData(x, y); //����xy��
			//ui.waveform_wid_1->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
			ui.waveform_wid_1->replot();//�ػ�
			ui.waveform_wid_2->graph(0)->data()->clear();//���ͼ���������
			ui.waveform_wid_2->replot();//�ػ�
		}
		else
		{

			/*����������x��y*/
			QVector<double> x(length), y(length);
			QVector<double> x2(length), y2(length);
			sf_read_double(snd_file, buf, length);
			for (int i = 0; i < length; i++)
			{
				if (i % 2 == 0)
				{
					x[i] = (double)i / samplerate;
					y[i] = (double)buf[i];
				}
				else
				{
					x2[i] = (double)i / samplerate;
					y2[i] = (double)buf[i];
				}
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_1->graph(0)->setData(x, y);//����xy��
			//ui.waveform_wid_1->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
			ui.waveform_wid_1->replot();//�ػ�

			ui.waveform_wid_2->xAxis->setRange(0.0, (double)duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_2->graph(0)->setData(x2, y2);//����xy��
			//ui.waveform_wid_2->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
			ui.waveform_wid_2->replot();//�ػ�
		}
		sf_close(snd_file);
	}
}
MainWindow::~MainWindow()
{
	if(buf!=NULL)
		free(buf);
}
void MainWindow::onClickOpenfilterWindow()
{
	Filter *filter = new Filter();
	filter->show();
}
void MainWindow::onClickOpenperiodWindow()
{
	Period *period = new Period();
	period->show();
}
void MainWindow::onClickOpenrecordWindow()
{
	Record *record = new Record();
	record->show();
}
void MainWindow::onClickOpenspectrumWindow()
{
	Spectrum *spectrum = new Spectrum();
	spectrum->getLengthOnMainWindow(length);
	spectrum->getBufOnMainWindow(buf);
	spectrum->getFramesOnWindow(frames);
	spectrum->getSamplerateOnMainWindow(samplerate);
	spectrum->drawSpecturm();
	spectrum->show();
}
void MainWindow::onClickOpenNewWindow()
{
	FinalMainWindow *fmw = new FinalMainWindow();
	fmw->show();
}