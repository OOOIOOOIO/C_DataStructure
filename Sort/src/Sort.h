/*
 * Sort.h
 *
 *  Created on: 2021. 8. 3.
 *      Author: polit
 */

#ifndef SORT_H_
#define SORT_H_


void printArr(int arr[], int n);

void genRandom(int arr[], int n); // 무작위 배열 1 ~ n 범위

void genIncSorted(int arr[], int n); // 오름차순 배열 생성

void genDecSorted(int arr[], int n); // 내림차순 배열 생성

void shuffleArr(int arr[], int n); // 배열 섞기

//----------------------------------------------------

typedef void fnSort(int[], int);
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle);


//----------------------------------------------------
void BubbleSort(int arr[], int n); // 버블정렬
void SelectionSort(int arr[], int n); // 선택정렬
void InsertionSort(int arr[], int n); // 삽입정렬


#endif /* SORT_H_ */
