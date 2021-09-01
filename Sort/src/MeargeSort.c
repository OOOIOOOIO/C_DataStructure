/*
 * MeargeSort.c
 *
 *  Created on: 2021. 8. 17.
 *      Author: polit
 */
#include <stdio.h>

#define MAX_SIZE 8
int sorted[MAX_SIZE]; // �߰����� ����


// 2���� ������ �迭 list[left ... mid]�� list[mid+1 ... right]�� �պ� ����

void merge(int list[], int left, int mid, int right){
	int i = left;	 // ���ҵǾ� ���ĵ� ���� ����Ʈ�� ���� �ε���
	int j = mid + 1; // ���ҵǾ� ���ĵ� ������ ����Ʈ�� ���� �ε���
	int k = left;	 // ������ ����Ʈ�� ���� �ε���(��ĥ �迭)



	// ���ҵ� �迭�� sorted��  �պ�
	while(i <= mid && j <= right){
		if(list[i] <= list[j]) // ���ʰ� ������ �迭�� �ε��� ���� ���ؼ� sorted�� ���� �� �պ�
			sorted[k++] = list[i++]; // k[0]�� ���� ���� k++�Ǿ� 1�� �Ǵ°���
		else
			sorted[k++] = list[j++];
	}


	// �����̳� ������ �迭�� ���� ���� ��� ���� �ִ� ������ �ϰ� ����
	if(i > mid){ // ������ ���� ���� ��� ������ ����
		while(j <= right){
			sorted[k++] = list[j++];
		}
	}
	else{		// �������� ���� ���� ��� ���� ����
		while(i <= mid)
			sorted[k++] = list[i++];
	}

	//  �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	for(k = left; k <= right; k++){
		list[k] = sorted[k];
	}

}

void mergeSort(int list[], int left, int right){
	int mid;

	if(left < right){
		mid = (left + right) / 2; 	   	 // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ��ϰ� ���� --> ����(divide)
		mergeSort(list, left, mid); 	 // ���� �κ� ����Ʈ ���� --> ����(conquer)

		mergeSort(list, mid + 1, right);// ���� �κ� ����Ʈ ���� --> ����(conquer)
		merge(list, left, mid, right);	 // ���ҵ� 2���� �κ� �迭�� ���� �� �պ��ϴ� ���� --> ����(combine)
	}
}


int main(){
	int list[MAX_SIZE] = {21, 10 , 12, 20, 25, 13, 15, 22};

	// �պ� ���� ����(left : �迭�� ���� �ε���, right : �迭�� �� �ε���)
	mergeSort(list, 0, MAX_SIZE - 1);

	for(int i = 0; i < MAX_SIZE; i++){
		printf("%d\n", list[i]);
	}
	return 0;
}

