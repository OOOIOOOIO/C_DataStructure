/*
 * Sort.c
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


void printArr(int arr[], int n){
	printf("[");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("]\n\n");

}
// 무작위 배열 생성, 1 ~ n 범위
void genRandom(int arr[], int n){
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}


// 오름차순 배열 생성
void genIncSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = i + 1;
	}
}


// 내림차순 배열 생성
void genDecSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = n - i;
	}
}


// 배열 섞기
void shuffleArr(int arr[], int n){
	srand(time(NULL));
	if(n > 1){ // 배열길이가 2개 이상인 경우에만 shuffle
		for(int i = 0; i < n-1; i++){
			//i번쨰와 i 오른쪽의 임의의 j번째 swap
			int j = i + rand() / (RAND_MAX / (n-i) + 1);

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}



//----------------------------------------------------

// 성능 체크
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle){
	clock_t start, end;
	start = clock();

	sort(arr, n);

	end = clock();

	printf("%s (size : %d) 수행결과 : %ld ms\n", szTitle, n, end - start);
}



//----------------------------------------------------

// 버블정렬
void BubbleSort(int arr[], int n){
	int i, j;
	int temp;

	for(i = 0; i < n-1; i++){ // cycle 회전 횟수, 총 n-1번
		for(j = 0; j < (n-i) - 1; j++){
			if(arr[j] > arr[j+1]){ // 인접한 두 값 비교, 1 cycle 당 (n-i) -1 번 발생
				temp = arr[j];
				arr[j] = arr[j+1];
				 arr[j+1] = temp;
			}
		}
		// 한 사이클 종료, 중간과정 출력
		//printArr(arr, n);
	}
}



// 선택정렬
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
		if(i != min_idx){ // 1 cycle 당 많아야 1번 발생
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
		// 한 사이클 종료, 중간과정 출력
		//printArr(arr, n);
	}
}
// min_idx의 값은 1번째 이후의 원소 중에서 가장 작은 값을 가리키고 있을 것이다.
// 그러면 arr[i]값과 arr[min_idx]의 값을 교환하면 된다.
// 1번째 우측(i+1)부터 시작하여 우측에서 1번째보다 작은것 중 가장 최솟값 찾기
// 최솟값의 위치(min_idx)를 '선택'하는 것이 목표!




// 삽입정렬
void InsertionSort(int arr[], int n){
	int insData;
	for(int i = 1; i < n; i++){ // i = 1부터 시작
		insData = arr[i]; // 삽입할 데이터 선택

		int j;
		for(j = i - 1; j>= 0; j--){ // j를 i 왼쪽부터 왼쪽으로 검색
			if(arr[j] > insData){ // 삽입하려는 데이터보다
				arr[j+1] = arr[j]; // j뻔쨰가 크면 j를 우측으로 한 칸 옮김
			}
			else
				break; // 삽입 위치(j)를 찾았으니 멈춤
		}
		//결정된 j 위치의 바로 오른쪽이 insert될 위치
		arr[j+1] = insData;

		// 한 사이클 종료, 중간과정 출력
		//printArr(arr, n);
	}
}



