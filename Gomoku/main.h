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
const int WINDOW_HEIGHT = 740;//至此为窗口尺寸
#define MENU  0
#define PLAYING  1
#define END  2//至此为游戏阶段
#define START_BOTTOM_LEFT_X 0//开始按钮的四个坐标信息
#define REGRET_BOTTOM_LEFT_X 0//悔棋按钮的四个坐标信息
#define BOARD_C0_X  0//定义棋盘最左边的第0条线的横坐标 C表示列线
#define BOARD_R16_Y 0//定义棋盘最下边的边线的纵坐标 R表示行线
#define CHESS_SIZE 0

ACL_Image Checkboard, StartMenu, WhiteChess, BlackChess;//载入的图片

status InitialTheGame();//载入图片
status PaintTheGame();//绘制当前游戏画面
status PaintTheChess();//根据二维数组画出旗子
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);


//Ai module
#endif // !MAIN_H
