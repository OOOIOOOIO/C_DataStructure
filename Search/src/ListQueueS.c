/*
 * ListQueue.c
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */
#include "ListQueueS.h"

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���


// ť �ʱ�ȭ
void queue_init(Queue* pq){

	pq->pFront = NULL;
	pq->pBack = NULL;

}


// ť ����
void queue_destroy(Queue* pq){

	//ť�� �� ����������� dequeue
	while(!(queue_is_empty(pq))){
		queue_deq(pq, NULL);
	}
}


//ť�� ����ִ��� Ȯ��
int queue_is_empty(Queue* pq){

	if(pq->pFront == NULL) return SUCCESS;

	return FAIL;
}


// enqueue ������ �߰� (back�� �߰�)
int queue_enq(Queue* pq, Data data){

	// ���ο� ��� ����
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = data;

	// ť�� ������� ���� �׷��� ���� �� ����
	if(queue_is_empty(pq)){
		pq->pFront = pNewNode;
		pq->pBack = pNewNode;
	}
	else{
		pq->pBack->pNext = pNewNode;
		pq->pBack =pNewNode;
	}

	return SUCCESS;

	// �� LinkedList.c �� list_add() �Լ��� ���غ���
	//    dummy node �� ����Ѱ�(LinkedList)��
	//    �׷��� ������(ListBaseQueue)�� ��. stack�� ��������
	//   dummy node  �� ����ϸ� �ڵ尡 ���� ����������. (�бⰡ ��������)


}


// dequeue ������ ���� (Front���� ����)
int queue_deq(Queue* pq, Data* pData){

	if(queue_is_empty(pq)){
		printf("Queue EMPTY!\n");
		return FAIL;
	}

	if(pData != NULL){
		*pData = pq->pFront->data; // front ������ ����
	}

	Node* deleteNode = pq->pFront;
	pq->pFront = pq->pFront->pNext;
	free(deleteNode);

	return SUCCESS;

}


// peak ������ �б� (Front���� �б�)
int queue_peek(Queue* pq, Data* pData){

	if(queue_is_empty(pq)){
			printf("Queue EMPTY!\n");
			return FAIL;
		}

		if(pData != NULL){
			*pData = pq->pFront->data; // front ������ ����
		}



		return SUCCESS;
}




