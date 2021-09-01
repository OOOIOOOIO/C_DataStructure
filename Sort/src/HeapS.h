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

/* Heap의 데이터 */

typedef int HData;

// 함수 선언
// d1의 우선순위가 높다면 0보다 큰 값 리턴
// d2의 우선순위가 높다면 0보다 작은 값 리턴
// d1과 d2의 우선순위가 같다면 0을 리턴
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap{
	HData *heapArr; // 동적 메모리로 구현
	int numData; // 담고 있는 데이터 개수

	// 우선순위 비교 함수
	fnPriorityComp *comp; //함수포인터 선언
}Heap;



/* Heap의 동작 */

// 힙 초기화

void heap_init(Heap *ph, int len); // 동적메모리 초기화
void heap_destroy(Heap *ph); // 동적메모리 해제


// 힙이 비어있나
int heap_is_empty(Heap *ph);


// 힙에 데이터 추가 (Insert)
void heap_insert(Heap *ph, HData data);


// 힙에서 (root를) 삭제하여 리턴 (Delete)
HData heap_delete(Heap *ph);


// 힙정렬
Heap *g_hp;
void HeapSort(int[], int n);


#endif /* HEAPS_H_ */
