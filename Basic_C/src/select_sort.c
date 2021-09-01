/*
 * function.c
 *
 *  Created on: 2021. 6. 29.
 *      Author: polit
 */
#include <stdio.h>

// c��� : �ڷᱸ���� ����⿡ ����
// java : �ڷᱸ���� ����ϱ⿡ ����

void select_sort(int* arData, int length){ //�����ʹ� �ּҰ����� ����
	for(int i = 0; i < length-1; i++) { //�������� ���� �ʿ� ���� : -1
			for(int j = i+1; j < length; j++){ // ���ؾ��ؼ� i+1
				if(arData[i] > arData[j]){ //[]�� ���������� �ּҰ��� �����ϴ°���, �迭 == �����ͻ��
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

	select_sort(arData, length); // �迭�� �ּҰ��� �Ѱ���

	for(int i = 0; i < length; i++){
		printf("%d ", arData[i]);
	}
	return 0;
}

