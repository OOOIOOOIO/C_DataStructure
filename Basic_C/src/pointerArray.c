/*
 * pointerArray.c
 *
 *  Created on: 2021. 7. 2.
 *      Author: polit
 */

#include <stdio.h>

// 포인터 배열

void changeValue(int**);
void changeValue_2(int*[]);

int main(void){
	int num1 = 10, num2 = 20, num3 = 30;

	int* PArrNum[3] = {&num1, &num2, &num3};

	for(int i = 0; i < 3; i++){        // ==  *PArrNum[i]
		printf("%d\n", **(PArrNum+i)); //주소값이 나오면 한번 더 참조해줘야됨. 왜? 포인터는 주소값에서 들어가니까
	}
		changeValue(PArrNum);
		changeValue_2(PArrNum);
	for(int i = 0; i < 3; i++){
			printf("%d\n", **(PArrNum+i));
	}

	return 0;
}

void changeValue(int** PArrNum){ // 이중포인터로 받아보기
	for(int i = 0; i < 3; i++){
		**(PArrNum+i) += 30;
	}
}


void changeValue_2(int* PArrNum[]){ // 단일포인터로 받기
	for(int i = 0; i < 3; i++){
		*(PArrNum[i]) += 30;
	}
}

