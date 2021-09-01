/*
 * pointerTask.c
 *
 *  Created on: 2021. 7. 2.
 *      Author: polit
 */

#include <stdio.h>
//������ ����� �������� ������(�����ͻ�� = �迭)

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

