#include "mainwindow.h"
#include "QFileDialog"
#include "filter.h"
#include "period.h"
#include "record.h"
#include "spectrum.h"
#include<kfr/all.hpp>
using namespace kfr;
using std::string;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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
		string filename2 = filename.toUtf8().data();
		/*读取wav*/
		audio_reader_wav<double> reader(open_file_for_reading(filename2));
		//audio_reader_wav<double> reader(open_file_for_reading("C:\\Users\\12860\\Desktop\\wav\\Alarm01.wav"));
		/*获取所有采样点*/
		univector2d<double> audio1 = reader.read_channels();
		/*获取采样率*/
		samplerate = reader.format().samplerate;
		/*获取长度*/
		length = reader.format().length;
		/*获取音道数*/
		channels = reader.format().channels;
		/*计算出周期，X轴*/
		duration = reader.format().length / reader.format().samplerate;
		/*创建迭代器x，y*/
		QVector<double> x(length), y(audio1.data()->size());
		QVector<double> x2(length), y2(audio1.data()->size());
		/*判断音道数*/
		if (channels == 1)
		{
			/*赋值给x轴*/
			for (int i = 0; i < length; i++)
			{
				x[i] = (double)i / samplerate;
			}
			/*赋值给y轴*/
			for (int i = 0; i < audio1.data()->size(); i++)
			{
				y[i] = (double)audio1.data()->at(i);
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//设置周期（x轴）
			ui.waveform_wid_1->graph(0)->setData(x, y); //设置xy轴
			ui.waveform_wid_1->replot();//重绘
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (i % 2 == 0)
					x[i] = (double)i / samplerate;
				else
					x2[i] = (double)i / samplerate;
			}
			for (int i = 0; i < audio1.data()->size(); i++)
			{
				if (i % 2 == 0)
					y[i] = (double)audio1.data()->at(i);
				else
					y2[i] = (double)audio1.data()->at(i);
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//设置周期（x轴）
			ui.waveform_wid_1->graph(0)->setData(x, y);//设置xy轴
			ui.waveform_wid_1->replot();//重绘

			ui.waveform_wid_2->xAxis->setRange(0.0, (double)duration);//设置周期（x轴）
			ui.waveform_wid_2->graph(0)->setData(x2, y2);//设置xy轴
			ui.waveform_wid_2->replot();//重绘
		}
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