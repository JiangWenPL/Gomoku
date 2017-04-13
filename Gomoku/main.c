/*
*    main.c
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/5/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"main.h"




int Setup() {
	initWindow("Gomoku", DEFAULT, DEFAULT, 1460, 750);
	initConsole();
	registerTimerEvent(&TimerEvent);
	registerMouseEvent(&MouseEvent);
	InitialTheGame();
	return 0;
}

int InitialTheGame()
{
	beginPaint();

	loadImage(".//checkboard.bmp", &Checkboard);
//	loadImage(".//DashBoard.bmp", &DashBoard);
//	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
	return 0;
}

int PaintTheGame()
{
	putImage(&Checkboard, 0, 0);
	return 0;
}

TimerEventCallback TimerEvent(int timerID)
{
	return 0;
}

MouseEventCallback MouseEvent(int x, int y, int button, int event)
{
	beginPaint();
	PaintTheGame();
	endPaint();
	printf("x=%4d, y=%4d, butoton =%d, event = %d\n", x, y, button, event);
	return 0;
}
