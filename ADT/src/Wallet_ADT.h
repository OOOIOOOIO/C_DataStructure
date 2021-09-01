#ifndef __WALLET_H__
#define __WALLET_H__



#define SUCCESS 1
#define FAIL 0

/* 지갑의 데이터 */ //구조체 선언
typedef struct _wallet{
	int coin500; // 500원짜리 동전 개수
	int bill1000; // 1000원짜리 지폐 개수


}Wallet;


/* 지갑의 동작 */ //구조체 포인터를 이용한 함수 구현

// 지갑 초기화
void wlt_init(Wallet *p);

// 동전 삽입
void wlt_put_coin(Wallet *p, int coinNum);

// 동전 추출
int wlt_take_coin(Wallet *p, int coinNum);

// 지폐 삽입
void wlt_put_bill(Wallet *p, int billBNUm);

// 지폐 추출
int wlt_take_bill(Wallet *p, int billBNUm);

// 잔액 확인
int wlt_balance(Wallet *p);


#endif
