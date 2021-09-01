/*
 * Heap.c
 *
 *  Created on: 2021. 8. 2.
 *      Author: polit
 */
#include "HeapS.h"

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���


//--------------------------------------------------

//�θ��� �ε��� ���ϱ�
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx / 2 // >>, << ��Ʈ����



// left �ڽĳ�� �ε��� ���ϱ�
#define GET_LEFT_IDX(idx) ((idx) << 1) // idx * 2



// right �ڽĳ�� �ε��� ���ϱ�
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // idx * 2 + 1


// ���Լ� ��� ��ũ��(���� up)
#define COMP_ASC(d1, d2) ((d2) - (d1)) // ��������
#define COMP_DESC(d1, d2) ((d1) - (d2)) // ��������

// idx�� �ڽĵ� �� �켱 ������ ���� �ڽ��� index �� ���� --> delete�� ���
int getHigherPriority(Heap *ph, int idx){

	// �ڽĳ�尡 ���ٸ� 0 ����
	if(GET_LEFT_IDX(idx) > ph->numData) return 0;

	// �ڽ��� �ϳ���(�����ϴٸ�) �ִٸ� left��
	if(GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);

	// �ڽ��� �� �ִ� ��� �켱 ���� ���Լ� ���
	if(COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
		return GET_RIGHT_IDX(idx); // Right�� �� �켱������ ����

	else return GET_LEFT_IDX(idx); // Left�� �� �켱������ ����
}

//----------------------------------------------------



// �����޸� �ʱ�ȭ
void heap_init(Heap *ph, int len){
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) *(len + 1)); // +1�� ��ŭ �޸� �ʿ� 1-base�̱� ����
	g_hp = ph;
}

// �����޸� ����
void heap_destroy(Heap *ph){
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}


// ���� ����ֳ�
int heap_is_empty(Heap *ph){
	if(ph->numData == 0) return SUCCESS;

	return FAIL;
}



// ���� ������ �߰� (Insert)
void heap_insert(Heap *ph, HData data){
	//���� Insert �Ǵ� �����ʹ� �� ��������
	int idx = ph->numData + 1; // �迭 �ε����� '1'���� ����.
							   // ��ü ����� ������ numData�̰�
							   // numData�� �� ������ ����� �ε�����.

	//�Ʒ� while�� �����ϸ鼭 ���� insert �� data�� ��ġ�� idx�� ����
	while(idx != 1){ // �ֻ��� root�� ������ ������ ���� (�ֻ��� ��� idx = 1)

		// �θ𺸴� �켱������ ���ٸ� �θ�� �ڸ�(idx) �ٲٱ�
		if(COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0){
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)]; // �θ� ������
			idx = GET_PARENT_IDX(idx); // idx -> �θ� idx
		}
		// �θ𺸴� �켱������ ���ų� �۴ٸ� ����
		else{
			break;
		}


	}

	ph->heapArr[idx] = data; // idx�� ���� ���� ���� insert�� data �ֱ�
	ph->numData++; // ������ ���� ����
}



// ������ (root��) �����Ͽ� ���� (Delete)
HData heap_delete(Heap *ph){
	// �ε��� 1���� ��Ʈ���. �̸� �����ϰ� ����
	HData rootData = ph->heapArr[1];

	// ������ ��尡 �ڸ����� ��ġ�� idx�� ����
	// idx�� ������ ������ ������ ����� data�� ������ ���´�
	HData lastElement = ph->heapArr[ph->numData]; // numData�� ������ ���

	int idx = 1;  // ������ ��带 �ϴ� root�� ����
	int childIdx;

	// �ϴ� �ڽĳ���� �켱������ ���� �ָ� ����
	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� whild�� ����
	// �Ʒ� while ���� �ᱹ idx ���� ������ ����

	while(childIdx = getHigherPriority(ph, idx)){
		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����
		if(COMP_ASC(lastElement, ph->heapArr[childIdx]) >= 0)
			break;

		// �ڽ��� �켱������ �� ũ�ٸ� �ڽ��� �θ�� ��ü
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// ���� �񱳸� ���� ������ ����� idx�� ������ �ڽ���ġ�� ������
		idx = childIdx;
	}
	// while�� �� ���� �ڸ�(idx)�� ������ ���(lastElement)�� ������ ��

	ph->heapArr[idx] = lastElement;
	ph->numData--;

	return rootData; // ���ʿ� ������ ���Ҵ� root data ����
}

// ������
void HeapSort(int arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		heap_insert(g_hp, arr[i]);
	}

	for(i = 0; i < n; i++){
		arr[i] = heap_delete(g_hp);
	}
}



