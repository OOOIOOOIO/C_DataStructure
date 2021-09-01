/*
 * mallocTask.c
 *
 *  Created on: 2021. 7. 5.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>



void sortAsc(int*, int);
void sortDsc(int*, int);

int main(void){
	int* arNum = 0;
	int size = 0;
	int select = 0;
//	char* dot[] = {",", ".."}; //문자열 쓰는법
	while(1){

	printf("입력받을 정수의 개수를 입력하시오.\n");
	fflush(stdout);
	scanf("%d", &size);

	arNum = (int*)calloc(size, sizeof(int)); // 동적할당
	printf("개수만큼 입력할 정수를 입력하세요.\n");

	for(int i = 0; i < size; i++){
		fflush(stdout);
		scanf("%d", arNum+i);
	}
	system("cls");
	again:
	printf("\n1.오름차순\n2.내림차순\n3.나가기\n");
	fflush(stdout);
	scanf("%d", &select);



	switch(select){
	case(1) :

			sortAsc(arNum, size);

		for(int i = 0; i < size; i++){
			printf("%d ", arNum[i]);

			}goto finish;

	case(2) :
			sortDsc(arNum, size);

			for(int i = 0; i < size; i++){
					printf("%d ", arNum[i]);

			}goto finish;

	case(3) :
			printf("종료합니다.\n");
			break;
	default :
		printf("잘못입력하였습니다. 다시 입력하세요.");
		goto again;

		}

	finish :
		free(arNum);
		return 0;
	}

	return 0;
}

void sortAsc(int* arr, int length){
	for(int i = 0; i < length-1; i++){
		for(int j = i+1; j < length; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

void sortDsc(int* arr, int length){
	for(int i = 0; i < length-1; i++){
		for(int j = i+1; j < length; j++){
			if(arr[i] < arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

