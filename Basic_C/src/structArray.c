/*
 * structArray.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */

#include <stdio.h>

typedef struct fruit{
	char name[20]; //20����Ʈ
	int price; 	  // 4������
 	char season[20]; // 20����Ʈ
}fruit;

int main(void){
	fruit arFruit[3] = {
			{"���", 1500, "����"},
			{"��", 10000, "����"},
			{"�ٳ���", 900, "�����"}

	};

	for(int i = 0; i < 3; i++){
		printf("%s %d�� %s\n", arFruit[i].name, arFruit[i].price, arFruit[i].season);
	}

	return 0;
}
