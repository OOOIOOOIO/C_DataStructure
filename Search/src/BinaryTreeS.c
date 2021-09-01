/*
 * BinaryTree.c
 *
 *  Created on: 2021. 8. 1.
 *      Author: polit
 */

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "BinaryTreeS.h"
//#include "ListQueueS.h"

//트리 노드 생성
BTreeNode* btree_make_node(void){
	BTreeNode *pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}



// 노드 데어터 읽기
BTData btree_get_data(BTreeNode *bt){
	return bt->data;
}



// 노드 데이터 쓰기
void btree_set_data(BTreeNode *bt, BTData data){
	bt->data = data;
}



// 노드의 Left sub tree
BTreeNode* btree_get_left(BTreeNode *bt){
	return bt->pLeft;
}



// 노드의 Right sub tree
BTreeNode* btree_get_right(BTreeNode *bt){
	return bt->pRight;
}



// bt의 left에 sub tree 연결
void btree_make_left(BTreeNode *bt, BTreeNode *sub){
	if(bt->pLeft != NULL)
		btree_delete(bt->pLeft);

	bt->pLeft = sub;
}



// bt의 right에 sub tree 연결
void btree_make_right(BTreeNode *bt, BTreeNode *sub){
	if(bt->pRight != NULL)
		btree_delete(bt->pRight);

	bt->pRight = sub;
}



// 현재 노드부터 삭제
void btree_delete(BTreeNode *bt){ // 재귀적으로 구성
	if(bt == NULL) return;

	// 삭제는 post order 방식( L -> R -> C) 순서로 지움
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	//printf("노드를 삭제 : %d \n", bt->data);
	free(bt); // C


}

//----------------------------------------------------------------------------
// Traversing
void btree_preoder_traverse(BTreeNode *bt, fnVistNode action){
	if(bt == NULL) return; // 재귀 종료

	// C -> L -> R
	action(bt->data); // C
	btree_preoder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_preoder_traverse(bt->pRight, action); // R : 재귀호출
}


void btree_inoder_traverse(BTreeNode *bt, fnVistNode action){
	if(bt == NULL) return; // 재귀 종료

	// L -> R -> C
	btree_inoder_traverse(bt->pLeft, action); // L : 재귀호출
	action(bt->data); // C
	btree_inoder_traverse(bt->pRight, action); // R : 재귀호출
}


void btree_postoder_traverse(BTreeNode *bt, fnVistNode action){
	if(bt == NULL) return; // 재귀 종료

	// L -> R -> C
	btree_postoder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_postoder_traverse(bt->pRight, action); // R : 재귀호출
	action(bt->data); // C

}




//// 도전 : level-order
//void btree_levelorder_traverse(BTreeNode *bt, fnVistNode action)
//{
//	Queue q;
//	queue_init(&q);
//
//	// 일단 root를 큐에 enq
//	queue_enq(&q, (Data)bt);
//
//	// while(큐 가 empty 될때까지)
//	while (!queue_is_empty(&q))
//	{
//		BTreeNode *btCurrent;
//
//		// dequeue 하여 출력
//		queue_deq(&q, &btCurrent);
//		action(btCurrent->data);
//
//		// left -> enqueue
//		if (btCurrent->pLeft != NULL)
//			queue_enq(&q, btCurrent->pLeft);
//
//		// right-> euqueue
//		if (btCurrent->pRight != NULL)
//			queue_enq(&q, btCurrent->pRight);
//	}
//
//
//	queue_destroy(&q);
//}


