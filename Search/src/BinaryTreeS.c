/*
 * BinaryTree.c
 *
 *  Created on: 2021. 8. 1.
 *      Author: polit
 */

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���

#include "BinaryTreeS.h"
//#include "ListQueueS.h"

//Ʈ�� ��� ����
BTreeNode* btree_make_node(void){
	BTreeNode *pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}



// ��� ������ �б�
BTData btree_get_data(BTreeNode *bt){
	return bt->data;
}



// ��� ������ ����
void btree_set_data(BTreeNode *bt, BTData data){
	bt->data = data;
}



// ����� Left sub tree
BTreeNode* btree_get_left(BTreeNode *bt){
	return bt->pLeft;
}



// ����� Right sub tree
BTreeNode* btree_get_right(BTreeNode *bt){
	return bt->pRight;
}



// bt�� left�� sub tree ����
void btree_make_left(BTreeNode *bt, BTreeNode *sub){
	if(bt->pLeft != NULL)
		btree_delete(bt->pLeft);

	bt->pLeft = sub;
}



// bt�� right�� sub tree ����
void btree_make_right(BTreeNode *bt, BTreeNode *sub){
	if(bt->pRight != NULL)
		btree_delete(bt->pRight);

	bt->pRight = sub;
}



// ���� ������ ����
void btree_delete(BTreeNode *bt){ // ��������� ����
	if(bt == NULL) return;

	// ������ post order ���( L -> R -> C) ������ ����
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	//printf("��带 ���� : %d \n", bt->data);
	free(bt); // C


}

//----------------------------------------------------------------------------
// Traversing
void btree_preoder_traverse(BTreeNode *bt, fnVistNode action){
	if(bt == NULL) return; // ��� ����

	// C -> L -> R
	action(bt->data); // C
	btree_preoder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_preoder_traverse(bt->pRight, action); // R : ���ȣ��
}


void btree_inoder_traverse(BTreeNode *bt, fnVistNode action){
	if(bt == NULL) return; // ��� ����

	// L -> R -> C
	btree_inoder_traverse(bt->pLeft, action); // L : ���ȣ��
	action(bt->data); // C
	btree_inoder_traverse(bt->pRight, action); // R : ���ȣ��
}


void btree_postoder_traverse(BTreeNode *bt, fnVistNode action){
	if(bt == NULL) return; // ��� ����

	// L -> R -> C
	btree_postoder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_postoder_traverse(bt->pRight, action); // R : ���ȣ��
	action(bt->data); // C

}




//// ���� : level-order
//void btree_levelorder_traverse(BTreeNode *bt, fnVistNode action)
//{
//	Queue q;
//	queue_init(&q);
//
//	// �ϴ� root�� ť�� enq
//	queue_enq(&q, (Data)bt);
//
//	// while(ť �� empty �ɶ�����)
//	while (!queue_is_empty(&q))
//	{
//		BTreeNode *btCurrent;
//
//		// dequeue �Ͽ� ���
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


