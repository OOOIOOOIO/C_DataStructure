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
	struct animal pig = {.name = "����", .age =  20, .feed =  "���"};
	printf("���� �̸��� �Է��ϼ���\n");
	fflush(stdout);
	scanf("%s", dog.name);

	printf("���� ������ �Է��ϼ���\n");
	fflush(stdout);
	scanf("%d", &dog.age);

	printf("���� ������ �Է��ϼ���\n");
	fflush(stdout);
	scanf("%s", dog.feed);

	printf("������ �̸� : %s\n", dog.name);
	printf("������ ���� : %d\n", dog.age);
	printf("������ ���� : %s\n", dog.feed);

	printf("���� �̸� : %s\n ���� ���� : %d\n ���� ���� : %s\n", pig.name, pig.age, pig.feed);
	return 0;
}

