/*
 * mallocStruct.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct furit{
	char name[20];
	int price;
	char season[20];
}F;

int main(void){
	F* arFruit;
	int size = 0;
	int sum = 0;

	printf("입력하실 과일의 갯수를 알려주세요.");
	fflush(stdout);
	scanf("%d", &size);

	arFruit = (F*)malloc(sizeof(F)*size);

	for(int i = 0; i < size; i++){
		printf("%d번째 과일 이름 : ", i + 1);
		fflush(stdout);
		scanf("%s", arFruit[i].name);

		printf("과일 가격 : ");
		fflush(stdout);
		scanf("%d", arFruit[i].price);

		printf("과일 계절 : ");
		fflush(stdout);
		scanf("%s", arFruit[i].season);
		sum += arFruit[i].price;
	}
	printf("=========================\n");

	for(int i = 0; i < size; i++){
		printf("%s %d %s\n", arFruit[i]);
	}
	printf("=========================\n");
	printf("과일들의 평균 가격 : %.2lf\n", (double)sum / size);

	free(arFruit);
	return 0;
}

