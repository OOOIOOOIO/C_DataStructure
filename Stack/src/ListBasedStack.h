/*
 * ListBasedStack.h
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */

#ifndef LISTBASEDSTACK_H_
#define LISTBASEDSTACK_H_

#define SUCCESS 1
#define FAIL 0

	/*	스택의 데이터 */

typedef int Data;

typedef struct _node{
	Data data; //네모칸 안의 데이터

	struct _node *pNext; // 네모칸 안의 넥스트

}Node;


typedef struct _listStack{
	Node *pTop; // 이번 예제에서는 numData는 사용 안함, pHead노드 느낌

}ListStack;


typedef ListStack Stack;




	/*	스택의 동작	 */

// 스택 초기화
void stack_init(Stack* pStack);

// 스택 제거
void stack_destroy(Stack* pStack);

// 스택이 비었는지 확인
int stack_is_empty(Stack* pStack);

// push : top에 데이터 추가
int stack_push(Stack* pStack, Data data);

// pop : top의 데이터 꺼내기
int stack_pop(Stack* pStack, Data* pData);

// peak : pop의 데이터 읽기
int stack_peek(Stack* pStack, Data* pData);

#endif /* LISTBASEDSTACK_H_ */
