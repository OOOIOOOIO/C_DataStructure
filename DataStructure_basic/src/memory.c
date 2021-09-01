/*
 * template.c
 *
 *  Created on: 2021. 7. 13.
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
*	malloc(), free()
*   calloc(), realloc()
*
*   memcpy(), memset()
*/


int main(void){

	{
		//동적메모리 할당 : Dynamic memory allocation
		int len = 1000000; //정수형을 백만개 담아둘 용량 - 사백만 바이트

		int* arr = malloc(sizeof(int)*len); // malloc(byte_size) 메모리 블럭 할당.
								 //메모리블럭의 주소(첫번쨰 바이트)를 리턴
		printf("memset 전 arr[0] : %d\n", arr[0]); // 원래 쓰레기값 나옴

		memset(arr, 0, sizeof(int) * len); // 메모리를 할당하는 함수, arr번지부터 len * int 만큼의 메모리 영역을 0으로 초기화
										   //사백만 바이트를 0으로 초기화
		printf("memset 휴arr[0] : %d\n", arr[0]);

		//반드시 동적메모리는 사용 후에 반 드 시 free로 할당해제 해야함.
		free(arr);

	}
	//적절한 시점에서 메모리를 할당해제 하지 않으면 메모리 누수(memory leak) 발생


	printf("\n");

	{
		//realloc() : 메모리 재할당
		// 기존에 메모리 할당된 것들을 새로이 공간할당 받아서 내용복사
		// 동적 메모리에 사용된 배열 확장등에 좋다.
		// 동적메모리 재할당 (확장, 축소)
		// 기존의 arr1 에 할당된 공간은 해제 됩니다. (따로 free() 시키지 않아도 됨)

		int* arr1 =  (int*)malloc(sizeof(int)*3);
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;

		printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);
		arr1 = realloc(arr1, sizeof(int)*5);

		arr1[3] = 40;
		printf("%d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3]);

		free(arr1);

	}


	return 0;
}
