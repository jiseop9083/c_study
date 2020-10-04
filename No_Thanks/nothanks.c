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
	printf("<�� ���� ���� ���>\n");
	for (int i = 0; i < len; i++) {
		printf("[%d] %s\n", i + 1, help[i]);
	}
	

}


int randomPick() {	//���� ��ġ���� �������� ���ڸ� ����
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
		printf("�����%d�� ����: ", i + 1);
		for (int j = 0; j < nCount; j++) {
			if ((member + i)->num[j] == 0) break;
			printf("%3.d ", (member+i)->num[j]);
		}
		printf("\n");
		printf("�����%d�� Ĩ�� ����: %d\n", i + 1, (member+i)->chip);
		
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

int play(Member* user, int pick, int *chipCount, int turn) {//����� ��ȣ, ������ ����, Ĩ ����
	const char* str1 = "yes";
	char str2[] = "no";
	char answer[7];
	printf("����: �����%d\n", turn);
	printf("������ �� �ִ� ����: %d\n", pick);
	printf("������ �� �ִ� Ĩ�� ����: %d\n", *chipCount);
	if ((user)->chip == 0) {
		printf("Ĩ�� ������ �����մϴ�\n.");
		(user)->chip = (((user)->chip) + *chipCount);
		numArray((user)->num, pick);
		printf("%d�� ��ū %d���� �����Խ��ϴ�.\n", pick, *chipCount);
		*chipCount = 0;
		return 0; //���� ������
	}
	else {
		printf("�������ڽ��ϱ�? (yes/no)\n");
		while (1) {
			scanf("%s", answer);
			if (strcmp(str1, answer) == 0 || strcmp(answer, "y") == 0)  {
				(user)->chip = (((user)->chip) + *chipCount);
				numArray((user)->num, pick);
				printf("%d�� ��ū %d���� �����Խ��ϴ�.\n", pick, *chipCount);
				*chipCount = 0;
				return 0;
			}
			else if (strcmp(str2, answer) == 0 || strcmp(answer, "n") == 0) {
				printf("Ĩ �� ���� ���ϴ�.\n");
				(user)->chip = ((user)->chip - 1);
				(*chipCount) += 1;
				return pick; //���� �Ȱ�����
			}
			else{
				printf("�ٽ��Է����ֽʽÿ�.(yes/no)\n");
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
			printf("%2.d����", k + 1);
		}
		printf("  ����");
		printf("\n");
		for (int i = 0; i < (*np); i++) {
			printf("�����%d: ", i+1);
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
		printf("�����: �����%d\n", winner + 1);
		printf("\n");





	}
	
}


int main(int argc, char* argv[]) {
	srand(time(NULL));
	const char* arr[9] =
	{ "���� ��ū 11���� ������.",
		"���� ��ġ���� �ϳ��� �����ϸ鼭 �������� ���� �����Ѵ�.",
		"���ڴ� 3~35���� �������� 9���� ���ŵǾ� �� 24���̴�.",
		"���ڸ� �������� ���� ������ ��ū �Ѱ��� ����.",
		"���ڸ� �������� �׿��� ��ū�� ���� ��� ��������.",
		"ī�尡 ������ ������ �ݺ��Ѵ�.",
		"������ ������ ���� ������ �ȴ�.",
		"��, ���ӵ� ���ڰ� ������ ���� ���� ���ڸ� ������ ������ ���ڴ� ������� ������, ��ū�� -1���̴�.",
		"������ ���� ���� ����� �¸��Ѵ�." };

	int mainNum = 0;
	int mainChip = 0;
	for (int i = 0; i < nCount; i++) {
		allnum[i] = i + 3;
	}
	int n ;
	if (argc == 1) {
		printf("conmand-line argument�� ����(3~7)�� �Է��ϸ� �˴ϴ�.\n");
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