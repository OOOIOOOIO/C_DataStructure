/*
 * BinaryTree.h
 *
 *  Created on: 2021. 8. 1.
 *      Author: polit
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

/* Binary Tree의 데이터 */
typedef int BTData;

typedef struct _bTreeNode{
	BTData data;
	struct _bTreeNode *pLeft; // left sub tree (left child)
	struct _bTreeNode *pRight; // right sub tree (right child)

}BTreeNode;




/* Binary Tree의 동작 */

//트리 노드 생성
BTreeNode* btree_make_node(void);



// 노드 데어터 읽기
BTData btree_get_data(BTreeNode *bt);



// 노드 데이터 쓰기
void btree_set_data(BTreeNode *bt, BTData data);



// 노드의 Left sub tree
BTreeNode* btree_get_left(BTreeNode *bt);



// 노드의 Right sub tree
BTreeNode* btree_get_right(BTreeNode *bt);



// bt의 left에 sub tree 연결
void btree_make_left(BTreeNode *bt, BTreeNode *sub);



// bt의 right에 sub tree 연결
void btree_make_right(BTreeNode *bt, BTreeNode *sub);



// 현재 노드부터 삭제
void btree_delete(BTreeNode *bt);


//----------------------------------------------------------------------

// Traversing
// 노드를 visit하여 노드의 데이터에 대해 수행할 함수(함수포인터) 타입 선언
typedef void fnVistNode(BTData data);


// 주어딘 노드 bt부터 시작하여 traversing하면서
// node를 visit할 때마다 action() 수행
void btree_preoder_traverse(BTreeNode *bt, fnVistNode action);

void btree_inoder_traverse(BTreeNode *bt, fnVistNode action);

void btree_postoder_traverse(BTreeNode *bt, fnVistNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVistNode action);








#endif /* BINARYTREE_H_ */
