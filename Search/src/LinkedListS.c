/*
 * LinkedList.c
 *
 *  Created on: 2021. 7. 22.
 *      Author: polit
 */

#include "LinkedListS.h"

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���



	/* List�� ���� */

	// ����Ʈ �ʱ�ȭ
	void list_init(List* pList){
		pList->pHead = (Node*)malloc(sizeof(Node));
		pList->pHead->pNext = NULL;
		pList->pTail = pList->pHead;

		pList->numData = 0;

		//printf("����Ʈ �ʱ�ȭ\n");
	}




	// ������ �߰�
	int list_add(List* pList, Data data){
		// ���ο� node ����
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		pNewNode->data = data;

		// tail�� ����Ű�� node�� next�� ���ο� node�� ����
		pList->pTail->pNext = pNewNode;

		// tail �̵�
		pList->pTail = pNewNode;

		(pList->numData)++;

		return TRUE;
	}


	// n���� ������ ����
	int list_set(List* pList, int n, Data data){
		if(n >= pList->numData) return FALSE;

		//head���� �����ؼ� n��° ��� ã�ư���, iteration ���
		list_init_iter(pList);
		int i = 0; // ���� ���° �������
		while(list_hasNext(pList)){
			list_next(pList);
			if(i >= n)break;	// n���� ��� ã��!
			i++;
		}
		// �� while���� ������ pCurrent�� n��° ��带 ����Ű�� ����
		//printf("%d��° ������ ����%d ---> %d\n", n, pList->pCurrent->data, data);

		pList->pCurrent->data = data;

		return TRUE;
	}


	// ������ ����
	int list_length(List* pList){

		return pList->numData;
	}


	// ������ ��ȸ, iteration �ʱ�ȭ
	void list_init_iter(List* pList){
		pList->pCurrent = pList->pHead; //ù��° pHead�� ���̳��� ����Ʈ�� -1�� ����

	}


	// ������ ��ȸ, iteration ���� ������ ����
	Data list_next(List* pList){
		pList->pCurrent = pList->pCurrent->pNext; // �켱 current�� �ѹ� ������ �̵�

		return pList->pCurrent->data;

	}


	// ������ ��ȸ, iteration ���� ������ �ֳ�? Ȯ��
	int list_hasNext(List* pList){
		if( pList->pCurrent->pNext == NULL){ // ���� ��� ���翩�� Ȯ��?
		return FALSE;
		}

		return TRUE;

	}


	// ������ ��ȸ : n��° ������ �� ��ȸ
	int list_get(List* pList, int n, Data* pData){

		if(n >= pList->numData) return FALSE;

		//head���� �����ؼ� n��° ��� ã�ư���, iteration ���
		list_init_iter(pList);
		int i = 0; // ���� ���° �������
		while(list_hasNext(pList)){
			list_next(pList);
			if(i >= n)break;	// n���� ��� ã��!
			i++;
		}

		// n��° �����͸� �Ű������� �����
		*pData = pList->pCurrent->data;

		return TRUE;
	}


	// n��° ������ ����
	int list_remove(List* pList, int n){
		if(n >= pList->numData) return FALSE;

		// n��° ��� �����Ϸ���
		// n��° �� �ƴ϶� n-1 ��° ��� ������ �˾ƾ� �Ѵ�
		// ��. ���� ���(previous node) ���� �˾ƾ� �Ѵ�.


		list_init_iter(pList);
		int i = 0;
		Node* pPrev = NULL; // ���� ��带 ����� ������

		while(list_hasNext(pList)){
			// pCurrent�� �̵��ϱ� ���� pCurrent ���� '���� ���'�� ����صξ�� �Ѵ�.
			pPrev = pList->pCurrent;
			list_next(pList);
			if(i >= n)break;	// n���� ��� ã��!
			i++;
		}

		// �� while ���� ������
			// pCurrent �� n��° ��带,
			// pPrev �� n-1��° ��带 ����Ű�� �ִ�

			// ���� �� �����ؾ� �Ѵ�.  ���� �ٲ�� �����ȴ�.

		// ���� ����
		pPrev->pNext = pList->pCurrent->pNext;

		// ���� tail�� ������ ��忴�ٸ� tail ���� �����ؾ� �Ѵ�.
		if(pList->pCurrent == pList->pTail){
			pList->pTail = pPrev;
		}

		//printf("%d��° ������ %d ����\n", n, pList->pCurrent->data);

		free(pList->pCurrent); // ����

		pList->numData--; // �����ؼ� ����� ���� -1 ����


		return TRUE;
	}

	// ������ ���� : n��° ��ġ�� data ����
	// �ǵڿ� ����(�߰�)�ϴ� �͵� ���
	// n��° ������ ����
	int list_insert(List* pList, int n, Data data){
		if( n > pList->numData) return FALSE;

		// ���ο� ��� ����
		Node *pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		pNewNode->data = data;

		// 1. ù��° �������̰ų� �ǳ��� �߰��ϸ� add()�� ����
		if(pList->numData == 0 || n == pList->numData ){
			pList->pTail->pNext = pNewNode;
			pList->pTail = pNewNode;
		}
		else{ // 2. n��° ��忡 �����Ϸ���  n-1��° ���, �������(previous node) ���� �˾ƾ��Ѵ�.
			list_init_iter(pList);
			int i = 0;
			Node* pPrev = NULL; // ���� ��带 ����� ������

			while(list_hasNext(pList)){
				// pCurrent�� �̵��ϱ� ���� pCurrent ���� '���� ���'�� ����صξ�� �Ѵ�.
				pPrev = pList->pCurrent;
				list_next(pList);
				if(i >= n)break;	// n���� ��� ã��!
				i++;
			}

			// ���� ���� ����
			pPrev->pNext = pNewNode;// �������� ���ο� ��带 ����Ű��
			pNewNode->pNext = pList->pCurrent;//���ο� ���� ������ n��° ��带 ����Ű�� �ȴ�.

		}

		//printf("[%d]��°�� ������ %d ����\n", n, data);
		(pList->numData)++;

		return TRUE;
	}

	// ����Ʈ ����
	void list_destroy(List* pList){
		list_init_iter(pList);

		Node* pPrev = NULL; // ���� ��带 ����� ������

		while(list_hasNext(pList)){
			// pCurrent�� �̵��ϱ� ���� pCurrent ���� '���� ���'�� ����صξ�� �Ѵ�.
			pPrev = pList->pCurrent;
			list_next(pList);
			free(pPrev); // Ŀ��Ʈ�� �ӹ����� ��� ����

		}
		pList->pHead = NULL;
		pList->pTail = NULL;
		pList->numData = 0;
		//printf("����Ʈ �Ҹ�\n");
	}


	// Ž��
	Node * list_search(List *pList, Data data)
	{
		pList->pCurrent = pList->pHead;   // head ���� �˻�
		while (pList->pCurrent->pNext != NULL)
		{
			pList->pCurrent = pList->pCurrent->pNext;
			if (pList->pCurrent->data == data)
				return pList->pCurrent;  // ã���� �ش� ��� ����
		}
		return NULL;   // ������ NULL ����
	}








