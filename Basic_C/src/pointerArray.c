/*
 * pointerArray.c
 *
 *  Created on: 2021. 7. 2.
 *      Author: polit
 */

#include <stdio.h>

// ������ �迭

void changeValue(int**);
void changeValue_2(int*[]);

int main(void){
	int num1 = 10, num2 = 20, num3 = 30;

	int* PArrNum[3] = {&num1, &num2, &num3};

	for(int i = 0; i < 3; i++){        // ==  *PArrNum[i]
		printf("%d\n", **(PArrNum+i)); //�ּҰ��� ������ �ѹ� �� ��������ߵ�. ��? �����ʹ� �ּҰ����� ���ϱ�
	}
		changeValue(PArrNum);
		changeValue_2(PArrNum);
	for(int i = 0; i < 3; i++){
			printf("%d\n", **(PArrNum+i));
	}

	return 0;
}

void changeValue(int** PArrNum){ // ���������ͷ� �޾ƺ���
	for(int i = 0; i < 3; i++){
		**(PArrNum+i) += 30;
	}
}


void changeValue_2(int* PArrNum[]){ // ���������ͷ� �ޱ�
	for(int i = 0; i < 3; i++){
		*(PArrNum[i]) += 30;
	}
}

