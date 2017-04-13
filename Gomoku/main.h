#ifndef MAIN_H
#define MAIN_H

#include "acllib.h"
#include "stdio.h"
#include"AI.h"

typedef int status;
//ȫ�ֱ�����������
status Status;

//������������
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 740;//����Ϊ���ڳߴ�
#define MENU  0
#define PLAYING  1
#define END  2//����Ϊ��Ϸ�׶�
#define START_BOTTOM_LEFT_X 0//��ʼ��ť���ĸ�������Ϣ
#define REGRET_BOTTOM_LEFT_X 0//���尴ť���ĸ�������Ϣ
#define BOARD_C0_X  0//������������ߵĵ�0���ߵĺ����� C��ʾ����
#define BOARD_R16_Y 0//�����������±ߵı��ߵ������� R��ʾ����
#define CHESS_SIZE 0

ACL_Image Checkboard, StartMenu, WhiteChess, BlackChess;//�����ͼƬ

status InitialTheGame();//����ͼƬ
status PaintTheGame();//���Ƶ�ǰ��Ϸ����
status PaintTheChess();//���ݶ�ά���黭������
TimerEventCallback TimerEvent(int timerID);
MouseEventCallback MouseEvent(int x, int y, int button, int event);


//Ai module
#endif // !MAIN_H
