/*
 * QuickSort.h
 *
 *  Created on: 2021. 8. 5.
 *      Author: polit
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

// 배열 안에서 두개 값 바꾸기
void Swap(int arr[], int idx1, int idx2);


// 배열의 정렬 영역 쪼개기(쪼갤 index(<- pivot) 리턴)
int Partition(int arr[], int left, int right);


 // 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right);


//퀵소트 성능테스트용
void QuickSortMain(int arr[], int n);

#endif /* QUICKSORT_H_ */
