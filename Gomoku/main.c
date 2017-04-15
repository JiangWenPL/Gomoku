/*
*    main.c
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/10/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"main.h"
//#define DEBUG
//Debug mode.
//Global Variable define
status Status;
ACL_Image Img_Checkboard, Img_StartMenu, Img_WhiteChess, Img_BlackChess, Img_BlackWin, Img_WhiteWin;//载入的图片
ACL_Sound Snd_Background, Snd_Victory, Snd_PutChess;
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
	freopen("Error_Log.txt", "w", stderr);
	//Redirect stderr to our error log file.
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
	loadImage(".//win_black.bmp", &Img_BlackWin);
	loadImage(".//win_white.bmp", &Img_WhiteWin);
	loadSound(".//BackGround.mp3", &Snd_Background);
	loadSound(".//DropChess.mp3", &Snd_PutChess);
	loadSound(".//Victory.mp3", &Snd_Victory);
	endPaint();
	m_Turn = 1;
	playSound(Snd_Background, 1);
	return 0;
}

TimerEventCallback TimerEvent(int timerID)
{
	return 0;
}

MouseEventCallback MouseEvent(int x, int y, int button, int event)
{
	POINT point;
	if (button != 1 || event != 2)return 0;
	else {
		switch (Status)
		{
		case MENU:
			if (x<START_BUTTON_RIGHT_X&&x>START_BUTTON_LEFT_X&&y > START_BUTTON_UP_Y&&y < START_BUTTON_DOWN_Y) {
				Status = PLAYING;
			}		//如果鼠标event == 2且位于开始按钮范围内，则Status = Playing.
			break;
		case PLAYING:
			if (x<BOARD_C14_X + HALF_CHESS_SIZE&&x>BOARD_C0_X - HALF_CHESS_SIZE&&y > BOARD_R0_Y - HALF_CHESS_SIZE&&y < BOARD_R14_Y + HALF_CHESS_SIZE) {
				point = get_point(x, y);
				if (CheckBoard[point.y][point.x] == 0) {
					Change_Data(&point);
					m_Turn = -m_Turn;
					playSound(Snd_PutChess, 0);
					if (m_Victory != 0)Status = END;
				}
#ifdef DEBUG
				printf("point.x = %d   point.y = %d\n", point.x, point.y);
				for (int i = 0; i < 15; i++) {
					for (int j = 0; j < 15; j++) {
						printf("%2d", CheckBoard[i][j]);
					}
					printf("\n");
				}
				printf("m_Vicotriy= %d\n", m_Victory);
#endif // DEBUG
			}
			 else if (x > REGRET_BUTTON_LEFT_X&&x < REGRET_BUTTON_RIGHT_X&&y<REGRET_BUTTON_DOWN_Y&&y>REGRET_BUTTON_UP_Y) {
				point.x = point.y = -1;
				Change_Data(&point);
			}
			break;
		case END:
			if (x<START_BUTTON_RIGHT_X&&x>START_BUTTON_LEFT_X&&y > START_BUTTON_UP_Y&&y < START_BUTTON_DOWN_Y) {
				Status = MENU;

				ClearTheBoard();//涉及数据层的附加函数
			}		
			
			break;
		default:
			break;
		}
		/*根据程序处于的阶段 判断鼠标对应的操作*/
		PaintTheGame();
	}
#ifdef DEBUG
	//Point* ptr=NULL;
	printf("Snd_Background=%d\n", Snd_Background);
	//printf("x=%4d, y=%4d, butoton =%d, event = %d\n", x, y, button, event);
#endif // DEBUG
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
		playSound(Snd_Victory, 1);
		if (m_Turn == -BLACKSIDE)putImage(&Img_BlackWin, 0, 0);
		else if(m_Turn == -WHITESIDE)putImage(&Img_WhiteWin, 0, 0);
		endPaint();
		break;
	default:
		break;
	}

	return 0;
}

status PaintTheChess()
{
	int i, j, x, y;
	for(i=0;i<CHECKBORAD_SIZE;i++)
		for (j = 0; j < CHECKBORAD_SIZE; j++) {
			x = BOARD_C0_X + i*BOARD_BOX_SIZE;
			y = BOARD_R0_Y + j*BOARD_BOX_SIZE;
			if (CheckBoard[j][i] == BLACKSIDE)putImage(&Img_BlackChess,x-HALF_CHESS_SIZE,y-HALF_CHESS_SIZE);
			else if(CheckBoard[j][i] == WHITESIDE)putImage(&Img_WhiteChess, x - HALF_CHESS_SIZE, y - HALF_CHESS_SIZE);
		}
	return 0;
}


POINT get_point(int x, int y)
{
	POINT point;
	int row, col;
	col = (x - BOARD_C0_X + HALF_CHESS_SIZE) / BOARD_BOX_SIZE;
	row = (y - BOARD_R0_Y + HALF_CHESS_SIZE) / BOARD_BOX_SIZE;
	point.x = col;
	point.y = row;
	return point;
}


int ClearTheBoard() {
	int i, j;
	for (i = 0; i < CHECKBORAD_SIZE; i++)
		for (j = 0; j < CHECKBORAD_SIZE; j++)
			CheckBoard[i][j] = 0;
}