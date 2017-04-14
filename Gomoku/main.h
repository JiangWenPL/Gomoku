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
#define END  2//至此为游戏阶段
#define START_BOTTOM_LEFT_X 0//开始按钮的四个坐标信息
#define REGRET_BOTTOM_LEFT_X 0//悔棋按钮的四个坐标信息
#define BOARD_C0_X  0//定义棋盘最左边的第0条线的横坐标 C表示列线
#define BOARD_R16_Y 0//定义棋盘最下边的边线的纵坐标 R表示行线
#define CHESS_SIZE 0
#define BLACKSIDE 1
#define WHITESIDE -1
#define RETRACT -1
#define CHECKBORAD_SIZE 15
ACL_Image Img_Checkboard, Img_StartMenu, Img_WhiteChess, Img_BlackChess;//载入的图片
//Funtion define.
status InitialTheGame();//载入图片
status PaintTheGame();//绘制当前游戏画面
status PaintTheChess();//根据二维数组画出旗子
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);

//Extern variable
extern status Status;
extern int m_Victory;
extern int CheckBoard[CHECKBORAD_SIZE][CHECKBORAD_SIZE];
extern int m_Turn;
//Ai module
#endif // !MAIN_H
