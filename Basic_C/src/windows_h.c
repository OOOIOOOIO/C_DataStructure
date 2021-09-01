/*
 * lotto.c
 *
 *  Created on: 2021. 6. 30.
 *      Author: polit
 */
#include <stdio.h>
#include <Windows.h> //컴파일러 제어

int main(void){
	int arr[5] = {1, 2, 3, 4, 5};

	for(int i = 0; i < 5; i++){
		printf("%d\n", arr[i]);
		Sleep(500); //1000 = 1초
	}
	return 0;
}
