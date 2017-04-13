#ifndef MAIN_H
#define MAIN_H

#include "acllib.h"
#include "stdio.h"
#include"AI.h"

typedef int status;
//全局变量定义如下
status Status;

//常量定义如下
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 740;
#define MENU  0
#define PLAYING  1
#define END  2

ACL_Image Checkboard, StartMenu, White, Black;//载入的图片

int InitialTheGame();//载入图片
int PaintTheGame();//绘制当前游戏画面
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);


//Ai module
#endif // !MAIN_H
