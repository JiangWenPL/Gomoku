#ifndef MAIN_H
#define MAIN_H

#include "acllib.h"
#include "stdio.h"
#include"AI.h"

typedef int status;
//ȫ�ֱ�����������
status Status;

//������������
const int MENU = 0;
const int PLAYING = 1;
const int END = 2;

ACL_Image Checkboard;//�����ͼƬ

int InitialTheGame();//����ͼƬ
int PaintTheGame();//���Ƶ�ǰ��Ϸ����
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);


//Ai module
#endif // !MAIN_H
