/* �÷���, ���÷��̸� ������ ������
1. random
2. checkfinish
3. removeLine*/

#include "data.h"

int random();	//�������� �����Ѱ� ���
int removeLine(); //���� ���ſ� ������ ���� ����, ������ ������ -1 ����

int checkRemove(int n, int level); //�� ���� ���ݴ��� ���, ������ �÷����� ���� -1���
int checkScore(int n, int level); //����Ȯ��