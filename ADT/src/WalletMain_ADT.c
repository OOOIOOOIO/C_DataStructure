/*
 * WalletMain_ADT.c
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



int main(void){
	Wallet myWallet; // ���� ����

	wlt_init(&myWallet); // ���� �ʱ�ȭ (_init �Լ�)

	wlt_put_coin(&myWallet, 2); // ���� ���� : 2��

	wlt_put_bill(&myWallet, 1); // ���� ���� : 1��



	printf("�ܾ� %d\n", wlt_balance(&myWallet)); //�ܾ� 2000�� ���;ߵ�

	wlt_put_coin(&myWallet, 3); // ���� ���� : 3��

	wlt_put_bill(&myWallet, 4); // ���� ���� : 4��



	printf("�ܾ� %d\n", wlt_balance(&myWallet)); //�ܾ� 7500�� ���;ߵ�

	wlt_take_coin(&myWallet, 4);

	wlt_take_bill(&myWallet, 2);

	printf("�ܾ� %d\n", wlt_balance(&myWallet)); //�ܾ� 3500

	wlt_take_coin(&myWallet, 2); // ���� ����
	wlt_take_bill(&myWallet, 10); // ���� ����



	return 0;
}


