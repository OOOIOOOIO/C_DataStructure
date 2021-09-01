/*
 * ListQueue.c
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */
#include "ListQueueS.h"

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오


// 큐 초기화
void queue_init(Queue* pq){

	pq->pFront = NULL;
	pq->pBack = NULL;

}


// 큐 제거
void queue_destroy(Queue* pq){

	//큐가 다 비어질때까지 dequeue
	while(!(queue_is_empty(pq))){
		queue_deq(pq, NULL);
	}
}


//큐가 비어있는지 확인
int queue_is_empty(Queue* pq){

	if(pq->pFront == NULL) return SUCCESS;

	return FAIL;
}


// enqueue 데이터 추가 (back에 추가)
int queue_enq(Queue* pq, Data data){

	// 새로운 노드 생성
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = data;

	// 큐가 비어있을 때와 그렇지 않을 때 구분
	if(queue_is_empty(pq)){
		pq->pFront = pNewNode;
		pq->pBack = pNewNode;
	}
	else{
		pq->pBack->pNext = pNewNode;
		pq->pBack =pNewNode;
	}

	return SUCCESS;

	// ※ LinkedList.c 의 list_add() 함수와 비교해보자
	//    dummy node 를 사용한것(LinkedList)와
	//    그렇지 않은것(ListBaseQueue)도 비교. stack도 마찬가지
	//   dummy node  를 사용하면 코드가 더욱 간결해진다. (분기가 적어진다)


}


// dequeue 데이터 추출 (Front에서 추출)
int queue_deq(Queue* pq, Data* pData){

	if(queue_is_empty(pq)){
		printf("Queue EMPTY!\n");
		return FAIL;
	}

	if(pData != NULL){
		*pData = pq->pFront->data; // front 데이터 추출
	}

	Node* deleteNode = pq->pFront;
	pq->pFront = pq->pFront->pNext;
	free(deleteNode);

	return SUCCESS;

}


// peak 데이터 읽기 (Front에서 읽기)
int queue_peek(Queue* pq, Data* pData){

	if(queue_is_empty(pq)){
			printf("Queue EMPTY!\n");
			return FAIL;
		}

		if(pData != NULL){
			*pData = pq->pFront->data; // front 데이터 추출
		}



		return SUCCESS;
}




