/*
 * SortMain.c
 *
 *  Created on: 2021. 8. 3.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "Sort.h"
#include "HeapS.h"
#include "QuickSort.h"

#define DATA_SIZE 20000

int main(void){
//	int length;

//	printf("BubbleSort ����\n");
//	{
//		int data[] = {3, 2, 7, 5, 1};
//		length = sizeof(data) / sizeof(int);
//		BubbleSort(data,length);
//		printArr(data, length); // 1, 2, 3, 5, 7
//	}
//
//	{
//		int data[] = {11, 3, 28, 43, 9, 4};
//		length = sizeof(data) / sizeof(int);
//		BubbleSort(data,length);
//		printArr(data, length); // 3, 4, 9, 11, 28, 43
//	}
//
//
//
//	printf("\SelectionSort ����\n");
//	{
//		int data[] = {29, 10, 14, 37, 13};
//		length = sizeof(data) / sizeof(int);
//		SelectionSort(data,length);
//		printArr(data, length); // 10, 13, 14, 29, 37
//	}
//
//	{
//		int data[] = {11, 3, 28, 43, 9, 4};
//		length = sizeof(data) / sizeof(int);
//		SelectionSort(data,length);
//		printArr(data, length); // 3, 4, 9, 11, 28, 43
//	}
//
//
//	printf("\InsertionSort ����\n");
//	{
//		int data[] = {29, 10, 14, 37, 13};
//		length = sizeof(data) / sizeof(int);
//		InsertionSort(data,length);
//		printArr(data, length); // 10, 13, 14, 29, 37
//	}
//
//	{
//		int data[] = {11, 3, 28, 43, 9, 4};
//		length = sizeof(data) / sizeof(int);
//		InsertionSort(data,length);
//		printArr(data, length); // 3, 4, 9, 11, 28, 43
//	}


//---------------------------------------------------------------------

	// ����� �Լ� ���� Ȯ��
//	{

//		int srcArr[10];
//		genIncSorted(srcArr, 10);
//		printArr(srcArr, 10);
//
//		genDecSorted(srcArr, 10);
//		printArr(srcArr, 10);
//
//		genRandom(srcArr, 10);
//		printArr(srcArr, 10);
//	}

//----------------------------------------------------------------------

	// �ð� üũ
//	printf("\nTime Complexity\n");
//	{

//		int srcArr[DATA_SIZE];
//		genRandom(srcArr, DATA_SIZE); // ���� ������
//		int workArr[DATA_SIZE];
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
//	}

//---------------------------------------------------------------------

//	printf("\nWORST VS BEST\n");
//	{

//		// ���� �迭
//		int srcArr[DATA_SIZE];
//		genRandom(srcArr, DATA_SIZE); // ���� ������
//		genIncSorted(srcArr, DATA_SIZE); // ������������ ���ĵ� ������
//		genDecSorted(srcArr, DATA_SIZE); // ������������ ���ĵ� ������
//		int workArr[DATA_SIZE];
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "����-������ ��");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "����-������ ��");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "���� -������ ��");

//----------------------------------------------------------------------
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "����-������ ��");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "����-������ ��");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "���� -������ ��");
//	}

//----------------------------------------------------------------------

//	{

//	printf("\nHeap Sort\n");
//
//	int srcArr[DATA_SIZE];
//	genRandom(srcArr, DATA_SIZE); // ���� ������
//	int workArr[DATA_SIZE];
//
//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//
//	Heap hp;
//	heap_init(&hp, DATA_SIZE);
//
//	printArr(workArr, DATA_SIZE); // ������
//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "������");
//	printArr(workArr, DATA_SIZE); // ������
//
//	heap_destroy(&hp);
//
//	}

//-----------------------------------------------------------------------

//	{
//
//	printf("\nQuick Sort\n");
//	int arr[] = {40, 50, -30, -11, -333, 349, 23, 10};
//	int len = sizeof(arr) / sizeof(int);
//
//	printArr(arr, len); // ������ ��
//
//	QuickSort(arr, 0, len-1);
//
//	printArr(arr, len); // ������ �� -> -333 -30 -11 23 40 50 349
//
//
//
//	}


	printf("\nQuick Sort TimeLap\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE); // ���� �迭

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������ ����");

		genIncSorted(srcArr, DATA_SIZE); // �������� �迭
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������ ����");


	}


	return 0;
}


/*
Time Complexity
�������� (size: 20000) ������ : 829 ms
�������� (size: 20000) ������ : 375 ms
�������� (size: 20000) ������ : 170 ms

�������� (size: 40000) ������ : 3392 ms
�������� (size: 40000) ������ : 1577 ms
�������� (size: 40000) ������ : 643 ms

�������� (size: 80000) ������ : 12702 ms
�������� (size: 80000) ������ : 6009 ms
�������� (size: 80000) ������ : 1902 ms


WORST vs. BEST
������ (size: 20000) ������ : 887 ms
���÷��� (size: 20000) ������ : 385 ms
���Է��� (size: 20000) ������ : 172 ms

������� (size: 20000) ������ : 447 ms
���ÿ��� (size: 20000) ������ : 380 ms
���Կ��� (size: 20000) ������ : 0 ms

�������� (size: 20000) ������ : 621 ms
���ÿ����� (size: 20000) ������ : 333 ms
���Կ����� (size: 20000) ������ : 392 ms

HeapSort
������ (size: 20000) ������ : 7 ms
������ (size: 40000) ������ : 16 ms
������ (size: 80000) ������ : 29 ms

QuickSort
������ ���� (size: 20000) ������ : 4 ms
������ ���� (size: 40000) ������ : 9 ms
������ ���� (size: 80000) ������ : 17 ms

QuickSort
������ ���� (size: 3000) ������ : 0 ms
��-�������� (size: 3000) ������ : 10 ms

// ���� size : 4M
������ ���� (size: 10000) ������ : 3 ms
��-�������� (size: 10000) ������ : 104 ms

// ���� size : 8M
������ ���� (size: 20000) ������ : 4 ms
��-�������� (size: 20000) ������ : 378 ms

*/

