/*
 * QuickSort.c
 *
 *  Created on: 2021. 8. 5.
 *      Author: polit
 */
#include <stdio.h>

#include "QuickSort.h"

// 배열 안에서 두개 값 바꾸기
void Swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


// 배열의 정렬 영역 쪼개기(쪼갤 index(<- pivot) 리턴)
int Partition(int arr[], int left, int right){

	int pivot = arr[left]; // pivot의 위치는 가장 왼쪽값! ( 값)
	int low = left + 1; // low는 pivot의 left+1 인덱스부터 시작 ( 인덱스)
	int high = right; // high는 right 인덱스부터 시작 ( 인덱스)


	while(low <= high) // low, high가 교차되지 않을 때까지 반복하면서 low, high 이동
	{
		// low는 우측으로 계속이동, pivot보다 큰 것을 만날 때까지!
		while(pivot >= arr[low] && low <= right){
			low++;
		}

		// high는 좌측으로 계속 이동, pivot보다 작은 것을 만날 떄까지!
		while(pivot <= arr[high] && high >= (left+1)){
			high--;
		}

		// low와 high가 멈추면!
		// low, high가 교차되지 않은 상채라면 Swap 진행
		if(low <= high){
			Swap(arr, low, high);
		}
	}



	// pivot(left)과 high가 가리키는 대상과 교환
	Swap(arr, left, high);
	// 이 시점에서 high의 우측은 pivot보다 큰 값들이 몰려있고
	// high의 좌측은 pivot보다 작은 값들이 몰려있다
	return high; // 정해진 pivot의 위치(인덱스) 리턴
}


 // 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right){

	if(left <= right){
		int pivot = Partition(arr, left, right); // pivot을 정하고 둘로 쪼갬

		// pivot의 왼쪽 영역을 퀵정렬
		QuickSort(arr, left, pivot - 1);

		// pivot의 오른쪽 영역을 퀵정렬
		QuickSort(arr, pivot +1, right);
	}
}


//퀵소트 성능테스용
void QuickSortMain(int arr[], int n){
	QuickSort(arr, 0, n - 1);

}

