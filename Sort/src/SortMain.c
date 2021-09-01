/*
 * SortMain.c
 *
 *  Created on: 2021. 8. 3.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "Sort.h"
#include "HeapS.h"
#include "QuickSort.h"

#define DATA_SIZE 20000

int main(void){
//	int length;

//	printf("BubbleSort 동작\n");
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
//	printf("\SelectionSort 동작\n");
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
//	printf("\InsertionSort 동작\n");
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

	// 도우미 함수 동작 확인
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

	// 시간 체크
//	printf("\nTime Complexity\n");
//	{

//		int srcArr[DATA_SIZE];
//		genRandom(srcArr, DATA_SIZE); // 랜덤 데이터
//		int workArr[DATA_SIZE];
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
//	}

//---------------------------------------------------------------------

//	printf("\nWORST VS BEST\n");
//	{

//		// 랜덤 배열
//		int srcArr[DATA_SIZE];
//		genRandom(srcArr, DATA_SIZE); // 랜덤 데이터
//		genIncSorted(srcArr, DATA_SIZE); // 오름차순으로 정렬된 데이터
//		genDecSorted(srcArr, DATA_SIZE); // 내림차순으로 정렬된 데이터
//		int workArr[DATA_SIZE];
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블-오름일 때");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택-오름일 떄");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입 -오름일 때");

//----------------------------------------------------------------------
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블-내림일 때");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택-내림일 떄");
//
//		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//		chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입 -내림일 떄");
//	}

//----------------------------------------------------------------------

//	{

//	printf("\nHeap Sort\n");
//
//	int srcArr[DATA_SIZE];
//	genRandom(srcArr, DATA_SIZE); // 랜덤 데이터
//	int workArr[DATA_SIZE];
//
//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
//
//	Heap hp;
//	heap_init(&hp, DATA_SIZE);
//
//	printArr(workArr, DATA_SIZE); // 정렬전
//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "힙정렬");
//	printArr(workArr, DATA_SIZE); // 정렬후
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
//	printArr(arr, len); // 퀵정렬 전
//
//	QuickSort(arr, 0, len-1);
//
//	printArr(arr, len); // 퀵정렬 후 -> -333 -30 -11 23 40 50 349
//
//
//
//	}


	printf("\nQuick Sort TimeLap\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE); // 랜덤 배열

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬 랜덤");

		genIncSorted(srcArr, DATA_SIZE); // 오름차순 배열
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬 랜덤");


	}


	return 0;
}


/*
Time Complexity
버블정렬 (size: 20000) 수행결과 : 829 ms
선택정렬 (size: 20000) 수행결과 : 375 ms
삽입정렬 (size: 20000) 수행결과 : 170 ms

버블정렬 (size: 40000) 수행결과 : 3392 ms
선택정렬 (size: 40000) 수행결과 : 1577 ms
삽입정렬 (size: 40000) 수행결과 : 643 ms

버블정렬 (size: 80000) 수행결과 : 12702 ms
선택정렬 (size: 80000) 수행결과 : 6009 ms
삽입정렬 (size: 80000) 수행결과 : 1902 ms


WORST vs. BEST
버블랜덤 (size: 20000) 수행결과 : 887 ms
선택랜덤 (size: 20000) 수행결과 : 385 ms
삽입랜덤 (size: 20000) 수행결과 : 172 ms

버블오름 (size: 20000) 수행결과 : 447 ms
선택오름 (size: 20000) 수행결과 : 380 ms
삽입오름 (size: 20000) 수행결과 : 0 ms

버블역정렬 (size: 20000) 수행결과 : 621 ms
선택역정렬 (size: 20000) 수행결과 : 333 ms
삽입역정렬 (size: 20000) 수행결과 : 392 ms

HeapSort
힙정렬 (size: 20000) 수행결과 : 7 ms
힙정렬 (size: 40000) 수행결과 : 16 ms
힙정렬 (size: 80000) 수행결과 : 29 ms

QuickSort
퀵정렬 랜덤 (size: 20000) 수행결과 : 4 ms
퀵정렬 랜덤 (size: 40000) 수행결과 : 9 ms
퀵정렬 랜덤 (size: 80000) 수행결과 : 17 ms

QuickSort
퀵정렬 랜덤 (size: 3000) 수행결과 : 0 ms
퀵-오름차순 (size: 3000) 수행결과 : 10 ms

// 스택 size : 4M
퀵정렬 랜덤 (size: 10000) 수행결과 : 3 ms
퀵-오름차순 (size: 10000) 수행결과 : 104 ms

// 스택 size : 8M
퀵정렬 랜덤 (size: 20000) 수행결과 : 4 ms
퀵-오름차순 (size: 20000) 수행결과 : 378 ms

*/

