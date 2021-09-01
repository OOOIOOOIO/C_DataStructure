/*
 * pointerTask.c
 *
 *  Created on: 2021. 7. 2.
 *      Author: polit
 */

#include <stdio.h>
//포인터 상수로 선택정렬 만들어보기(포인터상수 = 배열)

void main(){
	int arr[5] = {1, 3, 2, 10, 7};
	int length = sizeof(arr)/sizeof(int);
	sort(arr, length);

	for(int i = 0; i < length; i++){
		printf("%d\n", arr[i]);
	}
}
void sort(int* list, int length){
	for(int i = 0; i < length-1; i++){
		for(int j = i+1; j < length; j++){
			if(*(list+i) > *(list+j)){
				int temp = *(list+i);
				*(list+i) = *(list+j);
				*(list+j)  = temp;
			}
		}
	}
}

