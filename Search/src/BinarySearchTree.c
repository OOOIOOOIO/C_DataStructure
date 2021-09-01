/*
 * BinarySearchTree.c
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

#include "BinarySearchTree.h"

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot){
	*ppRoot = NULL;

}


// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
int bst_insert(BTreeNode **ppRoot, BTData data){ // ������������ ���� : ������� ���� �ֱ� ������
	BTreeNode *parentNode = NULL; // parent node
	BTreeNode *curNode = *ppRoot; // current node : �ϴ� root���� �����Ѵ�
	BTreeNode *newNode = NULL;

	// ���ο� ��尡 �߰��� ��ġ�� ã�� ��������
	while(curNode != NULL){ // �ߴܳ����� ��������, �װ���
		if(data == btree_get_data(curNode)){
			return FAIL; // BST���� Key�� �ߺ���� X
		}

		parentNode = curNode;

		if(btree_get_data(curNode) > data){   // �����Ϸ��� data�� ����� �����ͺ��� �� �۴ٸ�
			curNode = btree_get_left(curNode);
		}
		else{	  							  // �����Ϸ��� data�� ����� �����ͺ��� �� ũ�ٸ�
			curNode = btree_get_right(curNode);
		}
	}

	// �߰��� �� ����� ����
	newNode = btree_make_node();
	btree_set_data(newNode, data);

	// parentNode�� ���� ��忡 �� ��带 �߰�
	if(parentNode != NULL){
		if(data < btree_get_data(parentNode)){ // �θ��� �����ͺ��� �۴ٸ� left�� ���δ�
			btree_make_left(parentNode, newNode);
		}
		else{								   // �θ��� �����ͺ��� ũ�ٸ� right�� ���δ�
			btree_make_right(parentNode, newNode);
		}
	}
	// ù��° ����� ���, �� ��尡 ��Ʈ��ġ�̱⿡ parentNode�� NULL�� �����̴�.
	else{
		*ppRoot = newNode; // ��Ʈ ����!
	}

	return SUCCESS;
}


// ���� Ž�� Ʈ���� ������� ������ Ž��, �߰��� ��� ����
BTreeNode * bst_search(BTreeNode *pRoot, BTData data){
	BTreeNode *curNode = pRoot; // root���� Ž�� ����
	BTData curData; // current data

	while(curNode != NULL){ // Ž���� �� �������� ���ܳ����� �����ϸ� �ᱹ Ž�������� ��
		curData = btree_get_data(curNode);

		if(data == curData){
			return curNode; // �߰�! Ž�� ����. ����� �����͸� ����.
		}

		if(data < curData){ // data ���� ����� �����ͺ��� �۴ٸ� left�� �̵�
			curNode = btree_get_left(curNode);
		}
		else{				// data ���� ����� �����ͺ��� ũ�ٸ� right�� �̵�
			curNode = btree_get_right(curNode);
		}

	}

	// Ž�� ��� ����. ����
	return NULL;
}

