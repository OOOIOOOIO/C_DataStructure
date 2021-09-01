#ifndef __WALLET_H__
#define __WALLET_H__



#define SUCCESS 1
#define FAIL 0

/* ������ ������ */ //����ü ����
typedef struct _wallet{
	int coin500; // 500��¥�� ���� ����
	int bill1000; // 1000��¥�� ���� ����


}Wallet;


/* ������ ���� */ //����ü �����͸� �̿��� �Լ� ����

// ���� �ʱ�ȭ
void wlt_init(Wallet *p);

// ���� ����
void wlt_put_coin(Wallet *p, int coinNum);

// ���� ����
int wlt_take_coin(Wallet *p, int coinNum);

// ���� ����
void wlt_put_bill(Wallet *p, int billBNUm);

// ���� ����
int wlt_take_bill(Wallet *p, int billBNUm);

// �ܾ� Ȯ��
int wlt_balance(Wallet *p);


#endif
