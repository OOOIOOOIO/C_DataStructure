/*
 * ListBasedStack.c
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "ListBasedStack.h"

// 스택 초기화
void stack_init(Stack *pStack){
	pStack->pTop = NULL; // 더미노드 없이 바로 null로 시작
}


// 스택 제거
void stack_destroy(Stack *pStack){
	// 스택이 다 비어질때까지 pop 시키기
	while(!(stack_is_empty(pStack))){
		stack_pop(pStack, NULL);
	}
}


// 스택이 비었는지 확인
int stack_is_empty(Stack *pStack){
	if(pStack->pTop == NULL) return SUCCESS;

	return FAIL;
}


// push : top에 데이터 추가
int stack_push(Stack *pStack, Data data){
	// 새로운 노드 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;

	// 노드를 스택에 추가
	pNewNode->pNext = pStack->pTop;

	// top은 새로이 push된 노드를 가리킨다.
	pStack->pTop = pNewNode;

	return SUCCESS;
}


// pop : top의 데이터 꺼내기
int stack_pop(Stack *pStack, Data *pData){
	if(stack_is_empty(pStack)){
		printf("Empty Stack!\n");
		return FAIL;
	}

	// 삭제할 노드 기억
	Node *deleteNode = pStack->pTop;

	if(pData != NULL) *pData = pStack->pTop->data; // 메인에서 데이터 읽기 (꺼내기)

	pStack->pTop = pStack->pTop->pNext; // top 이동

	free(deleteNode); // pop된 노드 제거 pTop과 같으니까 주소도 같음
	return SUCCESS;
}


// peak : pop의 데이터 읽기
int stack_peek(Stack* pStack, Data* pData){
	if(stack_is_empty(pStack)){
		printf("Empty Stack!\n");
		return FAIL;
	}

	if(pData != NULL) *pData = pStack->pTop->data; // 데이터 읽기 (꺼내기)


	return SUCCESS;
}









