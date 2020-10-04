#include "data.h"
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

void cur(short x, short y) { //커서이동함수
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void showDisplay() {
	for (int i = 0; i < 21; i++) {
		cur(10, 5 + i);
		for (int j = 0; j < 12; j++){
			switch (board[i][j]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("□");  
				break;
			case 2:
				printf("■");
				break;
			case 3:
				printf("▩");
				break;
			default:
				printf("%d ", board[i][j]);
				break;
			}
			
			//printf("%d ", board[i][j]);
		}
		printf("\n");
	}

}

void showfinish(int n) {
	if (n == -1) {
		cur(45, 20);
		printf("게임이 끝났다!!!");
	}
	else if (n != 0) {
		cur(45, 20);
		printf("%d줄을 없앴따!!", n);
	}
}

int levelUp(int level, int n) {   //현재 렙업까지 남은 상태 출력, 레벨업 출력
	if (n == -1) {
		cur(45, 19);
		printf("레벨업!!!");
		cur(45, 15);
		printf("현재 레벨: %d\n", (level+1));
		cur(45, 17);
		printf("다음레벨까지: %d/10\n", 0);
		return 1;
	}
	else {
		cur(45, 15);
		printf("현재 레벨: %d\n", level);
		cur(45, 17);
		printf("다음레벨까지: %d/10\n", n);
		return 0;
	}
}

void showScore(int score) {
	cur(45, 3);
	printf("현재 점수: %d", score);
}

void preview(int type) {
	cur(45, 5);
	printf("다음 도형");
	for (int i = 0; i < 4; i++) {
		cur(45, 6 + i);
		for (int j = 0; j < 4; j++) {
			switch (shape[type][0][i][j]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			default:
				printf("%d ", shape[type][0][i][j]);
				break;
			}
		}
		
	
	}
}