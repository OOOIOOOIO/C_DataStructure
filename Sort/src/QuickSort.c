/*
 * QuickSort.c
 *
 *  Created on: 2021. 8. 5.
 *      Author: polit
 */
#include <stdio.h>

#include "QuickSort.h"

// �迭 �ȿ��� �ΰ� �� �ٲٱ�
void Swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


// �迭�� ���� ���� �ɰ���(�ɰ� index(<- pivot) ����)
int Partition(int arr[], int left, int right){

	int pivot = arr[left]; // pivot�� ��ġ�� ���� ���ʰ�! ( ��)
	int low = left + 1; // low�� pivot�� left+1 �ε������� ���� ( �ε���)
	int high = right; // high�� right �ε������� ���� ( �ε���)


	while(low <= high) // low, high�� �������� ���� ������ �ݺ��ϸ鼭 low, high �̵�
	{
		// low�� �������� ����̵�, pivot���� ū ���� ���� ������!
		while(pivot >= arr[low] && low <= right){
			low++;
		}

		// high�� �������� ��� �̵�, pivot���� ���� ���� ���� ������!
		while(pivot <= arr[high] && high >= (left+1)){
			high--;
		}

		// low�� high�� ���߸�!
		// low, high�� �������� ���� ��ä��� Swap ����
		if(low <= high){
			Swap(arr, low, high);
		}
	}



	// pivot(left)�� high�� ����Ű�� ���� ��ȯ
	Swap(arr, left, high);
	// �� �������� high�� ������ pivot���� ū ������ �����ְ�
	// high�� ������ pivot���� ���� ������ �����ִ�
	return high; // ������ pivot�� ��ġ(�ε���) ����
}


 // ��������� ������ ����
void QuickSort(int arr[], int left, int right){

	if(left <= right){
		int pivot = Partition(arr, left, right); // pivot�� ���ϰ� �ѷ� �ɰ�

		// pivot�� ���� ������ ������
		QuickSort(arr, left, pivot - 1);

		// pivot�� ������ ������ ������
		QuickSort(arr, pivot +1, right);
	}
}


//����Ʈ �����׽���
void QuickSortMain(int arr[], int n){
	QuickSort(arr, 0, n - 1);

}

