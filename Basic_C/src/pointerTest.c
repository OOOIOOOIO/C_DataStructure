/*
 * pointerTest.c
 *
 *  Created on: 2021. 7. 2.
 *      Author: polit
 */
#include <stdio.h>
//��Ʈ�� ������ �����Ͽ� ����ڿ��� ���� �Է¹��� ��
//�ش� ���� 2��� �ٲ��ִ� voidŸ�� �Լ� ���� �� ���

int main(void){
	int data = 0;
	int* PData = &data;

	scanf("%d", &data);

	fun_1(PData);

	int num = data;
	PData = num;

	fun_2(PData);


	printf("%d\n", *PData);

	return 0;
}

void fun_1(int* data){
	*data *= 3;
}

void fun_2(int* data){
	*data *= *data;
}
