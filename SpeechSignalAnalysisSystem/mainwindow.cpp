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
	/*�ź���۵�����*/
	connect(ui.readwav_act, SIGNAL(triggered()), this, SLOT(onClickChooseWavFile()));
	connect(ui.filterwind_open_act, SIGNAL(triggered()), this, SLOT(onClickOpenfilterWindow()));
	connect(ui.periodwind_open_act, SIGNAL(triggered()), this, SLOT(onClickOpenperiodWindow()));
	connect(ui.newdoublewav_act, SIGNAL(triggered()), this, SLOT(onClickOpenrecordWindow()));
	connect(ui.newsinglewav_act, SIGNAL(triggered()), this, SLOT(onClickOpenrecordWindow()));
	connect(ui.spectrumwind_open_act, SIGNAL(triggered()), this, SLOT(onClickOpenspectrumWindow()));

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
void MainWindow::onClickChooseWavFile()
{
	/*���ļ�*/
	filename = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("wavFile(*.wav)"));
	if (filename != NULL)
	{
		/*��QStringתΪString*/
		string filename2 = filename.toUtf8().data();
		/*��ȡwav*/
		audio_reader_wav<double> reader(open_file_for_reading(filename2));
		//audio_reader_wav<double> reader(open_file_for_reading("C:\\Users\\12860\\Desktop\\wav\\Alarm01.wav"));
		/*��ȡ���в�����*/
		univector2d<double> audio1 = reader.read_channels();
		/*��ȡ������*/
		samplerate = reader.format().samplerate;
		/*��ȡ����*/
		length = reader.format().length;
		/*��ȡ������*/
		channels = reader.format().channels;
		/*��������ڣ�X��*/
		duration = reader.format().length / reader.format().samplerate;
		/*����������x��y*/
		QVector<double> x(length), y(audio1.data()->size());
		QVector<double> x2(length), y2(audio1.data()->size());
		/*�ж�������*/
		if (channels == 1)
		{
			/*��ֵ��x��*/
			for (int i = 0; i < length; i++)
			{
				x[i] = (double)i / samplerate;
			}
			/*��ֵ��y��*/
			for (int i = 0; i < audio1.data()->size(); i++)
			{
				y[i] = (double)audio1.data()->at(i);
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_1->graph(0)->setData(x, y); //����xy��
			ui.waveform_wid_1->replot();//�ػ�
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
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_1->graph(0)->setData(x, y);//����xy��
			ui.waveform_wid_1->replot();//�ػ�

			ui.waveform_wid_2->xAxis->setRange(0.0, (double)duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_2->graph(0)->setData(x2, y2);//����xy��
			ui.waveform_wid_2->replot();//�ػ�
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