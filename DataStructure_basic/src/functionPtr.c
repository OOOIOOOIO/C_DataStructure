/*
 * functionPtr.c
 *
 *  Created on: 2021. 7. 13.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���


/*
 *	���� ������
 *	'�Լ��̸�'�� �� '������'�� !
 */



void fnMinus(int a, int b)
{
	printf("����: %d - %d = %d\n", a, b, a - b);
}

void fnMul(int a, int b)
{
	printf("����: %d * %d = %d\n", a, b, a * b);
}

void fnDiv(int a, int b)
{
	printf("������: %d / %d = %d\n", a, b, a / b);
}

void fnPlus(int a, int b){
	printf("���� : %d + %d = %d\n", a, b, a + b);
}




void doAction(int a, int b, void(*fnOp)(int, int)){ //�Լ������͸� ����� �Լ��� �Ű������� �Ѱ��� �� �ִ���
	fnOp(a, b);
}

typedef void fnActions(int, int); // �Լ������� Ÿ�� �����ϰ� 51~53ó�� ��ߵ�

void doAction2(int a, int b, fnActions * fnOp){ // �Ȱ��� �������� (45~ 47��° ��)
	fnOp(a, b);
}



int main(void){

	{
		printf("=======�Լ������� ����======\n");

		fnPlus(10, 20);

		printf("fnPlus -> %p\n", fnPlus); // �ּҰ�����

		//�Լ��̸� -> �Լ�������
		// �Լ������ʹ� '����' �� �� 'ȣ��' �����̴�.
		// ���������� * ����Ͽ� ȣ��

		(*fnPlus)(30, 40);

		// �Լ� ������ Ÿ�� ���� ���� ����
		// int *p;   <-- int �� ���� ������
		// void �����ϰ� (int, int) �Ű����� �޴� �Լ��� ���� �Լ� �����ʹ� �Ʒ���

		void(*fnOp)(int, int); //fnOp��� '�Լ������� ���� ����' !!

		// ������ ���� <- ���� �����ϴٴ� �� !

		fnOp = fnPlus;

		//���� fnOp�� fnPlus�Լ�ó�� ��� ����, ���������ڵ� ��� ����

		(*fnOp)(40, 60);
		fnOp(45, 70); //�Ȱ��� ����

	}

	printf("\n");

	{
		printf("=======�Լ������͸� �Լ������͹迭�� �־ ����======\n");
		// �Լ��������� ����.
		// '����'�� ���߿� ���� ���� (late-binding)

		int op;
		printf("\n���۹�ȣ�� �Է��ϼ���(0:+ 1:- 2:* 3:/): ");
		fflush(stdout);
		scanf("%d", &op);

		printf("\n======if-else if�� �Լ�����ϱ�======\n");

		int a = 30, b = 10;
		int i = 0;
		for (i = 0; i < 5; i++){
			if(op == 0)	fnPlus(a, b); 		 // <-- �� ������ �����ڵ�� fnPlus�� ȣ���ϵ��� �����ϵȴ�.
			else if(op == 1) fnMinus(a, b);  // <-- �� ������ �����ڵ�� fnMinus�� ȣ���ϵ��� �����ϵȴ�.
			else if(op == 2) fnMul(a, b);
			else if(op == 3) fnDiv(a, b);

		}
		// �� �̹� �������Ҷ� �ڵ�� ��õ� 'Ư��'�Լ���
		// ����ǵ��� ���ε� �ȴ�.  --> Early Binding �̶� ��
		// �� ��ȯ������ ���ǹ��� ���� ������ �Լ� ȣ���� ȣ���ؾ� �ϴ�, ���Ǻб⹮(if-else if) �ε尡 ŭ
		printf("\n");
		printf("=======�Լ������Ϳ� �Լ������͹迭�� �̿��ؼ� ����ϱ�======\n");
		// �ݸ� !
		// �Լ������� ����
		void(*fnAction)(int, int); //fnAction��� '�Լ������� ���� ����'


		// �Լ��������� �迭(�Լ��鸸 ��Ƴ��� �迭)
		void(*fnOpArr[])(int, int) = {fnPlus, fnMinus, fnMul, fnDiv};
		//fnArr[0] => fnPlus ....

		fnAction = fnOpArr[op]; //�Լ������Ϳ� �Լ������͹迭�� �Ѱܼ� ����Ѵ�.

		for(i = 0; i < 5; i++){
			fnAction(a, b);
		}
		// �׳� fnAction �� ����.. �׷��� ������ �������� ������ �������� �𸥴� (�� ���ε��� �Ǿ� ���� �ʴ�)
		// ���� �ؾ� ���߿� ������ �����ȴ�.   late-binding

		// ����: ���ǹ��� ���� �ε尡 ����.
		// �������!!

	}

	printf("\n");

	{
		printf("=======�Լ������͸� �̿��� �Լ��� �Ű������� �޾Ƽ� ����ϱ�======\n");
		// �Լ� �����͵� �����ʹ�!
		// �Ű������� �Ѱ��ټ���, ���ϰ����� ��������
		// �迭 ���Ұ� �ɼ��� �ִ�!!


		doAction(333, 444, fnPlus);
		doAction(333, 444, fnMinus);
		doAction(333, 444, fnMul);
		doAction(333, 444, fnDiv);
	}

	printf("\n");

	{
		// �Լ� �����͵� �����ʹ�!
		// �Ű������� �Ѱ��ټ���, ���ϰ����� ��������
		// �迭 ���Ұ� �ɼ��� �ִ�!!


		doAction2(333, 444, fnPlus);
		doAction2(333, 444, fnMinus);
		doAction2(333, 444, fnMul);
		doAction2(333, 444, fnDiv);
	}


	return 0;
}

