#include "data.h"
#include <time.h>
#include <stdio.h>





int checkCrush(int type, int rotate, int pY, int pX) { //타입, 회전도, 위치(y,x)
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (shape[type][rotate][i][j] == 1 && board[pY + i][pX + j] > 1) { //0은 빈블럭, 1은 떨어지는 블럭, 2는 정지된 블럭
				return 1; //충돌함
				
			}
		} 
	}
	return 0; //충돌안함
}

int rightMoving(int type, int rotate, int pY, int pX) {
	if (checkCrush(type, rotate, pY, pX + 1) == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[pY + i][pX + j] == 1) board[pY + i][pX + j] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (shape[type][rotate][i][j] == 1) board[pY + i][pX + 1 + j] = 1;
			}
		}
		return 1;
	}
	else return 0;
}



int leftMoving(int type, int rotate, int pY, int pX) {
	if (checkCrush(type, rotate, pY, pX - 1) == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[pY + i][pX + j] == 1) board[pY + i][pX + j] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (shape[type][rotate][i][j] == 1) board[pY + i][pX - 1 + j] = 1;
			}
		}
		return -1;
	}
	else return 0;
}

int downMoving(int type, int rotate, int pY, int pX) {
	if (checkCrush(type, rotate, pY + 1, pX) == 0) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[pY + i][pX + j] == 1) board[pY + i][pX + j] = 0;
		}
	}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (shape[type][rotate][i][j] == 1) board[pY + i + 1][pX + j] = 1;
			}
		}
		return 1;
	}
	else return 0;
}


int rotating(int type, int rotate, int pY, int pX) {
	if (rotate == 3) {
		if (checkCrush(type, 0, pY, pX) == 0) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (board[pY + i][pX + j] == 1) board[pY + i][pX + j] = 0;
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (shape[type][0][i][j] == 1) board[pY + i][pX + j] = 1;
				}
			}
			return 0;
		}
		else return rotate;
		
	}
	else if (rotate < 3) {
		if (checkCrush(type, rotate + 1, pY, pX) == 0) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (board[pY + i][pX + j] == 1) board[pY + i][pX + j] = 0;
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (shape[type][rotate + 1][i][j] == 1) board[pY + i][pX + j] = 1;
				}
			}
			return rotate + 1;
		}
		else return rotate;
		
	}
	
}

void makeTetris(int type, int rotate, int pY, int pX) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[pY + i][pX + j] == 1) board[pY + i][pX + j] = 2;
		}
	}
}