/*
 * ListBasedStackMain.c
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "ListBasedStack.h"

int main(void){
	Stack stack; // ����ü ����
	Data data; // Data = int

	stack_init(&stack); // Stack�� ���� �� �ʱ�ȭ

	// ������ push
	stack_push(&stack, 1); // 1 <-- (<--�� ž�̶� �����ϱ�)
	stack_push(&stack, 2); // 1 2 <--
	stack_push(&stack, 3); // 1 2 3 <-- ( ���� ȭ��ǥ �ڸ��� �߰���)
	stack_push(&stack, 4); // 1 2 3 4 <--
	stack_push(&stack, 5); // 1 2 3 4 5 <--

	// ������ pop
	stack_pop(&stack, &data); // data�� ��Ʈ���������̹Ƿ� �ּҰ� �Ѱܾߵ�
	printf("pop --> %d\n", data); // 5 pop
	stack_pop(&stack, &data);
	printf("pop --> %d\n", data); // 4

	// ������ pop ���
	while(!(stack_is_empty(&stack))){ // ������� �ʴٸ� �̶�� ��
		stack_pop(&stack, &data);	// 3 --> 2 --> 1 ������ pop
		printf("%d ", data);
	}
	printf("\n");



	for(int i = 0; i <= 1000; i +=100){
		stack_push(&stack, i);
	}

	while(!(stack_is_empty(&stack))){
		stack_pop(&stack, &data);
		printf("pop --> %d\n", data);
	}


	stack_destroy(&stack); // ���� ����
	return 0;
}


