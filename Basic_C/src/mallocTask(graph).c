/*
 * mallocTask(graph).c
 *
 *  Created on: 2021. 7. 6.
 *      Author: polit
 */

//// �л� �� ��ŭ ������ �Է¹޾� ����ϱ�

#include <stdio.h>
#include <stdio.h>
#include <Windows.h>

//�׷��� �׷�����

int main(void){
	int* student = 0;
	int size = 0;

	printf("�л� ���� �Է��ϼ���\n");
	fflush(stdout);
	scanf("%d", &size);

	student = (int*)malloc(sizeof(int)*size);

	for(int i = 0; i < size; i++){
		printf("%d�� �л� ���� �Է� : \n", i+1);
		fflush(stdout);
		scanf("%d", student+i);
	}

	//system("cls");

	for(int i = 10; i > 0; i--){
		printf("%3d ��", i*10);
		for(int j = 0; j < size; j++){
			if(student[j] / 10 >= i){
				if(student[j] /10 == i){
					printf(" ����");
				}
				else{
					printf(" ����");
				}

			}
			else{
				printf("   ");

			}
			//Sleep(500);
		}
		printf("\n");
	}

	printf("%3d ��", 0);

	for(int i = 0; i <size; i++){
		if(student[i] != 0){
			printf("������");
		}
		//printf("����������");
	}
	//Sleep(500);
	printf("\n");

	printf("    ");
	for(int i = 0; i < size; i++){
		printf(" %d", student[i]);
	}

	printf("\n");
	free(student);
	return 0;
}
