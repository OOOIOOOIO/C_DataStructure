/*
 * ListQueue.h
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */

#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_

#define SUCCESS 1
#define FAIL 0

	/*	ť�� ������	  */

typedef int Data;

typedef struct _node{
	Data data;
	struct _node* pNext;
}Node;

typedef struct _1Queue{
	Node* pFront;
	Node* pBack;
}LQueue;

typedef LQueue Queue;


	/*	ť�� ���� 	 */

// ť �ʱ�ȭ
void queue_init(Queue* pq);

// ť ����
void queue_destroy(Queue* pq);

//ť�� ����ִ��� Ȯ��
int queue_is_empty(Queue* pq);

// enqueue ������ �߰� (back�� �߰�)
int queue_enq(Queue* pq, Data data);

// dequeue ������ ���� (Front���� ����)
int queue_deq(Queue* pq, Data* pData);

// peak ������ �б� (Front���� �б�)
int queue_peek(Queue* pq, Data* pData);

#endif /* LISTQUEUE_H_ */
