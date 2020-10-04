#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void explain() {
	printf("please tap enter key to play streams game\n");
	char ch = getchar();
	while (ch != '\n') {
		printf("please tap enter key to play streams game\n");
		ch = getchar();
	}
}

int randomChoice(){  //1~30 랜덤숫자 반환
	static int list[] = { 0 };
	int i = ((rand()+1) % 30);
	while (list[i]) {
		i = ((rand() % 30));
	}
	int out = i+1;
	list[i] = 1;
	return out;
}


int calculateScore(int* board) {
	int score[20] = { 0 };
	int count = 0;
	int table[20] = { 0,1,3,5,7,9,11,15,20,25,30,35,40,50,60,70,85,100,150,300 };
	int total = 0;
	for(int i = 0; i <19; i++){
		if (board[i] < board[i + 1]) {
			count++;
		}
		else if (board[i] > board[i + 1]) {
			score[count]++;
			count = 0;
		}
	}
	score[count]++;
	for (int i = 0; i < 20; i++) {
		if (score[i] != 0) {
			total += (table[i] * score[i]);
		}
	}
	return total;
}


void displayBoard(int* board){
	printf("board: ");
	for (int i = 0; i < 20; i++) {
		if (board[i] == 0) {
			printf("  _");
		}
		else {
			printf("%3.d", board[i]);
		}	
	}
	printf("\nnumber:");
	for (int i = 1; i <= 20; i++) {
		printf("%3.d", i);	
	}
	printf("\n");
}

void play(int* board) {
	
	for (int i = 1; i <= 20; i++) {
		int n = randomChoice();
		printf("You choice number %d\n", n);
		printf("Where you like to put it?\n");
		displayBoard(board);
		int t;
		printf("enter: ");
		scanf("%d", &t);
		while (1) {
			if (t < 1 || t > 20 || board[t-1] != 0) {
				printf("Please choice number again!\n");
				printf("enter: ");
				scanf("%d", &t);
			}
			else {
				break;
			}
		}
		board[t - 1] = n;
		
		
	}
	printf("game is over!\n");
	displayBoard(board);
	printf("Your score is %d\n\n\n", calculateScore(board));
}

int main() {
	srand((unsigned)time(NULL));
	explain();
	char an;
	int board[20];
	memset(board, 0, sizeof(board));
	while (1) {
		play(board);
		printf("do you want play again?(y or n)\n\n");
		scanf(" %c", &an);
		if (an == 'n') {
			break;
		}
		memset(board, 0, sizeof(board));
	}
	
	return 0;
}