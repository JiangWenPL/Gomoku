/*
*    Check_Algorithm.c
*    Gomoku Project
*	 Team production.
*	 Team member: Jiang Wen, Huang Nianmei, Li Jianing.
*    This file was created by Wen Jiang on 4/10/2017.
*    Copyright (c) 2017 Wen Jiang, Huang Nianmei, Li Jianing. All rights reserved.
*/
#include"Check_Algorithm.h"
Chess *pHead = NULL;
Chess *pTail = NULL;
int Change_Data(Point* This) {
	if (This->x == RETRACT && This->y == RETRACT) {
		//This case when user press retarct.
		Chess_Pop();
	}
	else if (This->x < CHESS_RANGE_LOWER || This->x > CHESS_RANGE_UPPER || This->y <CHESS_RANGE_LOWER || This->y>CHESS_RANGE_UPPER) {
		//In case of out of range.
		assert(This->x < CHESS_RANGE_LOWER || This->x > CHESS_RANGE_UPPER || This->y <CHESS_RANGE_LOWER || This->y>CHESS_RANGE_UPPER);
	}
	else {
		//Normal status
		Chess_PushBack(This);
	}
}
int Chess_PushBack(Point *This) {
	if (pHead == NULL) {
		//New linked list.
		pHead = (Chess*)malloc(sizeof(*pHead));//Probably have problem.
		assert(pHead);
		pHead->Next = NULL;
		pHead->Prior = NULL;
		pHead->X = This->x;
		pHead->Y = This->y;
		pTail = pHead;
	}
}
int Chess_Pop() {
	int run_status = 0;
	if (pTail == NULL) {
		msgBox("No chess to extract.", "You have not put any chrsss on the check board!", EX_ALEAT_FLAG);
		//In case of free empty linked list.
		run_status = FREE_EMPTY;
	}
	else {
		CheckBoard[pTail->Y][pTail->X] = 0;
		//Put check board back to origin.
		if (pTail->Prior == NULL) {
			//Just have one chess.
			free(pTail);
			pTail = NULL;
			pHead = NULL;
		}
		else {
			Chess *Temp = pTail;
			pTail = pTail->Prior;
			free(Temp);
			pTail->Next = NULL;
		}	
	}
	return run_status;
}
//Check who is winner.