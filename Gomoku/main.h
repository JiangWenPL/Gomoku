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
//#define DEBUG

#include "acllib.h"
#include "stdio.h"
#include "AI.h"
#include "graphics.h"
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
#define END  2//至此为游戏阶段

#define BLACKSIDE 1
#define WHITESIDE -1
#define RETRACT -1
#define CHECKBORAD_SIZE 15

//Funtion define.
status InitialTheGame();//载入图片
status PaintTheGame();//绘制当前游戏画面
status PaintTheChess();//根据二维数组画出旗子
POINT get_point(int x, int y);//Get the point on the board from the location on the screen.

TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);
int ClearTheBoard();//把二维数组全部元素重置为0
int Change_Data(Point* This);

//Extern variable
extern status Status;
extern int m_Victory;
extern int CheckBoard[CHECKBORAD_SIZE][CHECKBORAD_SIZE];
extern int m_Turn;
//Ai module
#pragma warning(disable :4133 4047 4024)
#endif // !MAIN_H
