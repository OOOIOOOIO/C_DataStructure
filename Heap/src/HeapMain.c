/*
 * HeapMain.c
 *
 *  Created on: 2021. 8. 2.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "Heap.h"


int DataPriorityComp(HData ch1, HData ch2){
	return ch1 - ch2; // max-heap���� �۵�
	//return ch2 -ch1 // min-heap
}


int main(void){
	Heap heap; // ����ü ��ü����

	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	heap_insert(&heap, 15);
	heap_insert(&heap, 10);
	heap_insert(&heap, 3);
	heap_insert(&heap, 1);

	while(!(heap_is_empty(&heap))){
			printf("%d ", heap_delete(&heap)); // 30 - 20 - 15 - 10
		}

	//---------------------------------------
	printf("\n");
	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);
	heap_insert(&heap, 3);  // �߰�
	heap_insert(&heap, 2);  // ��� �ǳ�?
	heap_insert(&heap, 10); // ��� �ǳ�?
	heap_insert(&heap, 1);  // ��� �ǳ�?



	while(!(heap_is_empty(&heap))){
		printf("%d ", heap_delete(&heap)); // 30 - 20 - 15 - 10
	}

	return 0;
}



