#include "play.h"
#include "ready.h"
#include "display.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

#define LEFT 75
#define RIGHT 77
#define CHANGE 72
#define DOWN 80

int fallX = 0;
int fallY = 0;
int fallType = 0;
int fallRotating = 0;

void modTick(int delayTime) {
	int n;
	int play = 1;
	char c;
	while (play) {
		int start = clock();
		while ((clock() - start) <= delayTime) {
			if (_kbhit()) {
				c = _getch();
				if (c == -32) {
					c = _getch();
					switch (c) {
					case LEFT:
						fallX += leftMoving(fallType, fallRotating, fallY, fallX);
						showDisplay();
						break;
					case RIGHT:
						fallX += rightMoving(fallType, fallRotating, fallY, fallX);
						showDisplay();
						break;
					case CHANGE:
						fallRotating = rotating(fallType, fallRotating, fallY, fallX);
						showDisplay();
						break;
					case DOWN:
						fallY += downMoving(fallType, fallRotating, fallY, fallX);
						showDisplay();
						break;
					}
				}
			}
		}
		if (checkCrush(fallType, fallRotating, fallY + 1, fallX) == 0) {
			fallY += downMoving(fallType, fallRotating, fallY, fallX);
			showDisplay();
		}
		else {
			play = 0;
			makeTetris(fallType, fallRotating, fallY, fallX);
			showDisplay();
			break;
		}
	}
}


void makeShape(int next) {
	fallType = next;
	fallRotating = 0;
	fallX = 4;
	fallY = 0;
}

int main() {


	int level = 1;
	int next = random();
	srand((unsigned)time(NULL));
	int n;
	int speed[10] = { 600, 500, 430, 300, 250, 200, 150, 115, 85, 50 };

	showDisplay();
	n = 0;
	while (1) {
		makeShape(next);
		next = random();
		preview(next);
		showScore(checkScore(n, level)); //점수 추가
		level += levelUp(level, checkRemove(n, level)); //레벨업
		modTick(speed[level - 1]);
		n = removeLine(); //라인 제거
		
		showfinish(n);
		
		if (n == -1) break;
	}

	return  0;
}