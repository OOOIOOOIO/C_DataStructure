/*
 * arrayPointer.c
 *
 *  Created on: 2021. 7. 5.
 *      Author: polit
 */

#include <stdio.h>
#define SIZE 3

int arNum[SIZE] = {4, 5, 6};

void changeAdr(int*);

// �迭 ������

int main(void){
	int arNum[SIZE] = {1, 2, 3};

	int (*PNum)[SIZE] = &arNum; // �迭������ ���¹�

	for(int i = 0; i < SIZE; i++){
		printf("%d ", *(*PNum + i));
	}

	changeAdr(&PNum);

	for(int i = 0; i < SIZE; i++){
			printf("%d ", *(*PNum + i));
		}

	return 0;
}

void changeAdr(int*arData){
	*arData = arNum;
}
