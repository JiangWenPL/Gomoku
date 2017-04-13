#ifndef MAIN_H
#define MAIN_H

#include "acllib.h"
#include "stdio.h"
#include"AI.h"

typedef int status;
//ȫ�ֱ�����������
status Status;

//������������
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 740;
#define MENU  0
#define PLAYING  1
#define END  2

ACL_Image Checkboard, StartMenu, White, Black;//�����ͼƬ

int InitialTheGame();//����ͼƬ
int PaintTheGame();//���Ƶ�ǰ��Ϸ����
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);


//Ai module
#endif // !MAIN_H
