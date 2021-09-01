/*
 * LinkedList.h
 *
 *  Created on: 2021. 7. 22.
 *      Author: polit
 */

#ifndef LINKEDLISTS_H_
#define LINKEDLISTS_H_

/*
*	LinkedList 의 ADT
*
*	장점: 삽입, 삭제 유리
*	단점: 조회에 불리
*
*	단점: ArrayList에 비해 용량 UP
*/

#define TRUE 1
#define FALSE 0


/* List의 데이터 */
typedef int Data;


// 노드타입 정의
typedef struct _node{

	Data data; // 노드 데이터

	struct _node *pNext; // 다음 노드 포인터
} Node;



// Linked List 타입 정의
typedef struct _linkedList{
	Node *pHead;// 시작 노드

	Node *pTail;// 끝 노드

	Node *pCurrent;// iteration
	int numData;// 노드의 개수
} LinkedList;


typedef LinkedList List;



/* List의 동작 */

// 리스트 초기화
void list_init(List* pList);

// 리스트 제거
void list_destroy(List* pList);

// 데이터 추가
int list_add(List* pList, Data data);

// n번쨰 데이터 수정
int list_set(List* pList, int n, Data data);

// 데이터 개수
int list_length(List* pList);

// 데이터 조회, iteration 초기화
void list_init_iter(List* pList);

// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List* pList);

// 데이터 조회, iteration 다음 데이터 있나? 확인
int list_hasNext(List* pList);

// 데이터 조회 : n번째 데이터 값 조회
int list_get(List* pList, int n, Data* pData);

// n번째 데이터 삭제
int list_remove(List* pList, int n);

// n번째 데이터 삽입
int list_insert(List* pList, int n, Data data);


// 주어진 pList에서 data가 담김 Node를 찾아서 리턴, 없으면 NULL 리턴
Node * list_search(List *pList, Data data);





#endif /* LINKEDLISTS_H_ */
