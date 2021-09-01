/*
 * QuickSort.h
 *
 *  Created on: 2021. 8. 5.
 *      Author: polit
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

// �迭 �ȿ��� �ΰ� �� �ٲٱ�
void Swap(int arr[], int idx1, int idx2);


// �迭�� ���� ���� �ɰ���(�ɰ� index(<- pivot) ����)
int Partition(int arr[], int left, int right);


 // ��������� ������ ����
void QuickSort(int arr[], int left, int right);


//����Ʈ �����׽�Ʈ��
void QuickSortMain(int arr[], int n);

#endif /* QUICKSORT_H_ */
