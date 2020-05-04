#include "spectrum.h"

Spectrum::Spectrum(QWidget *parent,WavInfo *m_wavinfo)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.reset_but, SIGNAL(clicked()), this, SLOT(onClickReset()));
	connect(ui.zoomIn_but, SIGNAL(clicked()), this, SLOT(onClickZoomIn()));
	connect(ui.zoomOut_but, SIGNAL(clicked()), this, SLOT(onClickZoomOut()));

	this->resize(QSize(2000, 1000));//设置初始窗口大小

	this->setFixedSize(this->width(), this->height()); //设置不能最大化窗口
	//读取qss文件，并设置
	QFile file("qssStyle.qss");
	file.open(QFile::ReadOnly);
	QTextStream filetext(&file);
	QString stylesheet = filetext.readAll();
	this->setStyleSheet(stylesheet);
	file.close();

	wavinfo = new WavInfo();
	wavinfo = m_wavinfo;

	pGraph = ui.specturm_wdo->addGraph();
	/*设置线颜色*/
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	/*设置显示上边和右边的轴*/
	ui.specturm_wdo->axisRect()->setupFullAxesBox(true);
	ui.specturm_wdo->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

	out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * wavinfo->length);
	p = fftw_plan_dft_r2c_1d(wavinfo->length, wavinfo->samplePoints, out, FFTW_ESTIMATE);
	fftw_execute(p);
	QVector<double> x(wavinfo->length), y(wavinfo->length);
	/*赋值x,y 轴*/
	for (int i = 0; i < wavinfo->length; i++)
	{
		double A = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		if (A == 0.0)
		{
			continue;
		}
		x[i] = (double)i / wavinfo->length * (wavinfo->samplerate / 2.0);
		y[i] = 20 * log10(A);
	}
	ui.specturm_wdo->xAxis->setLabel(QString::fromLocal8Bit("频率"));
	ui.specturm_wdo->yAxis->setLabel(QString::fromLocal8Bit("振幅"));
	ui.specturm_wdo->graph(0)->setData(x, y); //设置xy轴
	ui.specturm_wdo->rescaleAxes(true);//重新调节轴、调用后坐标会根据实际情况增加	
	ui.specturm_wdo->replot();//重绘
	fftw_destroy_plan(p);
	fftw_free(out);
	
}
Spectrum::~Spectrum()
{
	if(wavinfo->samplePoints!=NULL)
		free(wavinfo->samplePoints);
}
void Spectrum::onClickZoomIn()
{
	ui.specturm_wdo->xAxis->scaleRange(0.5);
	//ui.waveform_wid_1->yAxis->scaleRange(0.5);
	ui.specturm_wdo->replot();
}
void Spectrum::onClickZoomOut()
{
	ui.specturm_wdo->xAxis->scaleRange(2);
	//ui.waveform_wid_1->yAxis->scaleRange(2);
	ui.specturm_wdo->replot();
}
void Spectrum::onClickReset()
{
	ui.specturm_wdo->rescaleAxes(true);//重新调节轴、调用后坐标会根据实际情况增加
	ui.specturm_wdo->replot();
}
//void Spectrum::getFramesOnWindow(int m_frames)
//{
//	frames = m_frames;
//}
//void Spectrum::getBufOnMainWindow(double *m_buf)
//{
//	buf = new double[length];
//	buf = m_buf;
//}
//
//void Spectrum::getLengthOnMainWindow(int m_length)
//{
//	length = m_length;
//	//qDebug() << "length:" << length << endl;
//}
//void Spectrum::getSamplerateOnMainWindow(int m_samplerate)
//{
//	samplerate = m_samplerate;
//}
//void Spectrum::drawSpecturm()
//{
//	out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * length);
//	p = fftw_plan_dft_r2c_1d(1000, buf, out, FFTW_ESTIMATE);
//	fftw_execute(p);
//	QVector<double> x(length), y(length);
//	/*赋值x,y轴*/
//	for (int i = 0; i < 1000; i++)
//	{
//		x[i] = (double)i / length * (samplerate / 2.0);
//		double A = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
//		y[i] = 20 * log10(A);
//	}
//	ui.specturm_wdo->xAxis->setRange(0, 25);
//	ui.specturm_wdo->yAxis->setRange(-70, -120);
//	ui.specturm_wdo->graph(0)->setData(x, y); //设置xy轴
//	ui.specturm_wdo->rescaleAxes(true);//重新调节轴、调用后坐标会根据实际情况增加	
//	ui.specturm_wdo->replot();//重绘
//	fftw_destroy_plan(p);
//	fftw_free(out);
//}
