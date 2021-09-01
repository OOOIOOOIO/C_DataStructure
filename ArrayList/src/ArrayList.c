/*
 * ArrayList.c
 *
 *  Created on: 2021. 7. 20.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(dsisable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "ArrayList.h"


// 리스트 초기화
void list_init(List *pList){
	pList->numData = 0;
	pList->curPosition = -1; // iteration
	memset(pList->arr, 0, sizeof(pList->arr)); // 배열을 전부 0으로 초기화
	printf("리스트 초기화\n");
}


// 리스트 제거
void list_destroy(List *pList){
	pList->numData = 0;
	printf("리스트 제거\n");
}


// 데이터 추가
int list_add(List *pList, Data data){
	if(pList->numData >= LIST_LEN){
		printf("데이터 추가 불가\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data; // 데이터 추가
	//printf("[%d]번째 데이터 %d 추가\n", pList -> numData, data);
	pList->numData++; // 넣기 전엔 넣으려는 인덱스 번호 넣은 후엔 배열의 개수가 됨(+1이 되니까)
	return SUCCESS;
}


// n번쨰 데이터 수정
int list_set(List *pList, int n, Data data){
	if(n >= pList->numData){
		printf("%d번째 데이터 수정 실패\n", n);
		return FAIL;
	}

	printf("[%d]번째 데이터 수정 %d -> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;
	return SUCCESS;
}


// 데이터 개수
int list_length(List *pList){
	return pList->numData;
}







// 데이터 조회, iteration 초기화
void list_init_iter(List *pList){
	pList->curPosition = -1;
}


// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List *pList){
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];

	return result;
}


// 데이터 조회, iteration 다음 데이터 있나? 확인
int list_hasNext(List *pList){
	if(pList->curPosition + 1 < pList->numData){
		return SUCCESS;
	}
	else return FAIL;
}


// 데이터 조회 : n번째 데이터 값 조회
int list_get(List *pList, int n, Data *pData){
	if(n >= pList->numData) return FAIL;

	*pData = pList->arr[n]; // n번째 데이터값을 pData를 통해 전달 Call By Reference
	return SUCCESS;
}


// n번째 데이터 삭제
int list_remove(List *pList, int n){
	if(n >= pList->numData){
		printf("[%d]번쨰 데이터 삭제 실패\n", n);
		return FAIL;
	}
	//배열이기에 중간의 데이터를 삭제하면 뒤의 것들을 당겨와야 함.
	for(int i = n; i < pList->numData-1; i++){
		pList->arr[i] = pList->arr[i+1];
	}
	pList->numData--; // 리스트 size 감소
	//printf("%d번째 데이터 삭제\n", n);

	return SUCCESS;
}


// n번째 데이터 삽입
int list_insert(List *pList, int n, Data data){
	if(pList->numData >= LIST_LEN){
		printf("더이상 삽입 불가\n");
		return FAIL;
	}
	// n의 유효범위 검증 '중간 및 끝' 삽입 허용
	if(n > pList->numData){
		printf("[%d]번째 위치에 삽입 불가\n", n);
		return FAIL;
	}


	for(int i = pList->numData; i > n; i--){
		pList->arr[i] = pList->arr[i-1];
	}

	pList->arr[n] = data;
	pList->numData++;
	//printf("%d번째 데이터에 %d삽입\n", n, data);

	return SUCCESS;
}






