/*
 * struct_TypedefTest.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */

#include <stdio.h>
#include <string.h>

/*
 ���� ����ü �����
 �����̸�, ����, ����
 ���, ��, �ٳ���
 ��ȭ �� ���
 */

typedef struct fruit{
	char name[20];
	int price;
	char season[20];
}fruit;
int main(void){

	fruit apple = {"���", 1500, "����"};
	fruit pear = {"��", 10000, "����"};
	fruit banana = {"�ٳ���", 900, "���"};

	printf("%s %d�� %s\n", apple.name, apple.price, apple.season);
	printf("%s %d�� %s\n", pear.name, pear.price, pear.season);
	printf("%s %d�� %s\n", banana.name, banana.price, banana.season);

	double avg = (apple.price + pear.price + banana.price) / 3.0;
	printf("��� : %.1lf", avg);
	return 0;
}

//-------------------------------------------------------

// Ÿ�Ե��� ���¹� //

typedef struct animal{
	char name[20];
	int age;
	char feed[20];
}animal; // Ÿ�Ե���

int main(void){
	animal dog = {"MAx", 3, "���"};
	//dog.name = "alal"; // ���ڿ� ������
	strcpy(dog.name, "Alex");
	printf("%s\n", dog.name);

	dog.age = 12;
	printf("%d\n", dog.age);

	strcpy(dog.feed, "���");
	printf("%s\n", dog.feed);
	return 0;
}

