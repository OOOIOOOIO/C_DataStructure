/*
 * time.c
 *
 *  Created on: 2021. 7. 15.
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
	C, C++ ���� ���� �����ϱ�
	���1:  time() ���
	���2:  clock() ���

	C ���� ���α׷� ���� ���� ��Ű��
		_sleep() ���
*/
int main(void){

	//time() ���

	{
		time_t start, end; //time.h
		printf("time() ���� ����\n");

		start = time(NULL); // ����ð� ����, ���� �ð� ���

		for(int i = 0; i < 5; i++){
			printf("i = %d\n", i);
			fflush(stdout);
			_sleep(1000);
		}

		end = time(NULL); //���� �ð� ���

		double result = (double)(end - start); // ����ð�
		printf("%f s\n", result);

	}


	// clock() ���

	{
		clock_t start, end;
		start = clock(); // ����ð� ����, ���۽ð� ���

		for(int i = 0; i < 5; i++){
				printf("i = %d\n", i);
				fflush(stdout);
				_sleep(1100);
			}

		end = clock(); //����ð� ���

		printf("%ld ms\n", end-start);
	}


	return 0;
}



