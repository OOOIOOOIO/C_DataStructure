/*
 * malloc.c
 *
 *  Created on: 2021. 7. 5.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int* mAR = 0;
	int arData[10] = {0, };
	mAR = (int*)malloc(sizeof(int*)*5);
	mAR = (int*)calloc(5, sizeof(int)); // �ʱ�ȭ ��Ű�� : 0���� �ʱ�ȭ ��
	mAR = (int*)realloc(mAR, sizeof(int)*10); // ũ�� ���� : �߰��� 5ĭ�� �þ
	mAR = (int*)calloc(10, sizeof(int));     // ���� �ִ� �� �״�� ����(������)

//	for(int i = 0; i < 5; i++){  //   <- �ʱ�ȭ��Ű��(�ʱ갪)
//		mAR[i] = i+1;
//	}
//	int num = 5;
//	int arr[num] = {0, }; // �����迭�� �Ұ���
//	int* arrr = 0;
//	arrr = (int*)malloc(sizeof(int*)*num); // �����Ҵ��� ����!!


	for(int i = 0; i < 10; i++){
		printf("%d\n", mAR[i]); // ������ �迭�̶� �Ȱ���
								// �����͸�[i], *(�����͸� + i)
	}

	free(mAR);
	return 0;
}

