/*
 * malloc.c
 *
 *  Created on: 2021. 7. 5.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int* mAR = 0;
	int arData[10] = {0, };
	mAR = (int*)malloc(sizeof(int*)*5);
	mAR = (int*)calloc(5, sizeof(int)); // 초기화 시키기 : 0으로 초기화 됨
	mAR = (int*)realloc(mAR, sizeof(int)*10); // 크기 변경 : 추가로 5칸이 늘어남
	mAR = (int*)calloc(10, sizeof(int));     // 원래 있는 건 그대로 있음(복사임)

//	for(int i = 0; i < 5; i++){  //   <- 초기화시키기(초깃값)
//		mAR[i] = i+1;
//	}
//	int num = 5;
//	int arr[num] = {0, }; // 정적배열은 불가능
//	int* arrr = 0;
//	arrr = (int*)malloc(sizeof(int*)*num); // 동적할당은 가능!!


	for(int i = 0; i < 10; i++){
		printf("%d\n", mAR[i]); // 사용법은 배열이랑 똑같음
								// 포인터명[i], *(포인터명 + i)
	}

	free(mAR);
	return 0;
}

