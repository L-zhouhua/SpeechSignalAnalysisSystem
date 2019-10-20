#pragma once
#include <stdio.h>
class WavInfo
{
public:
	double *samplePoint = NULL;//采样点数据
	int samplerate; //采样率（每秒采样个数，单位Hz）
	int frames;     //每个声道的采样点数
	int length;     //总采样点数（frame*channels）
	int channels;   //音道数
	double duration;   //周期
};