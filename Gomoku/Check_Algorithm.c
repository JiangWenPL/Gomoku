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
	else {
		if (This->x < CHESS_RANGE_LOWER || This->x > CHESS_RANGE_UPPER || This->y <CHESS_RANGE_LOWER || This->y>CHESS_RANGE_UPPER) {
			//In case of out of range.
			assert(This->x < CHESS_RANGE_LOWER || This->x > CHESS_RANGE_UPPER || This->y <CHESS_RANGE_LOWER || This->y>CHESS_RANGE_UPPER);
		}
		else {
			//Normal status
			Chess_PushBack(This);
		}
		Check_Winner(This);
	}
	return 0;
}
int Check_Winner(Point * This)
{
	int xBegin = This->x;
	int yBegin = This->y;
	int is_Victory = 0;
	int Connect_Count;
	int Horizon_Chess, Vertical_Chess;
	//Check Horizon condition
	for (Connect_Count = 0, Horizon_Chess = LEFT_LIMIT; Horizon_Chess < RIGHT_LIMIT+1; Horizon_Chess++) {
		if (Connect_Count == VICTORYCONDITION) break;
		if (xBegin + Horizon_Chess < CHESS_RANGE_LOWER) continue;
		//Becasu from left to cont.
		if (xBegin + Horizon_Chess > CHESS_RANGE_UPPER) break;
		if (CheckBoard[yBegin][xBegin + Horizon_Chess] == m_Turn) Connect_Count++;
		else Connect_Count = 0;
	}
	if (Connect_Count == VICTORYCONDITION) is_Victory = TRUE;
	if (!is_Victory) {
		//Check Vertical condition
		for (Connect_Count = 0, Vertical_Chess = LEFT_LIMIT; Vertical_Chess < RIGHT_LIMIT+1; Vertical_Chess++) {
			if (Connect_Count == VICTORYCONDITION) break;
			if (yBegin + Vertical_Chess < CHESS_RANGE_LOWER) continue;
			//Becasu from left to cont.
			if (yBegin + Vertical_Chess > CHESS_RANGE_UPPER) break;
			if (CheckBoard[yBegin+ Vertical_Chess][xBegin] == m_Turn) Connect_Count++;
			else Connect_Count = 0;
		}
		if (Connect_Count == VICTORYCONDITION) is_Victory = TRUE;
	}
	if (!is_Victory) {
		//Check diag condition
		for (Connect_Count = 0, Vertical_Chess = LEFT_LIMIT, Horizon_Chess = LEFT_LIMIT-1; Horizon_Chess < RIGHT_LIMIT; Vertical_Chess++,Horizon_Chess++) {
			if (Connect_Count == VICTORYCONDITION) break;
			if (yBegin + Vertical_Chess < CHESS_RANGE_LOWER) continue;
			if (xBegin + Horizon_Chess < CHESS_RANGE_LOWER) continue;
			//Becasu from left to cont.
			if (xBegin + Horizon_Chess > CHESS_RANGE_UPPER) break;
			//Becasu from left to cont.
			if (yBegin + Vertical_Chess > CHESS_RANGE_UPPER) break;
			if (CheckBoard[yBegin + Vertical_Chess][xBegin+Horizon_Chess] == m_Turn) Connect_Count++;
			else Connect_Count = 0;
		}
		if (Connect_Count == VICTORYCONDITION) is_Victory = TRUE;
	}
	if (!is_Victory) {
		//Check diag condition
		for (Connect_Count = 0, Vertical_Chess = LEFT_LIMIT, Horizon_Chess = RIGHT_LIMIT+1; Vertical_Chess < RIGHT_LIMIT; Vertical_Chess++, Horizon_Chess--) {
			if (Connect_Count == VICTORYCONDITION) break;
			if (yBegin + Vertical_Chess < CHESS_RANGE_LOWER) continue;
			if (xBegin + Horizon_Chess > CHESS_RANGE_UPPER) continue;
			//Becasu from right top to cont.
			if (xBegin + Horizon_Chess < CHESS_RANGE_LOWER) break;
			//Becasu from right top to cont.
			if (yBegin + Vertical_Chess > CHESS_RANGE_UPPER) break;
			if (CheckBoard[yBegin + Vertical_Chess][xBegin + Horizon_Chess] == m_Turn) Connect_Count++;
			else Connect_Count = 0;
		}
		if (Connect_Count == VICTORYCONDITION) is_Victory = TRUE;
	}
#ifdef DEBUG
	printf("Connect_Count = %d\n", Connect_Count);
#endif // DEBUG

	if (is_Victory) {
		m_Victory = m_Turn;
		Chess_Clean();
	}
	return 0;
}
int Chess_PushBack(Point *This) {
	CheckBoard[This->y][This->x] = m_Turn;
	if (pHead == NULL) {
		//New linked list.
		pHead = (Chess*)malloc(sizeof(*pHead));//Probably have problem.
		assert(pHead);
		//In case of malloc fail.
		pHead->Next = NULL;
		pHead->Prior = NULL;
		pHead->X = This->x;
		pHead->Y = This->y;
		pTail = pHead;
	}
	else {
		pTail->Next = (Chess*)malloc(sizeof(*pTail));
		assert(pTail->Next);
		//In case of malloc fail.
		(pTail->Next)->Prior = pTail;
		pTail = pTail->Next;
		//Move pTail point to the end.
		pTail->Next = NULL;
		pTail->X = This->x;
		pTail->Y = This->y;
	}
	return 0;
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

int Chess_Clean() {
	Chess *clean_Temp = NULL;
	//Clean up whole linked list;
	for (Chess *it = pHead; it; it = clean_Temp) {
		clean_Temp = it->Next;
		free(it);
	}
	pHead = NULL;
	pTail = NULL;
	return 0;
}

//Check who is winner.