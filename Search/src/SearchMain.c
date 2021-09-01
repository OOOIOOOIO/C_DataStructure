/*
 * SearchMain.c
 *
 *  Created on: 2021. 8. 10.
 *      Author: polit
 */

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "LinkedListS.h"
#include "BinarySearchTree.h"

#define DATA_SIZE 100


void printArr(int arr[], int n){
	printf("[");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("]\n\n");

}


// 오름차순 배열 생성
void genIncSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = i + 1;
	}
}


// 내림차순 배열 생성
void genDecSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = n - i;
	}
}

// 무작위 배열 생성, 1 ~ n 범위

// 배열 섞기
void shuffleArr(int arr[], int n){
	srand(time(NULL));
	if(n > 1){ // 배열길이가 2개 이상인 경우에만 shuffle
		for(int i = 0; i < n-1; i++){
			//i번쨰와 i 오른쪽의 임의의 j번째 swap
			int j = i + rand() / (RAND_MAX / (n-i) + 1);

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}



void genRandom(int arr[], int n){
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}



// 배열로부터 List 생성
void genList(List *pList, int arr[], int n){
	for(int i = 0; i < n; i++){
		list_add(pList, arr[1]);
	}
}

// 배열로부터 BST 생성
void genBST(BTreeNode **ppRoot, int arr[], int n){
	for(int i = 0; i < n; i++){
		bst_insert(ppRoot, arr[i]);
	}
}
//-------------------------------------------------------------------

typedef void* fnSearch(void *, int); // 검색함수 타입선언

// collection에서 arr[]의 data들을 탐색하여
// 평균 검색 시간을 체크
// ex) List <-- [5, 1, 2, 4, 3]
//	   List에서 [1, 2, 3, 4, 5] 탐색


void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title){
	clock_t start, end;
	int cnt = 0; // search가 성공한 횟수

	// 각각의 개별적인 search의 경과시간을 누적합산한 뒤 평균을 구한다.
	long duration = 0;
	for(int i = 0; i < n; i++){
		start = clock();

		if(search(collection, arr[i]) != NULL){
			cnt++;
		}

		end = clock();
		duration += end-start;
	}

	printf("%s (%d/%d개 탐색) 수행결과 %.3f ms\n", title, cnt, n, (double)duration / n);

}


int main(void){

	int srcArr[DATA_SIZE];
	int workArr[DATA_SIZE];

	genIncSorted(srcArr, DATA_SIZE); // 오름차순 배열

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	shuffleArr(workArr, DATA_SIZE); // 배열 섞기

	List list;
	list_init(&list);
	genList(&list, workArr, DATA_SIZE); // list <-- workArr
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "리스트탐색");
	list_destroy(&list);

	//------------------------------------------------------------------

	BTreeNode *pRoot;
	bst_make_init(&pRoot);

	genBST(&pRoot, workArr, DATA_SIZE);

	chkTimeLapArray(bst_search, pRoot, srcArr, DATA_SIZE, "BTS탐색");

	btree_delete(pRoot);
	return 0;
}


/*
리스트탐색 (10000/10000개 탐색) 수행결과 0.023 ms
리스트탐색 (20000/20000개 탐색) 수행결과 0.049 ms
리스트탐색 (40000/40000개 탐색) 수행결과 0.091 ms

리스트탐색 (10000/10000개 탐색) 수행결과 0.023 ms
BST탐색 (10000/10000개 탐색) 수행결과 0.001 ms
리스트탐색 (20000/20000개 탐색) 수행결과 0.048 ms
BST탐색 (20000/20000개 탐색) 수행결과 0.001 ms
리스트탐색 (40000/40000개 탐색) 수행결과 0.093 ms
BST탐색 (40000/40000개 탐색) 수행결과 0.001 ms
리스트탐색 (80000/80000개 탐색) 수행결과 0.213 ms
BST탐색 (80000/80000개 탐색) 수행결과 0.003 ms

*/








