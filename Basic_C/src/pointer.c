/*
 * pointer.c
 *
 *  Created on: 2021. 6. 30.
 *      Author: polit
 */
#include <stdio.h>

// 포인터 사용하기-1//

int main(void){
	int data = 10;
	int* PData = &data;
	*PData = 30; // data 값으 30으로 바뀜
	printf("%d\n", data);
	return 0;
}


// 포인터 사용하기 -2//

int main(void){
	int num = 0;
	fun(&num); // 포인터 사용
	printf("%d\n", num);
	return 0;
}

void fun(int* data){
	*data = 20;
}


// 이중 포인터 : 포인터의 주소값을 담는 저장공간

int main(void){
	int data = 10;
	int* PData = &data;
	int** PPData = &PData;

	printf("%p\n", &data);
	printf("%p\n", PData);
	printf("%p\n", PPData); //주소가 다 똑같다

	return 0;
}

void f(int**);

int main(void){
	int data = 10;
	int* PData = &data;

	printf("%d\n", *PData);
	f(&PData); // 이중포인터 사용
	printf("%d\n", *PData);
	return 0;
}

void f(int** x){
	int data = 20;
	*x = &data;
}
