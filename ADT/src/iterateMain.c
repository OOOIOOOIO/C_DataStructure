/*
 * iterateMain.c
 *
 *  Created on: 2021. 7. 15.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#define MAX_LENGTH 4
#define TRUE 1
#define FALSE 0


typedef struct _IterArray{
	int arr[MAX_LENGTH];
	int curPosition; // iterator 구현을 위한 값(currentposition)

}IterArray; // 구조체 선언


// 	<동작순서>

// iterator 초기화
void iter_init(IterArray *p){
	p->curPosition = -1; //다시 줄세운다는 뜻. 시작점 -1
}


// 다음에 추출할 데이터가 있나?
int iter_hasNext(IterArray *p){
	if(p->curPosition + 1 < MAX_LENGTH){
		return TRUE;
	}
	else{
		printf("더이상 추출할 데이터가 없습니다.\n");
		return FALSE;
	}
}


// 다음 데이터 추출
int iter_next(IterArray *p){
	p->curPosition++; // 우선! curPosition이 next로 +1 증가
	return p->arr[p->curPosition];
}



int main(void){

	IterArray data = {{10, 20, 30, 40}, -1}; // 초기화, {arr = {10, 20, 30, 40}, curPositon = -1}로 초기화

	iter_init(&data);
	while(iter_hasNext(&data)){ // 더 추출할 데이터가 있나 검사
		printf("%d ",iter_next(&data));
	} 							// 다 돌고 FASLE가 됨. 다시 iterator 돌리려 하면 안된다.


	printf("\n");


	// 다시 iterator 돌리려 하믄... (안된다)
	while (iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}


	// 새로 데이터를 추출하려면  iterator 를 새로 동작시켜야 한다.
	iter_init(&data);

	while (iter_hasNext(&data))  // 더 추출할 데이터 있나?
	{
		printf("%d ", iter_next(&data));
	}


	return 0;
}

/* 거의 대부분의 현대 언어들에선 Iteration(반복자) 지원함.
*
*	Python 의 iterable객체
*		ex) for a in b:  <-- b 는 'iterable' 해야 한다.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection 의 Iterator 객체
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator
*/
