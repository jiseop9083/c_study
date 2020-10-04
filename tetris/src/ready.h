/* 플래이, 디스플래이를 제외한 나머지
1. random
2. checkfinish
3. removeLine*/

#include "data.h"

int random();	//랜덤으로 도형한개 출력
int removeLine(); //라인 제거와 제거한 개수 리턴, 게임이 끝나면 -1 리턴

int checkRemove(int n, int level); //몇 줄을 없앴는지 출력, 레벨을 올려야할 때는 -1출력
int checkScore(int n, int level); //점수확인