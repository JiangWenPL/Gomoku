/*
*    main.c
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/10/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"main.h"
#define DEBUG
//Debug mode.
//Global Variable define
status Status;
int m_Victory = 0;
int CheckBoard[CHECKBORAD_SIZE][CHECKBORAD_SIZE] = { 0 };
//1 -> black side victory
//-1 -> white side victory.
int m_Turn = 0;
//So as turn.
//Local variable.
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 740;//Window size.
int Setup() {
	initWindow("Gomoku", DEFAULT, DEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT);
#ifdef DEBUG
	initConsole();
#endif // DEBUG
	Status = MENU;
	//Status = PLAYING;
	registerTimerEvent(&TimerEvent);
	registerMouseEvent(&MouseEvent);
	InitialTheGame();
	return 0;
}

int InitialTheGame()
{
	beginPaint();
	loadImage(".//black.bmp", &Img_BlackChess);
	loadImage(".//white.bmp", &Img_WhiteChess);
	loadImage(".//CheckBoardNew.bmp", &Img_Checkboard);
	loadImage(".//StartMenu.bmp", &Img_StartMenu);
//	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
	return 0;
}

int PaintTheGame()
{
	switch (Status)
	{
	case MENU:
		beginPaint();
		putImage(&Img_StartMenu, 0, 0);
		endPaint();
		break;
	case PLAYING:	
		beginPaint();
		putImage(&Img_Checkboard, 0, 0);
		PaintTheChess();
		endPaint(); 
		break;
	case END:
		beginPaint();
//		putImage(&Vitory, 0, 0);
		endPaint();
		break;
	default:
		break;
	}

	return 0;
}

status PaintTheChess()
{
	return 0;
}

TimerEventCallback TimerEvent(int timerID)
{
	return 0;
}

MouseEventCallback MouseEvent(int x, int y, int button, int event)
{
/*	switch (Status)
	{
	case MENU:
		//如果鼠标event == 2且位于开始按钮范围内，则Status = Playing.
		break;
	case PLAYING:
		break;
	case END:
		break;
	default:
		break;
	}
	根据程序处于的阶段 判断鼠标对应的操作*/
	PaintTheGame();
#ifdef DEBUG
	//Point* ptr=NULL;
	printf("x=%4d, y=%4d, butoton =%d, event = %d\n", x, y, button, event);
#endif // DEBUG
	return 0;
}
