/*ready�� display�� ������ ������
1. �̵��Լ���
2. Ư���� �̵�Ű*/

#include "data.h"

int checkCrush(int type, int rotate, int pY, int pX); //�浹����Ȯ��(�浹�ϸ� 1���)
int downMoving(int type, int rotate, int pY, int pX);	//�Ʒ��� 1ĭ �̵� {Ÿ��, ȸ����, Y��ǥ, X��ǥ}
int leftMoving(int type, int rotate, int pY, int pX);	//�������� 1ĭ �̵� {Ÿ��, ȸ����, Y��ǥ, X��ǥ}
int rightMoving(int type, int rotate, int pY, int pX);	//���������� 1ĭ �̵� {Ÿ��, ȸ����, Y��ǥ, X��ǥ}
int rotating(int type, int rotate, int pY, int pX);	//�ݽð�������� 90�� ȸ�� {Ÿ��, ȸ����, Y��ǥ, X��ǥ}, ȸ������ ��ȯ
void makeTetris(int type, int rotate, int pY, int pX); //������ ������ ������Ŵ(1�� 2��)