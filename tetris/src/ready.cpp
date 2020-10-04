#include "data.h"
#include <stdlib.h>
#include <stdio.h>



int random() { //��ǥ��(y,x)
	static int type[7] = { 0, }; // ��, ��, L, �ݴ�L, ����, ����, ��
	int choice;
	while (1) {
		if (type[0] == 1 && type[1] == 1 && type[2] == 1 && type[3] == 1 && type[4] == 1 && type[5] == 1 && type[6] == 1) {
			type[0] = 0; type[1] = 0; type[2] = 0; type[3] = 0; type[4] = 0; type[5] = 0; type[6] = 0;
		}
		choice = (rand() % 7);
		if (type[choice] == 1) {
			continue;
		}
		else break;
	}
	type[choice] = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j + 4] = shape[choice][0][i][j];
	
		}
	}

	return choice;
}

int removeLine() {
	int l_count = 0; //line����
	int count;
	for (int i = 19; i >= 0; i--) {
		count = 0;
		for (int j = 1; j < 11; j++) {
			if (board[3][j] > 1) return -1; //���ӳ�

			if (board[i][j] == 2) count++; //�� �� �ϼ� �ȵ�
			if (count == 10) {
				for (int k = i; k >= 4; k--) {
					for (int l = 1; l < 11; l++) {
						if (k == i) {
							board[k][l] = 0;
						}
						else if(board[k][l] == 2){
							board[k][l] = 0;
							board[k + 1][l] = 2;
						}


					}
				}
				l_count += 1;
				i++;
			}
		}
	}
	return l_count;
}

int checkRemove(int n, int level) { //�� ���� ���ݴ��� ���, ������ �÷����� ���� -1���
	static int line = 0;
	line += n;
	if (line >= 10 && level < 10) {
		line = 0;
		return -1;
	}
	else if (line >= 10 && level == 10) return 10;
	else return line;
}

int checkScore(int n, int level) {//���� ����
	static int score = 0;
	if (n > 0) {
		score += n * (10 + (n - 2 + level)); //���� ���ֱ� ���� 10%, ���������� 10%
	}
	return score;
}
