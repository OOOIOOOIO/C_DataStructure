/*
 * SearchMain.c
 *
 *  Created on: 2021. 8. 10.
 *      Author: polit
 */

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

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


// �������� �迭 ����
void genIncSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = i + 1;
	}
}


// �������� �迭 ����
void genDecSorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = n - i;
	}
}

// ������ �迭 ����, 1 ~ n ����

// �迭 ����
void shuffleArr(int arr[], int n){
	srand(time(NULL));
	if(n > 1){ // �迭���̰� 2�� �̻��� ��쿡�� shuffle
		for(int i = 0; i < n-1; i++){
			//i������ i �������� ������ j��° swap
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



// �迭�κ��� List ����
void genList(List *pList, int arr[], int n){
	for(int i = 0; i < n; i++){
		list_add(pList, arr[1]);
	}
}

// �迭�κ��� BST ����
void genBST(BTreeNode **ppRoot, int arr[], int n){
	for(int i = 0; i < n; i++){
		bst_insert(ppRoot, arr[i]);
	}
}
//-------------------------------------------------------------------

typedef void* fnSearch(void *, int); // �˻��Լ� Ÿ�Լ���

// collection���� arr[]�� data���� Ž���Ͽ�
// ��� �˻� �ð��� üũ
// ex) List <-- [5, 1, 2, 4, 3]
//	   List���� [1, 2, 3, 4, 5] Ž��


void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title){
	clock_t start, end;
	int cnt = 0; // search�� ������ Ƚ��

	// ������ �������� search�� ����ð��� �����ջ��� �� ����� ���Ѵ�.
	long duration = 0;
	for(int i = 0; i < n; i++){
		start = clock();

		if(search(collection, arr[i]) != NULL){
			cnt++;
		}

		end = clock();
		duration += end-start;
	}

	printf("%s (%d/%d�� Ž��) ������ %.3f ms\n", title, cnt, n, (double)duration / n);

}


int main(void){

	int srcArr[DATA_SIZE];
	int workArr[DATA_SIZE];

	genIncSorted(srcArr, DATA_SIZE); // �������� �迭

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	shuffleArr(workArr, DATA_SIZE); // �迭 ����

	List list;
	list_init(&list);
	genList(&list, workArr, DATA_SIZE); // list <-- workArr
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "����ƮŽ��");
	list_destroy(&list);

	//------------------------------------------------------------------

	BTreeNode *pRoot;
	bst_make_init(&pRoot);

	genBST(&pRoot, workArr, DATA_SIZE);

	chkTimeLapArray(bst_search, pRoot, srcArr, DATA_SIZE, "BTSŽ��");

	btree_delete(pRoot);
	return 0;
}


/*
����ƮŽ�� (10000/10000�� Ž��) ������ 0.023 ms
����ƮŽ�� (20000/20000�� Ž��) ������ 0.049 ms
����ƮŽ�� (40000/40000�� Ž��) ������ 0.091 ms

����ƮŽ�� (10000/10000�� Ž��) ������ 0.023 ms
BSTŽ�� (10000/10000�� Ž��) ������ 0.001 ms
����ƮŽ�� (20000/20000�� Ž��) ������ 0.048 ms
BSTŽ�� (20000/20000�� Ž��) ������ 0.001 ms
����ƮŽ�� (40000/40000�� Ž��) ������ 0.093 ms
BSTŽ�� (40000/40000�� Ž��) ������ 0.001 ms
����ƮŽ�� (80000/80000�� Ž��) ������ 0.213 ms
BSTŽ�� (80000/80000�� Ž��) ������ 0.003 ms

*/








