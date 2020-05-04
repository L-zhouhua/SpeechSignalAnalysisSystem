#include "spectrogram.h"
#include <synchapi.h>
#include<vector>
using namespace std;
const int FRAMING = 30;
const int FRAMESHIFT = 20;

Spectrogram::Spectrogram(QWidget *parent, WavInfo *m_wavinfo)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->resize(QSize(2400, 1500)); //���ó�ʼ���ڴ�С
	//��ȡqss�ļ���������
	QFile file("qssStyle.qss");
	file.open(QFile::ReadOnly);
	QTextStream filetext(&file);
	QString stylesheet = filetext.readAll();
	this->setStyleSheet(stylesheet);
	file.close();

	wavinfo = new WavInfo();
	wavinfo = m_wavinfo;
	testDraw();

}
void Spectrogram::testDraw()
{
	//����ͼ
	double *a = new double[wavinfo->frames];
	if (wavinfo->channels == 2)
	{
		int j = 0;
		for (int i = 0; i < wavinfo->length; i++)
		{
			if (i % 2 == 0)
			{
				a[j] = wavinfo->samplePoints[i];
				//qDebug() << a[j] << " ";
				j++;
			}
		}
	}
	else
	{
		for (int i = 0; i < wavinfo->length; i++)
		{
			a[i] = wavinfo->samplePoints[i];
		}
	}
	vector<vector<double>> sp = spectrogram(a, wavinfo->frames, wavinfo->samplerate,30,20,512);
	pGraph = ui.spectrogram_widget_1->addGraph();
	/*s
	/*������ʾ�ϱߺ��ұߵ���*/
	//ui.spectrogram_widget_4->axisRect()->setupFullAxesBox(true);
	ui.spectrogram_widget_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	ui.spectrogram_widget_1->xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//����x��
	ui.spectrogram_widget_1->yAxis->setRange(0, wavinfo->samplerate / 2.0);//����y��
	ui.spectrogram_widget_1->xAxis->setLabel("Time(s)");
	ui.spectrogram_widget_1->yAxis->setLabel("Frequency(Hz)");
	ui.spectrogram_widget_1->axisRect()->setupFullAxesBox(true);
	/*ui.spectrogram_widget_1->axisRect()->setRangeZoomAxes(ui.spectrogram_widget_1->xAxis,ui.spectrogram_widget_1->yAxis);*/
	//ui.spectrogram_widget_1->axisRect()->setRangeZoomFactor(2, 1);

	//QVector<double> x(sp[0].size()*sp.size()), y(sp.size()*sp[0].size());
	//for (int i = 0; i < sp.size(); i++)
	//{
	//	for (int j = 0; j < sp[0].size(); j++)
	//	{
	//		x[j + (sp[0].size()*i)] = j;
	//		y[j + (sp[0].size()*i)] = sp.at(i).at(j);
	//		//qDebug() << sp.at(i).at(j) << " ";
	//	}
	//}

	//colorMap����
	pColorMap = new QCPColorMap(ui.spectrogram_widget_1->xAxis, ui.spectrogram_widget_1->yAxis);
	pColorMap->data()->setSize(sp.size(), sp[0].size());
	pColorMap->data()->setRange(QCPRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0), QCPRange(0, wavinfo->samplerate / 2.0));
	pColorMap->setInterpolate(false);
	pColorMap->setAntialiased(false);//�����Ƿ�Զ�����п���ݻ��ơ�

	QCPColorScale *colorScale = new QCPColorScale(ui.spectrogram_widget_1);
	ui.spectrogram_widget_1->plotLayout()->addElement(0, 1, colorScale); // �Ҳ����
	colorScale->setType(QCPAxis::atRight);
	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.spectrogram_widget_1);
	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	colorScale->axis()->setLabel("Magnitude (dB SPL)");//ɫ������

	pColorMap->setColorScale(colorScale); //��ͼ����ɫ��
	pColorMap->setGradient(QCPColorGradient::gpIon);
	//pColorMap->setDataRange(QCPRange(-20, 50));

	/*QCPItemRect *rect;
	rect = new QCPItemRect(ui.spectrogram_widget_1);
	rect->setBrush(QBrush(QColor(0, 0, 255, 70)));
	rect->setSelectable(false);
	rect->topLeft->setCoords(520, 25);
	rect->bottomRight->setCoords(10, 0);*/

	//QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.spectrogram_widget_1);
	//ui.spectrogram_widget_1->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	for (int i = 0; i < sp.size(); i++)
	{
		for (int j =0; j < sp[0].size(); j++)
		{
			pColorMap->data()->setCell(i, j, sp[i][j]*10);//��������
		}
	}


	//pGraph->setPen(QPen(QColor(187, 255, 255)));
	//pGraph->setLineStyle(QCPGraph::lsNone);
	//pGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
	//ui.spectrogram_widget_1->graph(0)->setData(x, y); //����xy��
	ui.spectrogram_widget_1->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
	ui.spectrogram_widget_1->replot();//�ػ�

}
Spectrogram::~Spectrogram()
{
}
