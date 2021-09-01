/*
 * iterateMain.c
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

#define MAX_LENGTH 4
#define TRUE 1
#define FALSE 0


typedef struct _IterArray{
	int arr[MAX_LENGTH];
	int curPosition; // iterator ������ ���� ��(currentposition)

}IterArray; // ����ü ����


// 	<���ۼ���>

// iterator �ʱ�ȭ
void iter_init(IterArray *p){
	p->curPosition = -1; //�ٽ� �ټ���ٴ� ��. ������ -1
}


// ������ ������ �����Ͱ� �ֳ�?
int iter_hasNext(IterArray *p){
	if(p->curPosition + 1 < MAX_LENGTH){
		return TRUE;
	}
	else{
		printf("���̻� ������ �����Ͱ� �����ϴ�.\n");
		return FALSE;
	}
}


// ���� ������ ����
int iter_next(IterArray *p){
	p->curPosition++; // �켱! curPosition�� next�� +1 ����
	return p->arr[p->curPosition];
}



int main(void){

	IterArray data = {{10, 20, 30, 40}, -1}; // �ʱ�ȭ, {arr = {10, 20, 30, 40}, curPositon = -1}�� �ʱ�ȭ

	iter_init(&data);
	while(iter_hasNext(&data)){ // �� ������ �����Ͱ� �ֳ� �˻�
		printf("%d ",iter_next(&data));
	} 							// �� ���� FASLE�� ��. �ٽ� iterator ������ �ϸ� �ȵȴ�.


	printf("\n");


	// �ٽ� iterator ������ �Ϲ�... (�ȵȴ�)
	while (iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}


	// ���� �����͸� �����Ϸ���  iterator �� ���� ���۽��Ѿ� �Ѵ�.
	iter_init(&data);

	while (iter_hasNext(&data))  // �� ������ ������ �ֳ�?
	{
		printf("%d ", iter_next(&data));
	}


	return 0;
}

/* ���� ��κ��� ���� ���鿡�� Iteration(�ݺ���) ������.
*
*	Python �� iterable��ü
*		ex) for a in b:  <-- b �� 'iterable' �ؾ� �Ѵ�.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection �� Iterator ��ü
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator
*/
