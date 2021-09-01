/*
 * structArray.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */

#include <stdio.h>

typedef struct fruit{
	char name[20]; //20바이트
	int price; 	  // 4바이츠
 	char season[20]; // 20바이트
}fruit;

int main(void){
	fruit arFruit[3] = {
			{"사과", 1500, "가을"},
			{"배", 10000, "가을"},
			{"바나나", 900, "사계절"}

	};

	for(int i = 0; i < 3; i++){
		printf("%s %d원 %s\n", arFruit[i].name, arFruit[i].price, arFruit[i].season);
	}

	return 0;
}
