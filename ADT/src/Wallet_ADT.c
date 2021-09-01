/*
 * Wallet_ADT.c
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

#include "Wallet_ADT.h"


// 지갑 초기화
void wlt_init(Wallet* p){
	printf("지갑을 초기화 합니다\n");
	p->bill1000 = 0;
	p->coin500 = 0;

	//memset(p, 0, sizeof(Wallet); // 모든 p를 0으로 초기화
}

// 동전 삽입
void wlt_put_coin(Wallet *p, int coinNum){
	p->coin500 += coinNum;
	printf("동전 %d 개가 삽입되어 %d 개가 되었습니다\n", coinNum, p->coin500);
}

// 동전 추출
int wlt_take_coin(Wallet *p, int coinNum){
	if(p->coin500 < coinNum){
		printf("동전개수가 부족하여 %d 개를 추출할 수 없습니다.\n", coinNum);

	return FAIL; // 추출 실패
	}

	p->coin500 -= coinNum;
	printf("동전 %d개가 추출되어 %d개가 되었습니다.\n", coinNum, p->coin500);
	return SUCCESS; // 추출 성공
}

// 지폐 삽입
void wlt_put_bill(Wallet* p, int billNum){
	p->bill1000 += billNum;
	printf("동전 %d 개가 삽입되어 %d 개가 되었습니다\n", billNum, p->bill1000);

}

// 지폐 추출
int wlt_take_bill(Wallet* p, int billNum){
	if(p->bill1000 < billNum){
			printf("지폐개수가 부족하여 %d 개를 추출할 수 없습니다.\n", billNum);

		return FAIL; // 추출 실패
		}

		p->bill1000 -= billNum;
		printf("동전 %d개가 추출되어 %d개가 되었습니다.\n", billNum, p->bill1000);
		return SUCCESS; // 추출 성공
}

// 잔액 확인
int wlt_balance(Wallet *p){

	return p->coin500 * 500 + p->bill1000 * 1000;
}
