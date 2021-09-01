/*
 * WalletMain_ADT.c
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



int main(void){
	Wallet myWallet; // 지갑 생성

	wlt_init(&myWallet); // 지갑 초기화 (_init 함수)

	wlt_put_coin(&myWallet, 2); // 동전 삽입 : 2개

	wlt_put_bill(&myWallet, 1); // 지폐 삽입 : 1개



	printf("잔액 %d\n", wlt_balance(&myWallet)); //잔액 2000원 나와야됨

	wlt_put_coin(&myWallet, 3); // 동전 삽입 : 3개

	wlt_put_bill(&myWallet, 4); // 지폐 삽입 : 4개



	printf("잔액 %d\n", wlt_balance(&myWallet)); //잔액 7500원 나와야됨

	wlt_take_coin(&myWallet, 4);

	wlt_take_bill(&myWallet, 2);

	printf("잔액 %d\n", wlt_balance(&myWallet)); //잔액 3500

	wlt_take_coin(&myWallet, 2); // 추출 실패
	wlt_take_bill(&myWallet, 10); // 추출 실패



	return 0;
}


