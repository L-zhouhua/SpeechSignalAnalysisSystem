#include "mainwindow.h"
#include "QFileDialog"	
#include "filter_m.h"
#include "period.h"
#include "record.h"
#include "spectrum.h"
#include"finalmainwindow.h"
#include"spectrogram.h"
#include"freqyres.h"
using std::string;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->width(), this->height());
	/*信号与槽的连接*/
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
	connect(ui.spectrogram_act, SIGNAL(triggered()), this, SLOT(onClickOpenSpectrogramWindow()));
	connect(ui.freqResp_act, SIGNAL(triggered()), this, SLOT(onClickOpenfreqRespWindow()));

	pGraph = ui.waveform_wid_1->addGraph();
	/*设置线颜色*/
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	/*设置显示上边和右边的轴*/
	ui.waveform_wid_1->axisRect()->setupFullAxesBox(true);
	ui.waveform_wid_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	ui.waveform_wid_1->yAxis->setRange(-1, 1);//设置y轴

	pGraph2 = ui.waveform_wid_2->addGraph();
	/*设置线颜色*/
	pGraph2->setPen(QPen(QColor(32, 178, 170)));
	ui.waveform_wid_2->axisRect()->setupFullAxesBox(true);
	/*设置选框的属性*/
	ui.waveform_wid_2->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));//虚线
	ui.waveform_wid_2->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));//半透明浅蓝
	/*设置选择矩形模式*/
	ui.waveform_wid_2->setSelectionRectMode(QCP::SelectionRectMode::srmCustom);
	/*设置用户交互方式*/
	ui.waveform_wid_2->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables);//放大、选择线条
	ui.waveform_wid_2->yAxis->setRange(-1, 1);//设置y轴
	//ui.waveform_wid_1->xAxis->setLabel("X");//x轴名称
	//ui.waveform_wid_1->yAxis->setLabel("Y");//y轴名称 
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
	ui.waveform_wid_1->xAxis->setRange(0.0, (double)wavinfo->duration);
	ui.waveform_wid_2->yAxis->setRange(-1, 1);
	ui.waveform_wid_2->xAxis->setRange(0.0, (double)wavinfo->duration);
	ui.waveform_wid_1->replot();
	ui.waveform_wid_2->replot();
}
void MainWindow::onClickPlayWav()
{

	if (filename == NULL)
	{
		QMessageBox::about(NULL, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请先打开wav文件！"));
	}
	else
	{
		QSound::play(filename);
	}
}

void MainWindow::onClickChooseWavFile()
{
	/*打开文件*/
	filename = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("wavFile(*.wav)"));
	if (filename != NULL)
	{
		/*将QString转为String*/
		string fileUrl = filename.toUtf8().data();
		/*讲String转为char*/
		const char* ch_fileUrl = fileUrl.c_str();
		/*将format预先设置为0*/
		sf_info.format = 0;
		/*读取wav文件*/
		snd_file = sf_open(ch_fileUrl, SFM_READ,&sf_info);
		/*获取采样率*/
		wavinfo = new WavInfo();
		wavinfo->samplerate = sf_info.samplerate;
		/*获取单个声道的采样点*/
		wavinfo->frames = sf_info.frames;
		/*获取音道数*/
		wavinfo->channels = sf_info.channels;
		/*获取总采样点数*/
		wavinfo->length = wavinfo->frames * wavinfo->channels;
		/*创建长度为length的double*/
		wavinfo->samplePoints = new double[wavinfo->length];
		/*时长*/
		wavinfo->duration = (double)wavinfo->frames / wavinfo->samplerate;
		/*判断音道数*/
		if (wavinfo->channels == 1)
		{
			/*创建迭代器x，y*/
			QVector<double> x(wavinfo->length), y(wavinfo->length);
			sf_readf_double(snd_file, wavinfo->samplePoints, sf_info.frames);
			/*赋值给x轴*/
			for (int i = 0; i < wavinfo->length; i++)
			{
				x[i] = (double)i / wavinfo->samplerate/2.0;
			}
			/*赋值给y轴*/
			for (int i = 0; i < wavinfo->length; i++)
			{
				y[i] = (double)wavinfo->samplePoints[i];
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)wavinfo->duration);//设置周期（x轴）
			ui.waveform_wid_1->graph(0)->setData(x, y); //设置xy轴
			//ui.waveform_wid_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_1->replot();//重绘
			ui.waveform_wid_2->graph(0)->data()->clear();//清除图表二的数据
			ui.waveform_wid_2->replot();//重绘
		}
		else
		{

			/*创建迭代器x，y*/
			QVector<double> x(wavinfo->length), y(wavinfo->length);
			QVector<double> x2(wavinfo->length), y2(wavinfo->length);
			sf_read_double(snd_file, wavinfo->samplePoints, wavinfo->length);
			for (int i = 0; i < wavinfo->length; i++)
			{
				if (i % 2 == 0)
				{
					x[i] = (double)i / wavinfo->samplerate/2.0;
					y[i] = (double)wavinfo->samplePoints[i];
				}
				else
				{
					x2[i] = (double)i / wavinfo->samplerate/2.0;
					y2[i] = (double)wavinfo->samplePoints[i];
				}
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)wavinfo->duration);//设置周期（x轴）
			ui.waveform_wid_1->graph(0)->setData(x, y);//设置xy轴
			//ui.waveform_wid_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_1->replot();//重绘

			ui.waveform_wid_2->xAxis->setRange(0.0, (double)wavinfo->duration);//设置周期（x轴）
			ui.waveform_wid_2->graph(0)->setData(x2, y2);//设置xy轴
			//ui.waveform_wid_2->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_2->replot();//重绘
		}
		sf_close(snd_file);
	}
}
MainWindow::~MainWindow()
{
	if(wavinfo->samplePoints!=NULL)
		free(wavinfo->samplePoints);
}
void MainWindow::onClickOpenfilterWindow()
{
	FilterM *filter = new FilterM();
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
	Spectrum *spectrum = new Spectrum(Q_NULLPTR,wavinfo);
	spectrum->show();
}
void MainWindow::onClickOpenNewWindow()
{
	FinalMainWindow *fmw = new FinalMainWindow();
	fmw->show();
}
void MainWindow::onClickOpenSpectrogramWindow()
{
	Spectrogram *spectrogram = new Spectrogram(Q_NULLPTR, wavinfo);
	spectrogram->show();
}
void MainWindow::onClickOpenfreqRespWindow()
{
	FreqyRes *fr = new FreqyRes(Q_NULLPTR, wavinfo);
	fr->show();
}