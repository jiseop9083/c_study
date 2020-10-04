/*ready와 display를 제외한 나머지
1. 이동함수들
2. 특수한 이동키*/

#include "data.h"

int checkCrush(int type, int rotate, int pY, int pX); //충돌여부확인(충돌하면 1출력)
int downMoving(int type, int rotate, int pY, int pX);	//아래로 1칸 이동 {타입, 회전도, Y좌표, X좌표}
int leftMoving(int type, int rotate, int pY, int pX);	//왼쪽으로 1칸 이동 {타입, 회전도, Y좌표, X좌표}
int rightMoving(int type, int rotate, int pY, int pX);	//오른쪽으로 1칸 이동 {타입, 회전도, Y좌표, X좌표}
int rotating(int type, int rotate, int pY, int pX);	//반시계방향으로 90도 회전 {타입, 회전도, Y좌표, X좌표}, 회전도를 반환
void makeTetris(int type, int rotate, int pY, int pX); //떨어진 도형을 고정시킴(1을 2로)