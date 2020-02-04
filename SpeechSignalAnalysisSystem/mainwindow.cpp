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
	connect(ui.winFunc_act, SIGNAL(triggered()), this, SLOT(onClickOpenWinFuncWindow()));

	//绑定鼠标事件
	connect(ui.waveform_wid_1, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(my_mouseMoveEvent(QMouseEvent*)));
	connect(ui.waveform_wid_1, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(my_mousePressEvent(QMouseEvent*)));
	connect(ui.waveform_wid_1, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(my_mouseReleaseEvent(QMouseEvent*)));

	pGraph = ui.waveform_wid_1->addGraph();
	/*设置线颜色*/
	pGraph->setPen(QPen(QColor(32, 178, 170)));
	/*设置显示上边和右边的轴*/
	//ui.waveform_wid_1->axisRect()->setupFullAxesBox(true);
	ui.waveform_wid_1->setInteractions(QCP::iRangeZoom);
	//ui.waveform_wid_1->yAxis->setRange(-1, 1);//设置y轴
	ui.waveform_wid_1->xAxis->setLabel(QString::fromLocal8Bit("秒"));
	ui.waveform_wid_1->yAxis->setLabel(QString::fromLocal8Bit("振幅"));
	
	

	//高级轴
	ui.waveform_wid_1->addLayer("spectrogram"); //增加布局
	QCPLayoutGrid *subLayout = new QCPLayoutGrid; //创建网格布局
	ui.waveform_wid_1->plotLayout()->addElement(1, 0, subLayout); //将元素（网格布局）添加到下一个空单元格
	QCPAxisRect *subRectLeft = new QCPAxisRect(ui.waveform_wid_1, true); // false 意思是不设置默认坐标
	subLayout->addElement(0, 0, subRectLeft);
	/*subRectLeft->addAxes(QCPAxis::atBottom | QCPAxis::atLeft);
	subRectLeft->axis(QCPAxis::atLeft)->ticker()->setTickCount(2);
	subRectLeft->axis(QCPAxis::atBottom)->grid()->setVisible(true);*/
	//轴对齐
	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_1);
	//subRectLeft->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
	ui.waveform_wid_1->axisRect(0)->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
	ui.waveform_wid_1->axisRect(1)->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
	ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atLeft)->setLabel("Frequency(Hz)");
	ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atBottom)->setLabel("Time(s)");

	//pGraph2 = ui.waveform_wid_2->addGraph();
	///*设置线颜色*/
	//pGraph2->setPen(QPen(QColor(32, 178, 170)));
	//ui.waveform_wid_2->axisRect()->setupFullAxesBox(true);
	///*设置选框的属性*/
	//ui.waveform_wid_2->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));//虚线
	//ui.waveform_wid_2->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));//半透明浅蓝
	///*设置选择矩形模式*/
	//ui.waveform_wid_2->setSelectionRectMode(QCP::SelectionRectMode::srmCustom);
	///*设置用户交互方式*/
	//ui.waveform_wid_2->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables);//放大、选择线条
	//ui.waveform_wid_2->yAxis->setRange(-1, 1);//设置y轴
	////ui.waveform_wid_1->xAxis->setLabel("X");//x轴名称
	////ui.waveform_wid_1->yAxis->setLabel("Y");//y轴名称 

	mapFromGlobal(QPoint(ui.waveform_wid_1->x(), ui.waveform_wid_1->y()));

	//解决mouseMoceEvent不响应
	setMouseTracking(true);
	ui.centralWidget->setMouseTracking(true);
	ui.waveform_wid_1->setMouseTracking(true);
	tracer = new QCPItemTracer(ui.waveform_wid_1);
	tracer->setPen(QPen(Qt::DashLine)); //游标线型：虚线
	tracer->setStyle(QCPItemTracer::tsCrosshair);//游标样式：十字星、圆圈、方框等


	//左右游标
	/*QCPItemStraightLine *line = new QCPItemStraightLine(ui.waveform_wid_1);
	QPen pen = QPen(QColor(243, 102, 31));
	pen.setStyle(Qt::DashLine);
	line->setPen(pen);
	line->point1->setCoords(1, 1);
	line->point2->setCoords(1, 5);*/

	ui.waveform_wid_1->axisRect(0)->setRangeZoomFactor(0.5, 0);//放大横坐标
	ui.waveform_wid_1->axisRect(1)->setRangeZoomFactor(0.5, 0);//放大横坐标

	//按钮样式
	ui.zoomIn_but->setStyleSheet("QPushButton{background-color:rgba(255,178,0,100%);\
		color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
		"QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");   // 鼠标按下的色彩
	
}
void MainWindow::my_mouseMoveEvent(QMouseEvent *event)
{
	int x_pos = event->pos().x();
	int y_pos = event->pos().y();

	// 把鼠标坐标点 转换为 QCustomPlot 内部坐标值 （pixelToCoord 函数）
	// coordToPixel 函数与之相反 是把内部坐标值 转换为外部坐标点
	double x_val = ui.waveform_wid_1->xAxis->pixelToCoord(x_pos);
	double y_val = ui.waveform_wid_1->yAxis->pixelToCoord(y_pos);

	//MainWindow::mouseMoveEvent(event);
	//double x = ui.waveform_wid_1->xAxis->pixelToCoord(event->pos().x());//鼠标点的像素坐标转plot坐标
	tracer->setGraph(pGraph);//设置游标吸附在traceGraph这条曲线上
	tracer->setGraphKey(x_val);//设置游标的X值（这就是游标随动的关键代码）
	double traceX = tracer->position->key();
	double traceY = tracer->position->value();
	//设置状态条信息（数据点的坐标）
	ui.statusBar->showMessage("x: " + QString::number(traceX) + "   y: " + QString::number(traceY));
	
	//游标二
	if (line_2 != NULL&&mousePressFlag==1)
	{
		line_2->point1->setCoords(x_val, 1);
		line_2->point2->setCoords(x_val, 5);
	}



	ui.waveform_wid_1->replot();//重绘
}
void MainWindow::my_mousePressEvent(QMouseEvent * event)
{
	mousePressFlag = 1;

	int x_pos = event->pos().x();
	int y_pos = event->pos().y();

	// 把鼠标坐标点 转换为 QCustomPlot 内部坐标值 （pixelToCoord 函数）
	// coordToPixel 函数与之相反 是把内部坐标值 转换为外部坐标点
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

	ui.waveform_wid_1->replot();//重绘
}
void MainWindow::my_mouseReleaseEvent(QMouseEvent * event)
{
	mousePressFlag = 0;

	int x_pos = event->pos().x();
	int y_pos = event->pos().y();

	// 把鼠标坐标点 转换为 QCustomPlot 内部坐标值 （pixelToCoord 函数）
	// coordToPixel 函数与之相反 是把内部坐标值 转换为外部坐标点
	double x_val = ui.waveform_wid_1->xAxis->pixelToCoord(x_pos);
	double y_val = ui.waveform_wid_1->yAxis->pixelToCoord(y_pos);

	line_2->point1->setCoords(x_val, 1);
	line_2->point2->setCoords(x_val, 5);

	ui.waveform_wid_1->replot();//重绘
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
	xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//设置x轴
	yAxis->setRange(0, wavinfo->samplerate / 2.0);//设置y轴
	ui.waveform_wid_1->replot();
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
			ui.waveform_wid_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_1->yAxis->setRange(-1, 1);//设置y轴
			ui.waveform_wid_1->replot();//重绘
			//ui.waveform_wid_2->graph(0)->data()->clear();//清除图表二的数据
			//ui.waveform_wid_2->replot();//重绘
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
			ui.waveform_wid_1->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			ui.waveform_wid_1->yAxis->setRange(-1, 1);//设置y轴
			ui.waveform_wid_1->replot();//重绘

			if (pColorMap != NULL)//判断pColorMap是否有数据
				pColorMap->data()->clear();//清除上次数据
			testDraw_2();
	
			//ui.waveform_wid_2->xAxis->setRange(0.0, (double)wavinfo->duration);//设置周期（x轴）
			//ui.waveform_wid_2->graph(0)->setData(x2, y2);//设置xy轴
			////ui.waveform_wid_2->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
			//ui.waveform_wid_2->replot();//重绘
		}
		sf_close(snd_file);
	}
}
//void MainWindow::testDraw()
//{
//	//语谱图
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
//	ui.waveform_wid_2->xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//设置x轴
//	ui.waveform_wid_2->yAxis->setRange(0, wavinfo->samplerate / 2.0);//设置y轴
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
//	//colorMap方案
//	pColorMap = new QCPColorMap(ui.waveform_wid_2->xAxis, ui.waveform_wid_2->yAxis);
//	
//	pColorMap->data()->setSize(sp.size(), sp[0].size());
//	pColorMap->data()->setRange(QCPRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0), QCPRange(0, wavinfo->samplerate / 2.0));
//	pColorMap->setInterpolate(false);
//	pColorMap->setAntialiased(false);//设置是否对对象进行抗锯齿绘制。
//
//	QCPColorScale *colorScale = new QCPColorScale(ui.waveform_wid_2);
//	//ui.waveform_wid_2->plotLayout()->addElement(0, 1, colorScale); // 右侧添加
//	colorScale->setType(QCPAxis::atRight);
//	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_2);
//	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
//	colorScale->axis()->setLabel("Magnitude (dB SPL)");//色条的名
//
//	pColorMap->setColorScale(colorScale); //热图连接色条
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
//			pColorMap->data()->setCell(i, j, sp[i][j] * 6);//设置数据
//		}
//	}
//
//	//ui.waveform_wid_2->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
//	ui.waveform_wid_2->replot();//重绘
////}
void MainWindow::testDraw_2()
{
	connect(ui.waveform_wid_1->xAxis, SIGNAL(rangeChanged()), this, SLOT(xAxis->setRange()));
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
	vector<vector<double>> sp = spectrogram(a, wavinfo->frames, wavinfo->samplerate, 30, 20, 512);

	xAxis = ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atBottom);
	yAxis = ui.waveform_wid_1->axisRect(1)->axis(QCPAxis::atLeft);

	xAxis->setRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0);//设置x轴
	yAxis->setRange(0, wavinfo->samplerate / 2.0);//设置y轴
	//xAxis->setRange(xAxis->range().bounded(0, 6));//限制缩放范围
	//yAxis->setRange(yAxis->range().bounded(0, 10000));//限制缩放范围
	pColorMap = new QCPColorMap(xAxis, yAxis);
	pColorMap->data()->setSize(sp.size(), sp[0].size());
	pColorMap->data()->setRange(QCPRange(0, (double)wavinfo->length / wavinfo->samplerate / 2.0), QCPRange(0, wavinfo->samplerate / 2.0));
	pColorMap->setInterpolate(false);
	pColorMap->setAntialiased(false);//设置是否对对象进行抗锯齿绘制。

	QCPColorScale *colorScale = new QCPColorScale(ui.waveform_wid_1);
	ui.waveform_wid_1->plotLayout()->addElement(1, 1, colorScale); // 右侧添加
	colorScale->setType(QCPAxis::atRight);
	QCPMarginGroup *marginGroup = new QCPMarginGroup(ui.waveform_wid_1);
	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	colorScale->axis()->setLabel("Magnitude (dB SPL)");//色条的名

	pColorMap->setColorScale(colorScale); //热图连接色条
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
			pColorMap->data()->setCell(i, j, sp[i][j] * 6);//设置数据
		}
	}

	
	//ui.waveform_wid_2->rescaleAxes();//重新调节轴、调用后坐标会根据实际情况增加
	ui.waveform_wid_1->replot();//重绘
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