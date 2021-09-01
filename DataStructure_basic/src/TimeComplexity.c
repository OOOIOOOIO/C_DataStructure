/*
 * TimeComplexity.c
 *
 *  Created on: 2021. 8. 3.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

typedef void fnAction(int); // 측정할 함수 타입 선언

void chkTime(char* szTitle, fnAction action, int dataSize){
	clock_t start, end;
	long result;

	printf("%s : size[%d] 측정시작\n", szTitle, dataSize);
	start = clock();

	action(dataSize);


	end = clock();
	result = end - start;
	printf("%s : size[%d] 경과시간 %ld ms\n", szTitle, dataSize, result);
}





void func1(int size){ // n배 만큼
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum++;
	}
}


void func2(int size){ // n^2배 만큼
	int sum = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum++;
		}
	}
}

void func3(int size){ // n^3배 만큼
	int sum = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			for(int k = 0; k < size; k++){
				sum++;
			}

		}
	}
}


int main(void){
	int size;

	{
		size = 100000000;
		chkTime("O(n)", func1, size);
		chkTime("O(n)", func1, size*2);
		chkTime("O(n)", func1, size*4);

		// 입력데이터가 n배 증가할 때 수행시간도 n배 증가한다.
	}

	{
		size = 10000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size*2);
		chkTime("O(n^2)", func2, size*4);

		// 입력데이터가 n배 증가할 때 수행시간은 n^2배 증가한다.
	}

	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size*2);
		chkTime("O(n^3)", func3, size*4);

		// 입력데이터가 n배 증가할 때 수행시간은 n^3배 증가한다.
	}


	return 0;
}

