/*
 * function.c
 *
 *  Created on: 2021. 6. 29.
 *      Author: polit
 */
#include <stdio.h>

// c언어 : 자료구조를 만들기에 적합
// java : 자료구조를 사용하기에 적합

void select_sort(int* arData, int length){ //포인터는 주소값으로 접근
	for(int i = 0; i < length-1; i++) { //마지막은 비교할 필요 없음 : -1
			for(int j = i+1; j < length; j++){ // 비교해야해서 i+1
				if(arData[i] > arData[j]){ //[]도 마찬가지로 주소값을 참조하는거임, 배열 == 포인터상수
					int temp = arData[i];
					arData[i] = arData[j];
					arData[j] = temp;
				}

			}
		}

}
int main(void){
	int arData[5] = {9, 1, 8, 5, 6};
	int length = sizeof(arData)/sizeof(int);

	select_sort(arData, length); // 배열의 주소값을 넘겨줌

	for(int i = 0; i < length; i++){
		printf("%d ", arData[i]);
	}
	return 0;
}

