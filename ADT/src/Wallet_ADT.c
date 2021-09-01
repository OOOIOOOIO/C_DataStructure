/*
 * Wallet_ADT.c
 *
 *  Created on: 2021. 7. 15.
 *      Author: polit
 */

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "Wallet_ADT.h"


// ���� �ʱ�ȭ
void wlt_init(Wallet* p){
	printf("������ �ʱ�ȭ �մϴ�\n");
	p->bill1000 = 0;
	p->coin500 = 0;

	//memset(p, 0, sizeof(Wallet); // ��� p�� 0���� �ʱ�ȭ
}

// ���� ����
void wlt_put_coin(Wallet *p, int coinNum){
	p->coin500 += coinNum;
	printf("���� %d ���� ���ԵǾ� %d ���� �Ǿ����ϴ�\n", coinNum, p->coin500);
}

// ���� ����
int wlt_take_coin(Wallet *p, int coinNum){
	if(p->coin500 < coinNum){
		printf("���������� �����Ͽ� %d ���� ������ �� �����ϴ�.\n", coinNum);

	return FAIL; // ���� ����
	}

	p->coin500 -= coinNum;
	printf("���� %d���� ����Ǿ� %d���� �Ǿ����ϴ�.\n", coinNum, p->coin500);
	return SUCCESS; // ���� ����
}

// ���� ����
void wlt_put_bill(Wallet* p, int billNum){
	p->bill1000 += billNum;
	printf("���� %d ���� ���ԵǾ� %d ���� �Ǿ����ϴ�\n", billNum, p->bill1000);

}

// ���� ����
int wlt_take_bill(Wallet* p, int billNum){
	if(p->bill1000 < billNum){
			printf("���󰳼��� �����Ͽ� %d ���� ������ �� �����ϴ�.\n", billNum);

		return FAIL; // ���� ����
		}

		p->bill1000 -= billNum;
		printf("���� %d���� ����Ǿ� %d���� �Ǿ����ϴ�.\n", billNum, p->bill1000);
		return SUCCESS; // ���� ����
}

// �ܾ� Ȯ��
int wlt_balance(Wallet *p){

	return p->coin500 * 500 + p->bill1000 * 1000;
}
