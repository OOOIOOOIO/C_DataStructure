/*
 * pointer.c
 *
 *  Created on: 2021. 6. 30.
 *      Author: polit
 */
#include <stdio.h>

// ������ ����ϱ�-1//

int main(void){
	int data = 10;
	int* PData = &data;
	*PData = 30; // data ���� 30���� �ٲ�
	printf("%d\n", data);
	return 0;
}


// ������ ����ϱ� -2//

int main(void){
	int num = 0;
	fun(&num); // ������ ���
	printf("%d\n", num);
	return 0;
}

void fun(int* data){
	*data = 20;
}


// ���� ������ : �������� �ּҰ��� ��� �������

int main(void){
	int data = 10;
	int* PData = &data;
	int** PPData = &PData;

	printf("%p\n", &data);
	printf("%p\n", PData);
	printf("%p\n", PPData); //�ּҰ� �� �Ȱ���

	return 0;
}

void f(int**);

int main(void){
	int data = 10;
	int* PData = &data;

	printf("%d\n", *PData);
	f(&PData); // ���������� ���
	printf("%d\n", *PData);
	return 0;
}

void f(int** x){
	int data = 20;
	*x = &data;
}
