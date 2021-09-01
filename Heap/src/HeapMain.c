/*
 * HeapMain.c
 *
 *  Created on: 2021. 8. 2.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "Heap.h"


int DataPriorityComp(HData ch1, HData ch2){
	return ch1 - ch2; // max-heap으로 작동
	//return ch2 -ch1 // min-heap
}


int main(void){
	Heap heap; // 구조체 객체선언

	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	heap_insert(&heap, 15);
	heap_insert(&heap, 10);
	heap_insert(&heap, 3);
	heap_insert(&heap, 1);

	while(!(heap_is_empty(&heap))){
			printf("%d ", heap_delete(&heap)); // 30 - 20 - 15 - 10
		}

	//---------------------------------------
	printf("\n");
	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);
	heap_insert(&heap, 3);  // 추가
	heap_insert(&heap, 2);  // 어떻게 되나?
	heap_insert(&heap, 10); // 어떻게 되나?
	heap_insert(&heap, 1);  // 어떻게 되나?



	while(!(heap_is_empty(&heap))){
		printf("%d ", heap_delete(&heap)); // 30 - 20 - 15 - 10
	}

	return 0;
}



