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

	/*	큐의 데이터	  */

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


	/*	큐의 동작 	 */

// 큐 초기화
void queue_init(Queue* pq);

// 큐 제거
void queue_destroy(Queue* pq);

//큐가 비어있는지 확인
int queue_is_empty(Queue* pq);

// enqueue 데이터 추가 (back에 추가)
int queue_enq(Queue* pq, Data data);

// dequeue 데이터 추출 (Front에서 추출)
int queue_deq(Queue* pq, Data* pData);

// peak 데이터 읽기 (Front에서 읽기)
int queue_peek(Queue* pq, Data* pData);

#endif /* LISTQUEUE_H_ */
