/*
 * BstMain.c
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

#include "BinarySearchTree.h"

int main(){

	BTreeNode *pRoot; // BST의 루트

	BTreeNode *pSearchNode; // 탐색 노드

	bst_make_init(&pRoot); // 초기화(이중포인터)

	bst_insert(&pRoot, 12);
	bst_insert(&pRoot, 8);
	bst_insert(&pRoot, 9);
	bst_insert(&pRoot, 17);
	bst_insert(&pRoot, 10);
	bst_insert(&pRoot, 4);
	bst_insert(&pRoot, 21);
	bst_insert(&pRoot, 2);
	bst_insert(&pRoot, 13);
	bst_insert(&pRoot, 7);
	/*
	*             12
	*          ↙     ↘
	*         8        17
	*       ↙ ↘     ↙  ↘
	*      4    9    13   21
	*   ↙  ↘   ↘
	*   2   7    10
	*/


	BTreeNode *p =  bst_search(pRoot, 9);
	if(p) printf("%d\n", p->data);
	else printf("없다");

	//-----------------------------------------

	btree_delete(pRoot);


	return 0;
}
