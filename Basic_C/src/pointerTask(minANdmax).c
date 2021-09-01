/*
 * pointerTask_2.c
 *
 *  Created on: 2021. 7. 5.
 *      Author: polit
 */
/*
 * void함수 만들기(최댓값과 최솟값 구하기)
 * 배열을 넘겨주면 최댓값과 최솟값을 구해주는 함수(선택정렬 x)
 */
#include <stdio.h>

void maxANDmin(int*, int*, int*);

int main(void){
	int max = 0;
	int min = 0;
	int arr[7] = {1, 2, 3, 4, 5, 7, 6};

	maxANDmin(arr, &max, &min);

	printf("최댓값 : %d, 최솟값 : %d\n", max, min);
	return 0;
}


void maxANDmin(int* arr, int* max, int* min){
	*max = *arr; // max와 min에 초깃값 설정(arr[0])
	*min = *arr;

	for(int i = 1; i < 7; i++){
		if(*(arr+i) > *max) *max = *(arr+i) ;
		if(*(arr+i) < *min) *min = *(arr+i) ;

	} // 다른 지역의 값을 바꾸고 싶을 때 단일포인터를 사용해 주소값으로 수정하기
}
