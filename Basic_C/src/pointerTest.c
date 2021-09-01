/*
 * pointerTest.c
 *
 *  Created on: 2021. 7. 2.
 *      Author: polit
 */
#include <stdio.h>
//인트형 변수를 선언하여 사용자에게 값을 입력받은 후
//해당 값을 2배로 바꿔주는 void타입 함수 선언 및 사용

int main(void){
	int data = 0;
	int* PData = &data;

	scanf("%d", &data);

	fun_1(PData);

	int num = data;
	PData = num;

	fun_2(PData);


	printf("%d\n", *PData);

	return 0;
}

void fun_1(int* data){
	*data *= 3;
}

void fun_2(int* data){
	*data *= *data;
}
