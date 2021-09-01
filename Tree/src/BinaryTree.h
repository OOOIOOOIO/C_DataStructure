/*
 * BinaryTree.h
 *
 *  Created on: 2021. 8. 1.
 *      Author: polit
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

/* Binary Tree�� ������ */
typedef int BTData;

typedef struct _bTreeNode{
	BTData data;
	struct _bTreeNode *pLeft; // left sub tree (left child)
	struct _bTreeNode *pRight; // right sub tree (right child)

}BTreeNode;




/* Binary Tree�� ���� */

//Ʈ�� ��� ����
BTreeNode* btree_make_node(void);



// ��� ������ �б�
BTData btree_get_data(BTreeNode *bt);



// ��� ������ ����
void btree_set_data(BTreeNode *bt, BTData data);



// ����� Left sub tree
BTreeNode* btree_get_left(BTreeNode *bt);



// ����� Right sub tree
BTreeNode* btree_get_right(BTreeNode *bt);



// bt�� left�� sub tree ����
void btree_make_left(BTreeNode *bt, BTreeNode *sub);



// bt�� right�� sub tree ����
void btree_make_right(BTreeNode *bt, BTreeNode *sub);



// ���� ������ ����
void btree_delete(BTreeNode *bt);


//----------------------------------------------------------------------

// Traversing
// ��带 visit�Ͽ� ����� �����Ϳ� ���� ������ �Լ�(�Լ�������) Ÿ�� ����
typedef void fnVistNode(BTData data);


// �־�� ��� bt���� �����Ͽ� traversing�ϸ鼭
// node�� visit�� ������ action() ����
void btree_preoder_traverse(BTreeNode *bt, fnVistNode action);

void btree_inoder_traverse(BTreeNode *bt, fnVistNode action);

void btree_postoder_traverse(BTreeNode *bt, fnVistNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVistNode action);








#endif /* BINARYTREE_H_ */
