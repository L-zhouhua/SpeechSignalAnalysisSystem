#include "mainwindow.h"
#include "QFileDialog"	
#include "filter_m.h"
#include "period.h"
#include "record.h"
#include "spectrum.h"
#include"finalmainwindow.h"
#include"spectrogram.h"
#include"freqyres.h"
#include"winfunc.h"
using std::string;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//this->setFixedSize(this->width(), this->height());
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
	connect(ui.spectrogram_act, SIGNAL(triggered()), this, SLOT(onClickOpenSpectrogramWindow()));
	connect(ui.freqResp_act, SIGNAL(triggered()), this, SLOT(onClickOpenfreqRespWindow()));
	connect(ui.winFunc_act, SIGNAL(triggered()), this, SLOT(onClickOpenWinFuncWindow()));

	//������¼�
	connect(ui.waveform_wid_1, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(my_mouseMoveEvent(QMouseEvent*)));
	connect(ui.waveform_wid_1, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(my_mousePressEvent(QMouseEvent*)));
	connect(ui.waveform_wid_1, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(my_mouseReleaseEvent(QMouseEvent*)));

	pGraph = ui.waveform_wid_1->addGraph();
	/*��������ɫ*/
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	/*������ʾ�ϱߺ��ұߵ���*/
	//ui.waveform_wid_1->axisRect()->setupFullAxesBox(true);
	ui.waveform_wid_1->setInteractions(QCP::iRangeZoom);
	//ui.waveform_wid_1->yAxis->setRange(-1, 1);//����y��
	ui.waveform_wid_1->xAxis->setLabel(QString::fromLocal8Bit("��"));
	ui.waveform_wid_1->yAxis->setLabel(QString::fromLocal8Bit("���"));
	
	

	//�߼���
	ui.waveform_wid_1->addLayer("spectrogram"); //���Ӳ���
	QCPLayoutGrid *subLayout = new QCPLayoutGrid; //�������񲼾�
	ui.waveform_wid_1->plotLayout()->addElement(1, 0, subLayout); //��Ԫ�أ����񲼾֣���ӵ���һ���յ�Ԫ��
	QCPAxisRect *subRectLeft = new QCPAxisRect(ui.waveform_wid_1, true); // false ��˼�ǲ�����Ĭ������
	subLayout->addElement(0, 0, subRectLeft);
	/*subRectLeft->addAxes(QCPAxis::atBottom | QCPAxis::atLeft);
	subRectLeft->axis(QCPAxis::atLeft)->ticker()->setTickCount(2);
	subRectLeft->axis(QCPAxis::atBottom)->grid()->setVisible(true);*/
	//�����
	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_1);
	//subRectLeft->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
	ui.waveform_wid_1->axisRect(0)->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
	ui.waveform_wid_1->axisRect(1)->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
	ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atLeft)->setLabel("Frequency(Hz)");
	ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atBottom)->setLabel("Time(s)");

	//pGraph2 = ui.waveform_wid_2->addGraph();
	///*��������ɫ*/
	//pGraph2->setPen(QPen(QColor(32, 178, 170)));
	//ui.waveform_wid_2->axisRect()->setupFullAxesBox(true);
	///*����ѡ�������*/
	//ui.waveform_wid_2->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));//����
	//ui.waveform_wid_2->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));//��͸��ǳ��
	///*����ѡ�����ģʽ*/
	//ui.waveform_wid_2->setSelectionRectMode(QCP::SelectionRectMode::srmCustom);
	///*�����û�������ʽ*/
	//ui.waveform_wid_2->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables);//�Ŵ�ѡ������
	//ui.waveform_wid_2->yAxis->setRange(-1, 1);//����y��
	////ui.waveform_wid_1->xAxis->setLabel("X");//x������
	////ui.waveform_wid_1->yAxis->setLabel("Y");//y������ 

	mapFromGlobal(QPoint(ui.waveform_wid_1->x(), ui.waveform_wid_1->y()));

	//���mouseMoceEvent����Ӧ
	setMouseTracking(true);
	ui.centralWidget->setMouseTracking(true);
	ui.waveform_wid_1->setMouseTracking(true);
	tracer = new QCPItemTracer(ui.waveform_wid_1);
	tracer->setPen(QPen(Qt::DashLine)); //�α����ͣ�����
	tracer->setStyle(QCPItemTracer::tsCrosshair);//�α���ʽ��ʮ���ǡ�ԲȦ�������


	//�����α�
	/*QCPItemStraightLine *line = new QCPItemStraightLine(ui.waveform_wid_1);
	QPen pen = QPen(QColor(243, 102, 31));
	pen.setStyle(Qt::DashLine);
	line->setPen(pen);
	line->point1->setCoords(1, 1);
	line->point2->setCoords(1, 5);*/

	ui.waveform_wid_1->axisRect(0)->setRangeZoomFactor(0.5, 0);//�Ŵ������
	ui.waveform_wid_1->axisRect(1)->setRangeZoomFactor(0.5, 0);//�Ŵ������

	//��ť��ʽ
	ui.zoomIn_but->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
		color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // ������ɫ
		"QPushButton:hover{background-color:white; color: black;}"  // ���ͣ��ʱ��ɫ��
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // ��갴�µ�ɫ��
	
}
void MainWindow::my_mouseMoveEvent(QMouseEvent *event)
{
	int x_pos = event->pos().x();
	int y_pos = event->pos().y();

	// ���������� ת��Ϊ QCustomPlot �ڲ�����ֵ ��pixelToCoord ������
	// coordToPixel ������֮�෴ �ǰ��ڲ�����ֵ ת��Ϊ�ⲿ�����
	double x_val = ui.waveform_wid_1->xAxis->pixelToCoord(x_pos);
	double y_val = ui.waveform_wid_1->yAxis->pixelToCoord(y_pos);

	//MainWindow::mouseMoveEvent(event);
	//double x = ui.waveform_wid_1->xAxis->pixelToCoord(event->pos().x());//�������������תplot����
	tracer->setGraph(pGraph);//�����α�������traceGraph����������
	tracer->setGraphKey(x_val);//�����α��Xֵ��������α��涯�Ĺؼ����룩
	double traceX = tracer->position->key();
	double traceY = tracer->position->value();
	//����״̬����Ϣ�����ݵ�����꣩
	ui.statusBar->showMessage("x: " + QString::number(traceX) + "   y: " + QString::number(traceY));
	
	//�α��
	if (line_2 != NULL&&mousePressFlag==1)
	{
		line_2->point1->setCoords(x_val, 1);
		line_2->point2->setCoords(x_val, 5);
	}



	ui.waveform_wid_1->replot();//�ػ�
}
void MainWindow::my_mousePressEvent(QMouseEvent * event)
{
	mousePressFlag = 1;

	int x_pos = event->pos().x();
	int y_pos = event->pos().y();

	// ���������� ת��Ϊ QCustomPlot �ڲ�����ֵ ��pixelToCoord ������
	// coordToPixel ������֮�෴ �ǰ��ڲ�����ֵ ת��Ϊ�ⲿ�����
	double x_val = ui.waveform_wid_1->xAxis->pixelToCoord(x_pos);
	double y_val = ui.waveform_wid_1->yAxis->pixelToCoord(y_pos);
		
	if (line != NULL)
		ui.waveform_wid_1->removeItem(line);
	if (line_2 != NULL)
		ui.waveform_wid_1->removeItem(line_2);
	line = new QCPItemStraightLine(ui.waveform_wid_1);
	QPen pen(QColor(243, 102, 31),2, Qt::DotLine);
	line->setPen(pen);
	line->point1->setCoords(x_val, 1);
	line->point2->setCoords(x_val, 5);

	line_2 = new QCPItemStraightLine(ui.waveform_wid_1);
	line_2->setPen(pen);
	line_2->point1->setCoords(x_val, 1);
	line_2->point2->setCoords(x_val, 5);

	ui.waveform_wid_1->replot();//�ػ�
}
void MainWindow::my_mouseReleaseEvent(QMouseEvent * event)
{
	mousePressFlag = 0;

	int x_pos = event->pos().x();
	int y_pos = event->pos().y();

	// ���������� ת��Ϊ QCustomPlot �ڲ�����ֵ ��pixelToCoord ������
	// coordToPixel ������֮�෴ �ǰ��ڲ�����ֵ ת��Ϊ�ⲿ�����
	double x_val = ui.waveform_wid_1->xAxis->pixelToCoord(x_pos);
	double y_val = ui.waveform_wid_1->yAxis->pixelToCoord(y_pos);

	line_2->point1->setCoords(x_val, 1);
	line_2->point2->setCoords(x_val, 5);

	ui.waveform_wid_1->replot();//�ػ�
}
void MainWindow::onClickZoomIn()
{
	ui.waveform_wid_1->xAxis->scaleRange(0.5);
	//ui.waveform_wid_1->yAxis->scaleRange(0.5);
	xAxis->scaleRange(0.5);
	ui.waveform_wid_1->replot();	
}
void MainWindow::onClickZoomOut()
{
	ui.waveform_wid_1->xAxis->scaleRange(2);
	//ui.waveform_wid_1->yAxis->scaleRange(2);
	xAxis->scaleRange(2);
	ui.waveform_wid_1->replot();
}
void MainWindow::onClickReset()
{
	ui.waveform_wid_1->graph(0)->rescaleAxes();
	ui.waveform_wid_1->yAxis->setRange(-1, 1);
	ui.waveform_wid_1->xAxis->setRange(0.0, (double)wavinfo->duration);
	xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//����x��
	yAxis->setRange(0, wavinfo->samplerate / 2.0);//����y��
	ui.waveform_wid_1->replot();
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
		wavinfo = new WavInfo();
		wavinfo->samplerate = sf_info.samplerate;
		/*��ȡ���������Ĳ�����*/
		wavinfo->frames = sf_info.frames;
		/*��ȡ������*/
		wavinfo->channels = sf_info.channels;
		/*��ȡ�ܲ�������*/
		wavinfo->length = wavinfo->frames * wavinfo->channels;
		/*��������Ϊlength��double*/
		wavinfo->samplePoints = new double[wavinfo->length];
		/*ʱ��*/
		wavinfo->duration = (double)wavinfo->frames / wavinfo->samplerate;
		/*�ж�������*/
		if (wavinfo->channels == 1)
		{
			/*����������x��y*/
			QVector<double> x(wavinfo->length), y(wavinfo->length);
			sf_readf_double(snd_file, wavinfo->samplePoints, sf_info.frames);
			/*��ֵ��x��*/
			for (int i = 0; i < wavinfo->length; i++)
			{
				x[i] = (double)i / wavinfo->samplerate/2.0;
			}
			/*��ֵ��y��*/
			for (int i = 0; i < wavinfo->length; i++)
			{
				y[i] = (double)wavinfo->samplePoints[i];
			}
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)wavinfo->duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_1->graph(0)->setData(x, y); //����xy��
			ui.waveform_wid_1->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
			ui.waveform_wid_1->yAxis->setRange(-1, 1);//����y��
			ui.waveform_wid_1->replot();//�ػ�
			//ui.waveform_wid_2->graph(0)->data()->clear();//���ͼ���������
			//ui.waveform_wid_2->replot();//�ػ�
		}
		else
		{

			/*����������x��y*/
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
			ui.waveform_wid_1->xAxis->setRange(0.0, (double)wavinfo->duration);//�������ڣ�x�ᣩ
			ui.waveform_wid_1->graph(0)->setData(x, y);//����xy��
			ui.waveform_wid_1->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
			ui.waveform_wid_1->yAxis->setRange(-1, 1);//����y��
			ui.waveform_wid_1->replot();//�ػ�

			if (pColorMap != NULL)//�ж�pColorMap�Ƿ�������
				pColorMap->data()->clear();//����ϴ�����
			testDraw_2();
	
			//ui.waveform_wid_2->xAxis->setRange(0.0, (double)wavinfo->duration);//�������ڣ�x�ᣩ
			//ui.waveform_wid_2->graph(0)->setData(x2, y2);//����xy��
			////ui.waveform_wid_2->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
			//ui.waveform_wid_2->replot();//�ػ�
		}
		sf_close(snd_file);
	}
}
//void MainWindow::testDraw()
//{
//	//����ͼ
//	double *a = new double[wavinfo->frames];
//	if (wavinfo->channels == 2)
//	{
//		int j = 0;
//		for (int i = 0; i < wavinfo->length; i++)
//		{
//			if (i % 2 == 0)
//			{
//				a[j] = wavinfo->samplePoints[i];
//				//qDebug() << a[j] << " ";
//				j++;
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < wavinfo->length; i++)
//		{
//			a[i] = wavinfo->samplePoints[i];
//		}
//	}
//	vector<vector<double>> sp = spectrogram(a, wavinfo->frames, wavinfo->samplerate, 30, 20, 512);
//	
//	ui.waveform_wid_2->xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//����x��
//	ui.waveform_wid_2->yAxis->setRange(0, wavinfo->samplerate / 2.0);//����y��
//	
//	/*ui.spectrogram_widget_1->axisRect()->setRangeZoomAxes(ui.spectrogram_widget_1->xAxis,ui.spectrogram_widget_1->yAxis);*/
//	//ui.spectrogram_widget_1->axisRect()->setRangeZoomFactor(2, 1);
//
//	//QVector<double> x(sp[0].size()*sp.size()), y(sp.size()*sp[0].size());
//	//for (int i = 0; i < sp.size(); i++)
//	//{
//	//	for (int j = 0; j < sp[0].size(); j++)
//	//	{
//	//		x[j + (sp[0].size()*i)] = j;
//	//		y[j + (sp[0].size()*i)] = sp.at(i).at(j);
//	//		//qDebug() << sp.at(i).at(j) << " ";
//	//	}
//	//}
//
//	//colorMap����
//	pColorMap = new QCPColorMap(ui.waveform_wid_2->xAxis, ui.waveform_wid_2->yAxis);
//	
//	pColorMap->data()->setSize(sp.size(), sp[0].size());
//	pColorMap->data()->setRange(QCPRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0), QCPRange(0, wavinfo->samplerate / 2.0));
//	pColorMap->setInterpolate(false);
//	pColorMap->setAntialiased(false);//�����Ƿ�Զ�����п���ݻ��ơ�
//
//	QCPColorScale *colorScale = new QCPColorScale(ui.waveform_wid_2);
//	//ui.waveform_wid_2->plotLayout()->addElement(0, 1, colorScale); // �Ҳ����
//	colorScale->setType(QCPAxis::atRight);
//	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_2);
//	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
//	colorScale->axis()->setLabel("Magnitude (dB SPL)");//ɫ������
//
//	pColorMap->setColorScale(colorScale); //��ͼ����ɫ��
//	pColorMap->setGradient(QCPColorGradient::gpThermal);
//	//pColorMap->setDataRange(QCPRange(-20, 50));
//
//	/*QCPItemRect *rect;
//	rect = new QCPItemRect(ui.spectrogram_widget_1);
//	rect->setBrush(QBrush(QColor(0, 0, 255, 70)));
//	rect->setSelectable(false);
//	rect->topLeft->setCoords(520, 25);
//	rect->bottomRight->setCoords(10, 0);*/
//
//	//QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_1);
//	//ui.spectrogram_widget_1->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
//	for (int i = 0; i < sp.size(); i++)
//	{
//		for (int j = 0; j < sp[0].size(); j++)
//		{
//			pColorMap->data()->setCell(i, j, sp[i][j] * 6);//��������
//		}
//	}
//
//	//ui.waveform_wid_2->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
//	ui.waveform_wid_2->replot();//�ػ�
////}
void MainWindow::testDraw_2()
{
	connect(ui.waveform_wid_1->xAxis, SIGNAL(rangeChanged()), this, SLOT(xAxis->setRange()));
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
	vector<vector<double>> sp = spectrogram(a, wavinfo->frames, wavinfo->samplerate, 30, 20, 512);

	xAxis = ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atBottom);
	yAxis = ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atLeft);

	xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//����x��
	yAxis->setRange(0, wavinfo->samplerate / 2.0);//����y��
	//xAxis->setRange(xAxis->range().bounded(0, 6));//�������ŷ�Χ
	//yAxis->setRange(yAxis->range().bounded(0, 10000));//�������ŷ�Χ
	pColorMap = new QCPColorMap(xAxis, yAxis);
	pColorMap->data()->setSize(sp.size(), sp[0].size());
	pColorMap->data()->setRange(QCPRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0), QCPRange(0, wavinfo->samplerate / 2.0));
	pColorMap->setInterpolate(false);
	pColorMap->setAntialiased(false);//�����Ƿ�Զ�����п���ݻ��ơ�

	QCPColorScale *colorScale = new QCPColorScale(ui.waveform_wid_1);
	ui.waveform_wid_1->plotLayout()->addElement(1, 1, colorScale); // �Ҳ����
	colorScale->setType(QCPAxis::atRight);
	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_1);
	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	colorScale->axis()->setLabel("Magnitude (dB SPL)");//ɫ������

	pColorMap->setColorScale(colorScale); //��ͼ����ɫ��
	pColorMap->setGradient(QCPColorGradient::gpThermal);
	//pColorMap->setDataRange(QCPRange(-20, 50));

	/*QCPItemRect *rect;
	rect = new QCPItemRect(ui.spectrogram_widget_1);
	rect->setBrush(QBrush(QColor(0, 0, 255, 70)));
	rect->setSelectable(false);
	rect->topLeft->setCoords(520, 25);
	rect->bottomRight->setCoords(10, 0);*/

	//QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_1);
	//ui.spectrogram_widget_1->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	for (int i = 0; i < sp.size(); i++)
	{
		for (int j = 0; j < sp[0].size(); j++)
		{
			pColorMap->data()->setCell(i, j, sp[i][j] * 6);//��������
		}
	}

	
	//ui.waveform_wid_2->rescaleAxes();//���µ����ᡢ���ú���������ʵ���������
	ui.waveform_wid_1->replot();//�ػ�
}
MainWindow::~MainWindow()
{
	if (wavinfo != NULL)
	{
		free(wavinfo->samplePoints);
		wavinfo->samplePoints = NULL;
	}
		
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
void MainWindow::onClickOpenWinFuncWindow()
{
	WinFunc *wf = new WinFunc();
	wf->show();
}