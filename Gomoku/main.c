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
	initWindow("Gomoku", DEFAULT, DEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT);
	initConsole();
	Status = MENU;
//	Status = PLAYING;
	registerTimerEvent(&TimerEvent);
	registerMouseEvent(&MouseEvent);
	InitialTheGame();
	return 0;
}

int InitialTheGame()
{
	beginPaint();
	loadImage(".//CheckBoardNew.bmp", &Checkboard);
	loadImage(".//StartMenu.bmp", &StartMenu);
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
		putImage(&StartMenu, 0, 0);
		endPaint();
		break;
	case PLAYING:	
		beginPaint();
		putImage(&Checkboard, 0, 0);
		endPaint(); 
		break;
	default:
		break;
	}

	return 0;
}

TimerEventCallback TimerEvent(int timerID)
{
	return 0;
}

MouseEventCallback MouseEvent(int x, int y, int button, int event)
{

	PaintTheGame();

	printf("x=%4d, y=%4d, butoton =%d, event = %d\n", x, y, button, event);
	return 0;
}
