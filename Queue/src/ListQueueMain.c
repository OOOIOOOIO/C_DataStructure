/*
 * ListQueueMain.c
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "ListQueue.h"

int main(void){
	// Queue ���� �� �ʱ�ȭ
	Queue q; // ����ü ����
	Data data;

	queue_init(&q); // ť �ʱ�ȭ

	// ������ �ֱ� enqueue
	queue_enq(&q, 1); // front <-- [1] <-- back
	queue_enq(&q, 2); // front <-- [1 2] <-- back
	queue_enq(&q, 3); // front <-- [1 2 3] <-- back
	queue_enq(&q, 4); // front <-- [1 2 3 4] <-- back
	queue_enq(&q, 5); // front <-- [1 2 3 4 5] <-- back


	// ������ ������ dequeue
	while(!(queue_is_empty(&q))){
		queue_deq(&q, &data);
		printf("deq --> %d\n", data); // ��� 1 2 3 4 5 ������ pop
	}




	queue_destroy(&q); // ť ����


	return 0;
}


