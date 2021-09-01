/*
 * ArrayList.c
 *
 *  Created on: 2021. 7. 20.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(dsisable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "ArrayList.h"


// ����Ʈ �ʱ�ȭ
void list_init(List *pList){
	pList->numData = 0;
	pList->curPosition = -1; // iteration
	memset(pList->arr, 0, sizeof(pList->arr)); // �迭�� ���� 0���� �ʱ�ȭ
	printf("����Ʈ �ʱ�ȭ\n");
}


// ����Ʈ ����
void list_destroy(List *pList){
	pList->numData = 0;
	printf("����Ʈ ����\n");
}


// ������ �߰�
int list_add(List *pList, Data data){
	if(pList->numData >= LIST_LEN){
		printf("������ �߰� �Ұ�\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data; // ������ �߰�
	//printf("[%d]��° ������ %d �߰�\n", pList -> numData, data);
	pList->numData++; // �ֱ� ���� �������� �ε��� ��ȣ ���� �Ŀ� �迭�� ������ ��(+1�� �Ǵϱ�)
	return SUCCESS;
}


// n���� ������ ����
int list_set(List *pList, int n, Data data){
	if(n >= pList->numData){
		printf("%d��° ������ ���� ����\n", n);
		return FAIL;
	}

	printf("[%d]��° ������ ���� %d -> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;
	return SUCCESS;
}


// ������ ����
int list_length(List *pList){
	return pList->numData;
}







// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List *pList){
	pList->curPosition = -1;
}


// ������ ��ȸ, iteration ���� ������ ����
Data list_next(List *pList){
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];

	return result;
}


// ������ ��ȸ, iteration ���� ������ �ֳ�? Ȯ��
int list_hasNext(List *pList){
	if(pList->curPosition + 1 < pList->numData){
		return SUCCESS;
	}
	else return FAIL;
}


// ������ ��ȸ : n��° ������ �� ��ȸ
int list_get(List *pList, int n, Data *pData){
	if(n >= pList->numData) return FAIL;

	*pData = pList->arr[n]; // n��° �����Ͱ��� pData�� ���� ���� Call By Reference
	return SUCCESS;
}


// n��° ������ ����
int list_remove(List *pList, int n){
	if(n >= pList->numData){
		printf("[%d]���� ������ ���� ����\n", n);
		return FAIL;
	}
	//�迭�̱⿡ �߰��� �����͸� �����ϸ� ���� �͵��� ��ܿ;� ��.
	for(int i = n; i < pList->numData-1; i++){
		pList->arr[i] = pList->arr[i+1];
	}
	pList->numData--; // ����Ʈ size ����
	//printf("%d��° ������ ����\n", n);

	return SUCCESS;
}


// n��° ������ ����
int list_insert(List *pList, int n, Data data){
	if(pList->numData >= LIST_LEN){
		printf("���̻� ���� �Ұ�\n");
		return FAIL;
	}
	// n�� ��ȿ���� ���� '�߰� �� ��' ���� ���
	if(n > pList->numData){
		printf("[%d]��° ��ġ�� ���� �Ұ�\n", n);
		return FAIL;
	}


	for(int i = pList->numData; i > n; i--){
		pList->arr[i] = pList->arr[i-1];
	}

	pList->arr[n] = data;
	pList->numData++;
	//printf("%d��° �����Ϳ� %d����\n", n, data);

	return SUCCESS;
}






