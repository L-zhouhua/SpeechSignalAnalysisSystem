#pragma once
#include <stdio.h>
class WavInfo
{
public:
	double *samplePoints = NULL;//����������
	int samplerate; //�����ʣ�ÿ�������������λHz��
	int frames;     //ÿ�������Ĳ�������
	int length;     //�ܲ���������frame*channels��
	int channels;   //������
	double duration;   //����
};