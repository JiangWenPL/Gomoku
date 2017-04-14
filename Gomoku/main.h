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
#define START_BUTTON_LEFT_X 520 //开始按钮的四个坐标信息
#define START_BUTTON_RIGHT_X 890
#define START_BUTTON_UP_Y 440
#define START_BUTTON_DOWN_Y 580
#define REGRET_BUTTON_LEFT_X 870//悔棋按钮的四个坐标信息
#define REGRET_BUTTON_RIGHT_X 1020
#define REGRET_BUTTON_UP_Y 150
#define REGRET_BUTTON_DOWN_Y 260


#define BOARD_C0_X  0//定义棋盘最左边的第0条线的横坐标 C表示列线
#define BOARD_C1_X 153
#define BOARD_C2_X 200
#define BOARD_C3_X 247
#define BOARD_C4_X 294
#define BOARD_C5_X 339
#define BOARD_C6_X 385
#define BOARD_C7_X 432
#define BOARD_C8_X 480
#define BOARD_C9_X 525
#define BOARD_C10_X 572 
#define BOARD_C11_X 618
#define BOARD_C12_X 667
#define BOARD_C13_X 712
#define BOARD_C14_X 759
#define BOARD_C15_X 805

#define BOARD_R1_Y 35
#define BOARD_R2_Y 83
#define BOARD_R3_Y 129
#define BOARD_R4_Y 176
#define BOARD_R5_Y 224
#define BOARD_R6_Y 271
#define BOARD_R7_Y 319
#define BOARD_R8_Y 367
#define BOARD_R9_Y 414
#define BOARD_R10_Y 462
#define BOARD_R11_Y 508
#define BOARD_R12_Y 556
#define BOARD_R13_Y 603
#define BOARD_R14_Y 651
#define BOARD_R15_Y 689
#define BOARD_R16_Y 0//定义棋盘最下边的边线的纵坐标 R表示行线

#define CHESS_SIZE 0
#define BLACKSIDE 1
#define WHITESIDE -1
#define RETRACT -1
#define CHECKBORAD_SIZE 15
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
