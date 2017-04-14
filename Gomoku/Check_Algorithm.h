/*
*    Chexk_Algorithm.h
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/10/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#pragma once
#ifndef CHECK_ALGORITHM_H
#include "main.h"

//VAriable define & extern.
typedef struct S_Chess{
	int X;
	int Y;
	int Side;
	struct S_Chess* Prior;
	struct S_Chess* Next;
}Chess;
extern int m_Victory;
extern int m_Turn;
int Change_Data(Point* This);
int Chess_Pop();
#define EX_ALEAT_FLAG 1
#define CHESS_RANGE_LOWER 0
#define CHESS_RANGE_UPPER 14
#define FREE_EMPTY 1
#endif // !CHECK_ALGORITHM_H
