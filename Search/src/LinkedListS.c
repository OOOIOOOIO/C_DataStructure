/*
 * LinkedList.c
 *
 *  Created on: 2021. 7. 22.
 *      Author: polit
 */

#include "LinkedListS.h"

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오



	/* List의 동작 */

	// 리스트 초기화
	void list_init(List* pList){
		pList->pHead = (Node*)malloc(sizeof(Node));
		pList->pHead->pNext = NULL;
		pList->pTail = pList->pHead;

		pList->numData = 0;

		//printf("리스트 초기화\n");
	}




	// 데이터 추가
	int list_add(List* pList, Data data){
		// 새로운 node 생성
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		pNewNode->data = data;

		// tail이 가리키던 node의 next를 새로운 node에 연결
		pList->pTail->pNext = pNewNode;

		// tail 이동
		pList->pTail = pNewNode;

		(pList->numData)++;

		return TRUE;
	}


	// n번쨰 데이터 수정
	int list_set(List* pList, int n, Data data){
		if(n >= pList->numData) return FALSE;

		//head부터 시작해서 n번째 노드 찾아가기, iteration 사용
		list_init_iter(pList);
		int i = 0; // 현재 몇번째 노드인지
		while(list_hasNext(pList)){
			list_next(pList);
			if(i >= n)break;	// n번쨰 노드 찾음!
			i++;
		}
		// 위 while문이 끝나면 pCurrent는 n번째 노드를 가리키고 있음
		//printf("%d번째 데이터 수정%d ---> %d\n", n, pList->pCurrent->data, data);

		pList->pCurrent->data = data;

		return TRUE;
	}


	// 데이터 개수
	int list_length(List* pList){

		return pList->numData;
	}


	// 데이터 조회, iteration 초기화
	void list_init_iter(List* pList){
		pList->pCurrent = pList->pHead; //첫번째 pHead는 더미노드로 리스트의 -1과 같음

	}


	// 데이터 조회, iteration 다음 데이터 추출
	Data list_next(List* pList){
		pList->pCurrent = pList->pCurrent->pNext; // 우선 current를 한발 앞으로 이동

		return pList->pCurrent->data;

	}


	// 데이터 조회, iteration 다음 데이터 있나? 확인
	int list_hasNext(List* pList){
		if( pList->pCurrent->pNext == NULL){ // 다음 노드 존재여부 확인?
		return FALSE;
		}

		return TRUE;

	}


	// 데이터 조회 : n번째 데이터 값 조회
	int list_get(List* pList, int n, Data* pData){

		if(n >= pList->numData) return FALSE;

		//head부터 시작해서 n번째 노드 찾아가기, iteration 사용
		list_init_iter(pList);
		int i = 0; // 현재 몇번째 노드인지
		while(list_hasNext(pList)){
			list_next(pList);
			if(i >= n)break;	// n번쨰 노드 찾음!
			i++;
		}

		// n번째 데이터를 매개변수에 담아줌
		*pData = pList->pCurrent->data;

		return TRUE;
	}


	// n번째 데이터 삭제
	int list_remove(List* pList, int n){
		if(n >= pList->numData) return FALSE;

		// n번째 노드 삭제하려면
		// n번째 뿐 아니라 n-1 번째 노드 정보도 알아야 한다
		// 즉. 이전 노드(previous node) 또한 알아야 한다.


		list_init_iter(pList);
		int i = 0;
		Node* pPrev = NULL; // 이전 노드를 기억할 포인터

		while(list_hasNext(pList)){
			// pCurrent를 이동하기 전에 pCurrent 값을 '이전 노드'로 기억해두어야 한다.
			pPrev = pList->pCurrent;
			list_next(pList);
			if(i >= n)break;	// n번쨰 노드 찾음!
			i++;
		}

		// 위 while 문이 끝나면
			// pCurrent 는 n번째 노드를,
			// pPrev 는 n-1번째 노드를 가리키고 있다

			// 순서 잘 생각해야 한다.  순서 바뀌면 엉망된다.

		// 삭제 진행
		pPrev->pNext = pList->pCurrent->pNext;

		// 만약 tail이 삭제할 노드였다면 tail 값도 수정해야 한다.
		if(pList->pCurrent == pList->pTail){
			pList->pTail = pPrev;
		}

		//printf("%d번째 데이터 %d 삭제\n", n, pList->pCurrent->data);

		free(pList->pCurrent); // 삭제

		pList->numData--; // 삭제해서 노드의 개수 -1 해줌


		return TRUE;
	}

	// 데이터 삽입 : n번째 위치에 data 삽입
	// 맨뒤에 삽입(추가)하는 것도 허용
	// n번째 데이터 삽입
	int list_insert(List* pList, int n, Data data){
		if( n > pList->numData) return FALSE;

		// 새로운 노드 생성
		Node *pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		pNewNode->data = data;

		// 1. 첫번째 데이터이거나 맨끝에 추가하면 add()와 동일
		if(pList->numData == 0 || n == pList->numData ){
			pList->pTail->pNext = pNewNode;
			pList->pTail = pNewNode;
		}
		else{ // 2. n번째 노드에 삽입하려면  n-1번째 노드, 직전노드(previous node) 또한 알아야한다.
			list_init_iter(pList);
			int i = 0;
			Node* pPrev = NULL; // 이전 노드를 기억할 포인터

			while(list_hasNext(pList)){
				// pCurrent를 이동하기 전에 pCurrent 값을 '이전 노드'로 기억해두어야 한다.
				pPrev = pList->pCurrent;
				list_next(pList);
				if(i >= n)break;	// n번쨰 노드 찾음!
				i++;
			}

			// 삽입 동작 수행
			pPrev->pNext = pNewNode;// 이전노드는 새로운 노드를 가리키고
			pNewNode->pNext = pList->pCurrent;//새로운 노드는 기존의 n번째 노드를 가리키면 된다.

		}

		//printf("[%d]번째에 데이터 %d 삽입\n", n, data);
		(pList->numData)++;

		return TRUE;
	}

	// 리스트 제거
	void list_destroy(List* pList){
		list_init_iter(pList);

		Node* pPrev = NULL; // 이전 노드를 기억할 포인터

		while(list_hasNext(pList)){
			// pCurrent를 이동하기 전에 pCurrent 값을 '이전 노드'로 기억해두어야 한다.
			pPrev = pList->pCurrent;
			list_next(pList);
			free(pPrev); // 커런트가 머물렀던 노드 삭제

		}
		pList->pHead = NULL;
		pList->pTail = NULL;
		pList->numData = 0;
		//printf("리스트 소멸\n");
	}


	// 탐색
	Node * list_search(List *pList, Data data)
	{
		pList->pCurrent = pList->pHead;   // head 부터 검색
		while (pList->pCurrent->pNext != NULL)
		{
			pList->pCurrent = pList->pCurrent->pNext;
			if (pList->pCurrent->data == data)
				return pList->pCurrent;  // 찾으면 해당 노드 리턴
		}
		return NULL;   // 없으면 NULL 리턴
	}








