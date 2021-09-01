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
//	char* dot[] = {",", ".."}; //���ڿ� ���¹�
	while(1){

	printf("�Է¹��� ������ ������ �Է��Ͻÿ�.\n");
	fflush(stdout);
	scanf("%d", &size);

	arNum = (int*)calloc(size, sizeof(int)); // �����Ҵ�
	printf("������ŭ �Է��� ������ �Է��ϼ���.\n");

	for(int i = 0; i < size; i++){
		fflush(stdout);
		scanf("%d", arNum+i);
	}
	system("cls");
	again:
	printf("\n1.��������\n2.��������\n3.������\n");
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
			printf("�����մϴ�.\n");
			break;
	default :
		printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���.");
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

