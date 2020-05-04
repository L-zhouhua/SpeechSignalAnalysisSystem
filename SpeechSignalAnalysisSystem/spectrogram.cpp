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
	this->resize(QSize(2400, 1500)); //设置初始窗口大小
	//读取qss文件，并设置
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
	//语谱图
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
	/*设置显示上边和右边的轴*/
	//ui.spectrogram_widget_4->axisRect()->setupFullAxesBox(true);
	ui.spectrogram_widget_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	ui.spectrogram_widget_1->xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//设置x轴
	ui.spectrogram_widget_1->yAxis->setRange(0, wavinfo->samplerate / 2.0);//设置y轴
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

	//colorMap方案
	pColorMap = new QCPColorMap(ui.spectrogram_widget_1->xAxis, ui.spectrogram_widget_1->yAxis);
	pColorMap->data()->setSize(sp.size(), sp[0].size());
	pColorMap->data()->setRange(QCPRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0), QCPRange(0, wavinfo->samplerate / 2.0));
	pColorMap->setInterpolate(false);
	pColorMap->setAntialiased(false);//设置是否对对象进行抗锯齿绘制。

	QCPColorScale *colorScale = new QCPColorScale(ui.spectrogram_widget_1);
	ui.spectrogram_widget_1->plotLayout()->addElement(0, 1, colorScale); // 右侧添加
	colorScale->setType(QCPAxis::atRight);
	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.spectrogram_widget_1);
	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	colorScale->axis()->setLabel("Magnitude (dB SPL)");//色条的名

	pColorMap->setColorScale(colorScale); //热图连接色条
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
			pColorMap->data()->setCell(i, j, sp[i][j]*10);//设置数据
		}
	}


	//pGraph->setPen(QPen(QColor(187, 255, 255)));
	//pGraph->setLineStyle(QCPGraph::lsNone);
	//pGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
	//ui.spectrogram_widget_1->graph(0)->setData(x, y); //设置xy轴
	ui.spectrogram_widget_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
	ui.spectrogram_widget_1->replot();//重绘

}
Spectrogram::~Spectrogram()
{
}
