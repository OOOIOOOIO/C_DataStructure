/*
 * ListBasedStack.c
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

#include "ListBasedStack.h"

// ���� �ʱ�ȭ
void stack_init(Stack *pStack){
	pStack->pTop = NULL; // ���̳�� ���� �ٷ� null�� ����
}


// ���� ����
void stack_destroy(Stack *pStack){
	// ������ �� ����������� pop ��Ű��
	while(!(stack_is_empty(pStack))){
		stack_pop(pStack, NULL);
	}
}


// ������ ������� Ȯ��
int stack_is_empty(Stack *pStack){
	if(pStack->pTop == NULL) return SUCCESS;

	return FAIL;
}


// push : top�� ������ �߰�
int stack_push(Stack *pStack, Data data){
	// ���ο� ��� ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;

	// ��带 ���ÿ� �߰�
	pNewNode->pNext = pStack->pTop;

	// top�� ������ push�� ��带 ����Ų��.
	pStack->pTop = pNewNode;

	return SUCCESS;
}


// pop : top�� ������ ������
int stack_pop(Stack *pStack, Data *pData){
	if(stack_is_empty(pStack)){
		printf("Empty Stack!\n");
		return FAIL;
	}

	// ������ ��� ���
	Node *deleteNode = pStack->pTop;

	if(pData != NULL) *pData = pStack->pTop->data; // ���ο��� ������ �б� (������)

	pStack->pTop = pStack->pTop->pNext; // top �̵�

	free(deleteNode); // pop�� ��� ���� pTop�� �����ϱ� �ּҵ� ����
	return SUCCESS;
}


// peak : pop�� ������ �б�
int stack_peek(Stack* pStack, Data* pData){
	if(stack_is_empty(pStack)){
		printf("Empty Stack!\n");
		return FAIL;
	}

	if(pData != NULL) *pData = pStack->pTop->data; // ������ �б� (������)


	return SUCCESS;
}









