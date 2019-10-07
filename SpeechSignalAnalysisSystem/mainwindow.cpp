#include "mainwindow.h"
#include "QFileDialog"
#include "filter.h"
#include "period.h"
#include "record.h"
#include "spectrum.h"

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
	ui.waveform_wid_2->setInteractions(QCP::iRangeZoom);
	ui.waveform_wid_2->yAxis->setRange(-1, 1);//设置y轴

	//ui.waveform_wid_1->xAxis->setLabel("X");//x轴名称
	//ui.waveform_wid_1->yAxis->setLabel("Y");//y轴名称 
}
void MainWindow::onClickChooseWavFile()
{
	/*打开文件*/
	filename = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("wavFile(*.wav)"));
	if (filename != NULL)
	{
		/*将QString转为String*/
		string fileUrl = filename.toUtf8().data();
		const char* ch_fileUrl = fileUrl.c_str();
		/*读取wav*/
		sf_info.format = 0;
		snd_file = sf_open(ch_fileUrl, SFM_READ,&sf_info);
		//audio_reader_wav<double> reader(open_file_for_reading("C:\\Users\\12860\\Desktop\\wav\\Alarm01.wav"));
		/*获取所有采样点*/
		//buf = (double *)malloc(sf_info.frames * sizeof(double));
		buf = new double[sf_info.frames*2];
		/*获取采样率*/
		samplerate = sf_info.samplerate;
		/*获取单个声道的采样点*/
		frames = sf_info.frames;
		/*获取音道数*/
		channels = sf_info.channels;
		/*获取总采样点数*/
		length = frames * channels;
		/*计算出周期，X轴*/
		duration = (double)length / samplerate;
		/*判断音道数*/
		if (channels == 1)
		{
			/*创建迭代器x，y*/
			QVector<double> x(length), y(length);
			sf_readf_double(snd_file, buf, sf_info.frames);
			/*赋值给x轴*/
			for (int i = 0; i < length; i++)
			{
				x[i] = (double)i / samplerate;
			}
			/*赋值给y轴*/
			for (int i = 0; i < length; i++)
			{
				y[i] = (double)buf[i];
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//设置周期（x轴）
			ui.waveform_wid_1->graph(0)->setData(x, y); //设置xy轴
			//ui.waveform_wid_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_1->replot();//重绘
			ui.waveform_wid_2->graph(0)->data()->clear();//清除图表二的数据
			ui.waveform_wid_2->replot();//重绘
		}
		else
		{

			/*创建迭代器x，y*/
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
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//设置周期（x轴）
			ui.waveform_wid_1->graph(0)->setData(x, y);//设置xy轴
			//ui.waveform_wid_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_1->replot();//重绘

			ui.waveform_wid_2->xAxis->setRange(0.0, (double)duration);//设置周期（x轴）
			ui.waveform_wid_2->graph(0)->setData(x2, y2);//设置xy轴
			//ui.waveform_wid_2->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_2->replot();//重绘
		}
		free(buf);
		sf_close(snd_file);
	}
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
	spectrum->show();
}