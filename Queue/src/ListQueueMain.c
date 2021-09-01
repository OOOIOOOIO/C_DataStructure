/*
 * ListQueueMain.c
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

#include "ListQueue.h"

int main(void){
	// Queue 생성 및 초기화
	Queue q; // 구조체 선언
	Data data;

	queue_init(&q); // 큐 초기화

	// 데이터 넣기 enqueue
	queue_enq(&q, 1); // front <-- [1] <-- back
	queue_enq(&q, 2); // front <-- [1 2] <-- back
	queue_enq(&q, 3); // front <-- [1 2 3] <-- back
	queue_enq(&q, 4); // front <-- [1 2 3 4] <-- back
	queue_enq(&q, 5); // front <-- [1 2 3 4 5] <-- back


	// 데이터 꺼내기 dequeue
	while(!(queue_is_empty(&q))){
		queue_deq(&q, &data);
		printf("deq --> %d\n", data); // 결과 1 2 3 4 5 순으로 pop
	}




	queue_destroy(&q); // 큐 제거


	return 0;
}


