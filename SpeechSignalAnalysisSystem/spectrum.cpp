#include "spectrum.h"

Spectrum::Spectrum(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->width(), this->height());

	pGraph = ui.specturm_wdo->addGraph();
	/*��������ɫ*/
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	/*������ʾ�ϱߺ��ұߵ���*/
	ui.specturm_wdo->axisRect()->setupFullAxesBox(true);
	ui.specturm_wdo->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
Spectrum::~Spectrum()
{
	if(buf!=NULL)
		free(buf);
}
void Spectrum::getFramesOnWindow(int m_frames)
{
	frames = m_frames;
}
void Spectrum::getBufOnMainWindow(double *m_buf)
{
	buf = new double[length];
	buf = m_buf;
}

void Spectrum::getLengthOnMainWindow(int m_length)
{
	length = m_length;
	//qDebug() << "length:" << length << endl;
}
void Spectrum::getSamplerateOnMainWindow(int m_samplerate)
{
	samplerate = m_samplerate;
}

void Spectrum::drawSpecturm()
{
	out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * length);
	p = fftw_plan_dft_r2c_1d(1000, buf, out, FFTW_ESTIMATE);
	fftw_execute(p);
	QVector<double> x(length), y(length);
	/*��ֵx,y��*/
	for (int i = 0; i < 1000; i++)
	{
		x[i] = (double)i / length * (samplerate / 2.0);
		double A = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		y[i] = 20 * log10(A);
	}
	ui.specturm_wdo->xAxis->setRange(0, 25);
	ui.specturm_wdo->yAxis->setRange(-70, -120);
	ui.specturm_wdo->graph(0)->setData(x, y); //����xy��
	ui.specturm_wdo->rescaleAxes(true);//���µ����ᡢ���ú���������ʵ���������	
	ui.specturm_wdo->replot();//�ػ�
	fftw_destroy_plan(p);
	fftw_free(out);
}
