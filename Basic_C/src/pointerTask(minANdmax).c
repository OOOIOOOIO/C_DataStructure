/*
 * pointerTask_2.c
 *
 *  Created on: 2021. 7. 5.
 *      Author: polit
 */
/*
 * void�Լ� �����(�ִ񰪰� �ּڰ� ���ϱ�)
 * �迭�� �Ѱ��ָ� �ִ񰪰� �ּڰ��� �����ִ� �Լ�(�������� x)
 */
#include <stdio.h>

void maxANDmin(int*, int*, int*);

int main(void){
	int max = 0;
	int min = 0;
	int arr[7] = {1, 2, 3, 4, 5, 7, 6};

	maxANDmin(arr, &max, &min);

	printf("�ִ� : %d, �ּڰ� : %d\n", max, min);
	return 0;
}


void maxANDmin(int* arr, int* max, int* min){
	*max = *arr; // max�� min�� �ʱ갪 ����(arr[0])
	*min = *arr;

	for(int i = 1; i < 7; i++){
		if(*(arr+i) > *max) *max = *(arr+i) ;
		if(*(arr+i) < *min) *min = *(arr+i) ;

	} // �ٸ� ������ ���� �ٲٰ� ���� �� ���������͸� ����� �ּҰ����� �����ϱ�
}
