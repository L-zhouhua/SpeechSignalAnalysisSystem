#pragma once
#include <stdio.h>
class WavInfo
{
public:
	double *samplePoint = NULL;//����������
	int samplerate; //�����ʣ�ÿ�������������λHz��
	int frames;     //ÿ�������Ĳ�������
	int length;     //�ܲ���������frame*channels��
	int channels;   //������
	double duration;   //����
};