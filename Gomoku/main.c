/*
*    main.c
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/5/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"main.h"

int InitialTheGame();

int Setup() {
	initWindow("Gomoku", DEFAULT, DEFAULT, 1536, 802);
	InitialTheGame();
	return 0;
}

int InitialTheGame()
{
	beginPaint();
	ACL_Image Checkboard, DashBoard;
	loadImage(".//checkboard.bmp", &Checkboard);
	putImage(&Checkboard, 0, 0);
//	loadImage(".//DashBoard.bmp", &DashBoard);
//	putImage(&DashBoard, DASHBOARDX, DASHBOARDY);
	endPaint();
	return 0;
}
