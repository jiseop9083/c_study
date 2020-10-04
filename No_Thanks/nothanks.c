#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int allnum[33];
const int nCount = 33;
int table[10][1000];

typedef struct {
	int chip;
	int num[34];
} Member;


void explain(const char** help, int len) {
	printf("<노 땡스 게임 방법>\n");
	for (int i = 0; i < len; i++) {
		printf("[%d] %s\n", i + 1, help[i]);
	}
	

}


int randomPick() {	//숫자 뭉치에서 랜덤으로 숫자를 꺼냄
	static int count = -1;
	count++;
	if (count == nCount) {
		return -1;
	}
	while (1) {
		int random = (rand() % nCount);
		if (allnum[random] == 0) continue;
		else {
			int num = allnum[random];
			allnum[random] = 0;
			return num;
		}
	}
}

void printSituation(const Member* member, int* np) {
	for (int i = 0; i < *np; i++) {
		printf("사용자%d의 숫자: ", i + 1);
		for (int j = 0; j < nCount; j++) {
			if ((member + i)->num[j] == 0) break;
			printf("%3.d ", (member+i)->num[j]);
		}
		printf("\n");
		printf("사용자%d의 칩의 개수: %d\n", i + 1, (member+i)->chip);
		
	}
	printf("\n");
	
}

void numArray(int arr[34], int num) {
	for (int i = 0; i <= nCount; i++) {
		if (arr[i] == 0 || arr[i] < num) {
			for (int j = nCount-1; j >= i; j--) {
				arr[j + 1] = arr[j];
			}
			arr[i] = num;
			return;
		}
	}
}

int play(Member* user, int pick, int *chipCount, int turn) {//사용자 번호, 가져갈 숫자, 칩 개수
	const char* str1 = "yes";
	char str2[] = "no";
	char answer[7];
	printf("차례: 사용자%d\n", turn);
	printf("가져갈 수 있는 숫자: %d\n", pick);
	printf("가져갈 수 있는 칩의 개수: %d\n", *chipCount);
	if ((user)->chip == 0) {
		printf("칩의 개수가 부족합니다\n.");
		(user)->chip = (((user)->chip) + *chipCount);
		numArray((user)->num, pick);
		printf("%d와 토큰 %d개를 가져왔습니다.\n", pick, *chipCount);
		*chipCount = 0;
		return 0; //숫자 가져감
	}
	else {
		printf("가져가겠습니까? (yes/no)\n");
		while (1) {
			scanf("%s", answer);
			if (strcmp(str1, answer) == 0 || strcmp(answer, "y") == 0)  {
				(user)->chip = (((user)->chip) + *chipCount);
				numArray((user)->num, pick);
				printf("%d와 토큰 %d개를 가져왔습니다.\n", pick, *chipCount);
				*chipCount = 0;
				return 0;
			}
			else if (strcmp(str2, answer) == 0 || strcmp(answer, "n") == 0) {
				printf("칩 한 개를 냅니다.\n");
				(user)->chip = ((user)->chip - 1);
				(*chipCount) += 1;
				return pick; //숫자 안가져감
			}
			else{
				printf("다시입력해주십시오.(yes/no)\n");
				continue;
			}
		}
		
	}
}

int checkscore(Member* user, int score, int i) {
	if (user->num[i] == 0) return (0 - (user->chip));
	if (user->num[i] != user->num[i + 1] + 1) {
		score = user->num[i] + checkscore(user, score, i + 1); 
	}
	else {
		score = checkscore(user, score, i + 1);
	}
	return score;
}



void makeTable(Member* user, int* np, int print) {
	int min = 0;
	int winner;
	int score = 0;
	
	static int t = 0;
	if (!print) {
		for (int i = 0; i < (*np); i++) {
			table[i][t] = checkscore(user + i, 0, 0);
		}
		t++;
	}
	else if (print) {
		printf("         ");
		for (int k = 0; k < t; k++) {
			printf("%2.d바퀴", k + 1);
		}
		printf("  최종");
		printf("\n");
		for (int i = 0; i < (*np); i++) {
			printf("사용자%d: ", i+1);
			for (int j = 0; j < t; j++) {
				printf("%6.d", table[i][j]);
			}
			score = checkscore(user + i, 0, 0);
			printf("%6.d", score);
			if (i == 0 || min > score) {
				min = score;
				winner = i;
			}
			printf("\n");
		}
		printf("우승자: 사용자%d\n", winner + 1);
		printf("\n");





	}
	
}


int main(int argc, char* argv[]) {
	srand(time(NULL));
	const char* arr[9] =
	{ "각자 토큰 11개씩 가진다.",
		"숫자 뭉치에서 하나씩 오픈하면서 가져갈지 말지 결정한다.",
		"숫자는 3~35까지 무작위로 9개가 제거되어 총 24개이다.",
		"숫자를 가져가고 싶지 않으면 토큰 한개를 낸다.",
		"숫자를 가져가면 쌓여진 토큰과 숫자 모두 가져간다.",
		"카드가 없어질 때까지 반복한다.",
		"가져간 숫자의 합이 점수가 된다.",
		"단, 연속된 숫자가 있으면 가장 작은 숫자를 제외한 나머지 숫자는 계산하지 않으며, 토큰은 -1점이다.",
		"점수가 가장 작은 사람이 승리한다." };

	int mainNum = 0;
	int mainChip = 0;
	for (int i = 0; i < nCount; i++) {
		allnum[i] = i + 3;
	}
	int n ;
	if (argc == 1) {
		printf("conmand-line argument로 숫자(3~7)를 입력하면 됩니다.\n");
		n = 3;
		}
	else{
		n = atoi(argv[1]);
	}
	for (int i = 0; i < 9; i++) randomPick();

	Member* member = (Member*)malloc(n * sizeof(Member));
	for (int i = 0; i < n; i++) { 
		member[i].chip = 11;
		for (int j = 0; j <= nCount; j++) {
			member[i].num[j] = 0;
		}
	}
	int turn = 0;
	explain(arr, sizeof(arr)/sizeof(char*));
	while (1) {
		printSituation(member, &n);
		if (!mainNum) mainNum = randomPick();
		if (mainNum == -1) {
			break;
		}
		mainNum = play(member + (turn % n), mainNum, &mainChip, (turn%n)+1);
		turn++;
		if(!(turn%n)) makeTable(member, &n, 0);
	}
	makeTable(member, &n, 1);
	free(member);

	return 0;
}