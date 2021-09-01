/*
 * Sort.h
 *
 *  Created on: 2021. 8. 3.
 *      Author: polit
 */

#ifndef SORT_H_
#define SORT_H_


void printArr(int arr[], int n);

void genRandom(int arr[], int n); // ������ �迭 1 ~ n ����

void genIncSorted(int arr[], int n); // �������� �迭 ����

void genDecSorted(int arr[], int n); // �������� �迭 ����

void shuffleArr(int arr[], int n); // �迭 ����

//----------------------------------------------------

typedef void fnSort(int[], int);
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle);


//----------------------------------------------------
void BubbleSort(int arr[], int n); // ��������
void SelectionSort(int arr[], int n); // ��������
void InsertionSort(int arr[], int n); // ��������


#endif /* SORT_H_ */
