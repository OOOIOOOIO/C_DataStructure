/*
 * mallocTask(graph).c
 *
 *  Created on: 2021. 7. 6.
 *      Author: polit
 */

//// 학생 수 만큼 점수를 입력받아 출력하기

#include <stdio.h>
#include <stdio.h>
#include <Windows.h>

//그래프 그려보기

int main(void){
	int* student = 0;
	int size = 0;

	printf("학생 수를 입력하세요\n");
	fflush(stdout);
	scanf("%d", &size);

	student = (int*)malloc(sizeof(int)*size);

	for(int i = 0; i < size; i++){
		printf("%d번 학생 점수 입력 : \n", i+1);
		fflush(stdout);
		scanf("%d", student+i);
	}

	//system("cls");

	for(int i = 10; i > 0; i--){
		printf("%3d │", i*10);
		for(int j = 0; j < size; j++){
			if(student[j] / 10 >= i){
				if(student[j] /10 == i){
					printf(" ┌┐");
				}
				else{
					printf(" ││");
				}

			}
			else{
				printf("   ");

			}
			//Sleep(500);
		}
		printf("\n");
	}

	printf("%3d └", 0);

	for(int i = 0; i <size; i++){
		if(student[i] != 0){
			printf("─┴┴");
		}
		//printf("─────");
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
