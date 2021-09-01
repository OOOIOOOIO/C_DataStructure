/*
 * struct.c
 *
 *  Created on: 2021. 7. 7.
 *      Author: polit
 */
#include <stdio.h>

struct animal{
	int age;
	char name[20];
	char feed[20];
};

int main(void){
	struct animal dog;
	struct animal pig = {.name = "돼지", .age =  20, .feed =  "사료"};
	printf("동물 이름을 입력하세요\n");
	fflush(stdout);
	scanf("%s", dog.name);

	printf("동물 나이을 입력하세요\n");
	fflush(stdout);
	scanf("%d", &dog.age);

	printf("동물 먹이을 입력하세요\n");
	fflush(stdout);
	scanf("%s", dog.feed);

	printf("강아지 이름 : %s\n", dog.name);
	printf("강아지 나이 : %d\n", dog.age);
	printf("강아지 먹이 : %s\n", dog.feed);

	printf("돼지 이름 : %s\n 돼지 나이 : %d\n 돼지 먹이 : %s\n", pig.name, pig.age, pig.feed);
	return 0;
}

