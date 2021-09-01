/*
 * MeargeSort.c
 *
 *  Created on: 2021. 8. 17.
 *      Author: polit
 */
#include <stdio.h>

#define MAX_SIZE 8
int sorted[MAX_SIZE]; // 추가적인 공간


// 2개의 인접한 배열 list[left ... mid]와 list[mid+1 ... right]의 합병 과정

void merge(int list[], int left, int mid, int right){
	int i = left;	 // 분할되어 정렬된 왼쪽 리스트에 대한 인덱스
	int j = mid + 1; // 분할되어 정렬된 오른쪽 리스트에 대한 인덱스
	int k = left;	 // 정렬할 리스트에 대한 인덱스(합칠 배열)



	// 분할된 배열을 sorted에  합병
	while(i <= mid && j <= right){
		if(list[i] <= list[j]) // 왼쪽과 오른쪽 배열의 인덱스 들을 비교해서 sorted에 정렬 및 합병
			sorted[k++] = list[i++]; // k[0]에 먼저 들어가고 k++되어 1이 되는거임
		else
			sorted[k++] = list[j++];
	}


	// 왼쪽이나 오른쪽 배열이 먼저 끝날 경우 남아 있는 값들을 일괄 복사
	if(i > mid){ // 왼쪽이 먼저 끝날 경우 오른쪽 복사
		while(j <= right){
			sorted[k++] = list[j++];
		}
	}
	else{		// 오른쪽이 먼저 끝날 경우 왼쪽 복사
		while(i <= mid)
			sorted[k++] = list[i++];
	}

	//  배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for(k = left; k <= right; k++){
		list[k] = sorted[k];
	}

}

void mergeSort(int list[], int left, int right){
	int mid;

	if(left < right){
		mid = (left + right) / 2; 	   	 // 중간 위치를 계산하여 리스트를 균등하게 분할 --> 분할(divide)
		mergeSort(list, left, mid); 	 // 앞쪽 부분 리스트 분할 --> 정복(conquer)

		mergeSort(list, mid + 1, right);// 뒤쪽 부분 리스트 분할 --> 정복(conquer)
		merge(list, left, mid, right);	 // 분할된 2개의 부분 배열을 정렬 및 합병하는 과정 --> 결합(combine)
	}
}


int main(){
	int list[MAX_SIZE] = {21, 10 , 12, 20, 25, 13, 15, 22};

	// 합병 정렬 수행(left : 배열의 시작 인덱스, right : 배열의 끝 인덱스)
	mergeSort(list, 0, MAX_SIZE - 1);

	for(int i = 0; i < MAX_SIZE; i++){
		printf("%d\n", list[i]);
	}
	return 0;
}

