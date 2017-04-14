/*
*    main.h
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/10/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#ifndef MAIN_H
#define MAIN_H

#include "acllib.h"
#include "stdio.h"
#include "AI.h"
#include <assert.h>
#include<stdlib.h>
//#include "Check_Algorithm.h"
//Type define.
typedef struct s_Point{
	int x;
	int y;
} Point;
typedef int status;

//Constants
#define MENU  0
#define PLAYING  1
#define END  2//����Ϊ��Ϸ�׶�
#define START_BOTTOM_LEFT_X 0//��ʼ��ť���ĸ�������Ϣ
#define REGRET_BOTTOM_LEFT_X 0//���尴ť���ĸ�������Ϣ
#define BOARD_C0_X  0//������������ߵĵ�0���ߵĺ����� C��ʾ����
#define BOARD_R16_Y 0//�����������±ߵı��ߵ������� R��ʾ����
#define CHESS_SIZE 0
#define BLACKSIDE 1
#define WHITESIDE -1
#define RETRACT -1
#define CHECKBORAD_SIZE 15
ACL_Image Img_Checkboard, Img_StartMenu, Img_WhiteChess, Img_BlackChess;//�����ͼƬ
//Funtion define.
status InitialTheGame();//����ͼƬ
status PaintTheGame();//���Ƶ�ǰ��Ϸ����
status PaintTheChess();//���ݶ�ά���黭������
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);

//Extern variable
extern status Status;
extern int m_Victory;
extern int CheckBoard[CHECKBORAD_SIZE][CHECKBORAD_SIZE];
extern int m_Turn;
//Ai module
#endif // !MAIN_H
