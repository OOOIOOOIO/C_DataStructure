/*
 * Sort.c
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


void printArr(int arr[], int n){
	printf("[");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("]\n\n");

}
// ������ �迭 ����, 1 ~ n ����
void genRandom(int arr[], int n){
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}


// �������� �迭 ����
void genIncSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = i + 1;
	}
}


// �������� �迭 ����
void genDecSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = n - i;
	}
}


// �迭 ����
void shuffleArr(int arr[], int n){
	srand(time(NULL));
	if(n > 1){ // �迭���̰� 2�� �̻��� ��쿡�� shuffle
		for(int i = 0; i < n-1; i++){
			//i������ i �������� ������ j��° swap
			int j = i + rand() / (RAND_MAX / (n-i) + 1);

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}



//----------------------------------------------------

// ���� üũ
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle){
	clock_t start, end;
	start = clock();

	sort(arr, n);

	end = clock();

	printf("%s (size : %d) ������ : %ld ms\n", szTitle, n, end - start);
}



//----------------------------------------------------

// ��������
void BubbleSort(int arr[], int n){
	int i, j;
	int temp;

	for(i = 0; i < n-1; i++){ // cycle ȸ�� Ƚ��, �� n-1��
		for(j = 0; j < (n-i) - 1; j++){
			if(arr[j] > arr[j+1]){ // ������ �� �� ��, 1 cycle �� (n-i) -1 �� �߻�
				temp = arr[j];
				arr[j] = arr[j+1];
				 arr[j+1] = temp;
			}
		}
		// �� ����Ŭ ����, �߰����� ���
		//printArr(arr, n);
	}
}



// ��������
void SelectionSort(int arr[], int n){
	int i, j;
	int min_idx;
	int temp;

	for(i = 0; i < n-1; i++){
		min_idx = i;
		for(j = i + 1; j < n; j++){
			if(arr[min_idx] > arr[j]){
				min_idx = j;
			}
		}
		if(i != min_idx){ // 1 cycle �� ���ƾ� 1�� �߻�
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
		// �� ����Ŭ ����, �߰����� ���
		//printArr(arr, n);
	}
}
// min_idx�� ���� 1��° ������ ���� �߿��� ���� ���� ���� ����Ű�� ���� ���̴�.
// �׷��� arr[i]���� arr[min_idx]�� ���� ��ȯ�ϸ� �ȴ�.
// 1��° ����(i+1)���� �����Ͽ� �������� 1��°���� ������ �� ���� �ּڰ� ã��
// �ּڰ��� ��ġ(min_idx)�� '����'�ϴ� ���� ��ǥ!




// ��������
void InsertionSort(int arr[], int n){
	int insData;
	for(int i = 1; i < n; i++){ // i = 1���� ����
		insData = arr[i]; // ������ ������ ����

		int j;
		for(j = i - 1; j>= 0; j--){ // j�� i ���ʺ��� �������� �˻�
			if(arr[j] > insData){ // �����Ϸ��� �����ͺ���
				arr[j+1] = arr[j]; // j������ ũ�� j�� �������� �� ĭ �ű�
			}
			else
				break; // ���� ��ġ(j)�� ã������ ����
		}
		//������ j ��ġ�� �ٷ� �������� insert�� ��ġ
		arr[j+1] = insData;

		// �� ����Ŭ ����, �߰����� ���
		//printArr(arr, n);
	}
}



