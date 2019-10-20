#include "spectrogram.h"

const int FRAMING = 30;
const int FRAMESHIFT = 20;
Spectrogram::Spectrogram(QWidget *parent, WavInfo *m_wavinfo)
	: QWidget(parent)
{
	ui.setupUi(this);
	wavinfo = new WavInfo();
	wavinfo = m_wavinfo;

	WinType win_type = HANNING;
	int n = double(FRAMING / (wavinfo->duration * 1000))*wavinfo->length;
	double *vessel = new double[n];
	int j = 0;
	for (int i = 0; i < wavinfo->length; i++)
	{
		if (i%n == 0)
		{
			j = 0;
			double *buf = new double[n];
			buf = getwincoef<double>(n, vessel, win_type);
		}
		vessel[j] = wavinfo->samplePoint[i];
	}
}
Spectrogram::~Spectrogram()
{
}
