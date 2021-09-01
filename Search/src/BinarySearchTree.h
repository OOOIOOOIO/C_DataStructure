/*
 * BinarySearchTree.h
 *
 *  Created on: 2021. 8. 10.
 *      Author: polit
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BinaryTreeS.h"
#define SUCCESS 1
#define FAIL 0

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot);


// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
int bst_insert(BTreeNode **ppRoot, BTData data);


// ���� Ž�� Ʈ���� ������� ������ Ž��, �߰��� ��� ����. �Լ�����
BTreeNode * bst_search(BTreeNode *pRoot, BTData data);


#endif /* BINARYSEARCHTREE_H_ */
