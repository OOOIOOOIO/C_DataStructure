/*
 * Heap.h
 *
 *  Created on: 2021. 8. 2.
 *      Author: polit
 */

#ifndef HEAPS_H_
#define HEAPS_H_

#define SUCCESS 1
#define FAIL 0
//#define HEAP_LEN 100

/* Heap�� ������ */

typedef int HData;

// �Լ� ����
// d1�� �켱������ ���ٸ� 0���� ū �� ����
// d2�� �켱������ ���ٸ� 0���� ���� �� ����
// d1�� d2�� �켱������ ���ٸ� 0�� ����
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap{
	HData *heapArr; // ���� �޸𸮷� ����
	int numData; // ��� �ִ� ������ ����

	// �켱���� �� �Լ�
	fnPriorityComp *comp; //�Լ������� ����
}Heap;



/* Heap�� ���� */

// �� �ʱ�ȭ

void heap_init(Heap *ph, int len); // �����޸� �ʱ�ȭ
void heap_destroy(Heap *ph); // �����޸� ����


// ���� ����ֳ�
int heap_is_empty(Heap *ph);


// ���� ������ �߰� (Insert)
void heap_insert(Heap *ph, HData data);


// ������ (root��) �����Ͽ� ���� (Delete)
HData heap_delete(Heap *ph);


// ������
Heap *g_hp;
void HeapSort(int[], int n);


#endif /* HEAPS_H_ */
