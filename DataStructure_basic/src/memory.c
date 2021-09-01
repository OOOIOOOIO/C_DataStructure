/*
 * template.c
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
*	malloc(), free()
*   calloc(), realloc()
*
*   memcpy(), memset()
*/


int main(void){

	{
		//�����޸� �Ҵ� : Dynamic memory allocation
		int len = 1000000; //�������� �鸸�� ��Ƶ� �뷮 - ��鸸 ����Ʈ

		int* arr = malloc(sizeof(int)*len); // malloc(byte_size) �޸� �� �Ҵ�.
								 //�޸𸮺��� �ּ�(ù���� ����Ʈ)�� ����
		printf("memset �� arr[0] : %d\n", arr[0]); // ���� �����Ⱚ ����

		memset(arr, 0, sizeof(int) * len); // �޸𸮸� �Ҵ��ϴ� �Լ�, arr�������� len * int ��ŭ�� �޸� ������ 0���� �ʱ�ȭ
										   //��鸸 ����Ʈ�� 0���� �ʱ�ȭ
		printf("memset ��arr[0] : %d\n", arr[0]);

		//�ݵ�� �����޸𸮴� ��� �Ŀ� �� �� �� free�� �Ҵ����� �ؾ���.
		free(arr);

	}
	//������ �������� �޸𸮸� �Ҵ����� ���� ������ �޸� ����(memory leak) �߻�


	printf("\n");

	{
		//realloc() : �޸� ���Ҵ�
		// ������ �޸� �Ҵ�� �͵��� ������ �����Ҵ� �޾Ƽ� ���뺹��
		// ���� �޸𸮿� ���� �迭 Ȯ�� ����.
		// �����޸� ���Ҵ� (Ȯ��, ���)
		// ������ arr1 �� �Ҵ�� ������ ���� �˴ϴ�. (���� free() ��Ű�� �ʾƵ� ��)

		int* arr1 =  (int*)malloc(sizeof(int)*3);
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;

		printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);
		arr1 = realloc(arr1, sizeof(int)*5);

		arr1[3] = 40;
		printf("%d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3]);

		free(arr1);

	}


	return 0;
}
