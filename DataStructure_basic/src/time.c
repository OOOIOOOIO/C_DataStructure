/*
 * time.c
 *
 *  Created on: 2021. 7. 15.
 *      Author: polit
 */

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오


/*
	C, C++ 에서 시작 측정하기
	방법1:  time() 사용
	방법2:  clock() 사용

	C 에서 프로그램 실행 지연 시키기
		_sleep() 사용
*/
int main(void){

	//time() 사용

	{
		time_t start, end; //time.h
		printf("time() 측정 시작\n");

		start = time(NULL); // 현재시간 리턴, 시작 시간 기록

		for(int i = 0; i < 5; i++){
			printf("i = %d\n", i);
			fflush(stdout);
			_sleep(1000);
		}

		end = time(NULL); //종료 시간 기록

		double result = (double)(end - start); // 경과시간
		printf("%f s\n", result);

	}


	// clock() 사용

	{
		clock_t start, end;
		start = clock(); // 현재시간 측정, 시작시간 기록

		for(int i = 0; i < 5; i++){
				printf("i = %d\n", i);
				fflush(stdout);
				_sleep(1100);
			}

		end = clock(); //종료시간 기록

		printf("%ld ms\n", end-start);
	}


	return 0;
}



