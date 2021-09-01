/*
 * ListBasedStackMain.c
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

int main(void){
	Stack stack; // 구조체 선언
	Data data; // Data = int

	stack_init(&stack); // Stack의 생서 및 초기화

	// 데이터 push
	stack_push(&stack, 1); // 1 <-- (<--가 탑이라 생각하기)
	stack_push(&stack, 2); // 1 2 <--
	stack_push(&stack, 3); // 1 2 3 <-- ( 이전 화살표 자리에 추가됨)
	stack_push(&stack, 4); // 1 2 3 4 <--
	stack_push(&stack, 5); // 1 2 3 4 5 <--

	// 데이터 pop
	stack_pop(&stack, &data); // data가 인트포인터형이므로 주소값 넘겨야됨
	printf("pop --> %d\n", data); // 5 pop
	stack_pop(&stack, &data);
	printf("pop --> %d\n", data); // 4

	// 데이터 pop 출력
	while(!(stack_is_empty(&stack))){ // 비어있지 않다면 이라는 뜻
		stack_pop(&stack, &data);	// 3 --> 2 --> 1 순으로 pop
		printf("%d ", data);
	}
	printf("\n");



	for(int i = 0; i <= 1000; i +=100){
		stack_push(&stack, i);
	}

	while(!(stack_is_empty(&stack))){
		stack_pop(&stack, &data);
		printf("pop --> %d\n", data);
	}


	stack_destroy(&stack); // 스택 제거
	return 0;
}


