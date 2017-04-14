/*
*    Check_Algorithm.c
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/10/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"Check_Algorithm.h"

int Change_Data(Point* This) {
	if (This->x == RETRACT && This->y == RETRACT) {
		Chess_Pop();
	}
}
int Chess_Pop() {
	;
}
//Check who is winner.