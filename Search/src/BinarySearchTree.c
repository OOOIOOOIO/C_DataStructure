/*
 * BinarySearchTree.c
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

// 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot){
	*ppRoot = NULL;

}


// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
int bst_insert(BTreeNode **ppRoot, BTData data){ // 이중포인터인 이유 : 비어있을 수도 있기 때문에
	BTreeNode *parentNode = NULL; // parent node
	BTreeNode *curNode = *ppRoot; // current node : 일단 root부터 시작한다
	BTreeNode *newNode = NULL;

	// 새로운 노드가 추가될 위치를 찾아 내려간다
	while(curNode != NULL){ // 중단노드까지 내려가면, 그곳이
		if(data == btree_get_data(curNode)){
			return FAIL; // BST에선 Key의 중복허용 X
		}

		parentNode = curNode;

		if(btree_get_data(curNode) > data){   // 삽입하려는 data가 노드의 데이터보다 더 작다면
			curNode = btree_get_left(curNode);
		}
		else{	  							  // 삽입하려믄 data가 노드의 데이터보다 더 크다면
			curNode = btree_get_right(curNode);
		}
	}

	// 추가할 새 노드의 생성
	newNode = btree_make_node();
	btree_set_data(newNode, data);

	// parentNode의 서브 노드에 새 노드를 추가
	if(parentNode != NULL){
		if(data < btree_get_data(parentNode)){ // 부모의 데이터보다 작다면 left로 붙인다
			btree_make_left(parentNode, newNode);
		}
		else{								   // 부모의 데이터보다 크다면 right로 붙인다
			btree_make_right(parentNode, newNode);
		}
	}
	// 첫번째 노드의 경우, 새 노드가 루트위치이기에 parentNode는 NULL인 상태이다.
	else{
		*ppRoot = newNode; // 루트 세팅!
	}

	return SUCCESS;
}


// 이진 탐색 트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode * bst_search(BTreeNode *pRoot, BTData data){
	BTreeNode *curNode = pRoot; // root부터 탐색 시작
	BTData curData; // current data

	while(curNode != NULL){ // 탐색을 해 내려가다 종단노드까지 도달하면 결국 탐색실패한 것
		curData = btree_get_data(curNode);

		if(data == curData){
			return curNode; // 발견! 탐색 성공. 노드의 포인터를 리턴.
		}

		if(data < curData){ // data 값이 노드의 데이터보다 작다면 left로 이동
			curNode = btree_get_left(curNode);
		}
		else{				// data 값이 노드의 데이터보다 크다면 right로 이동
			curNode = btree_get_right(curNode);
		}

	}

	// 탐색 결과 없음. 실패
	return NULL;
}

