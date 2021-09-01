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

// 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot);


// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
int bst_insert(BTreeNode **ppRoot, BTData data);


// 이진 탐색 트리를 대상으로 데이터 탐색, 발견한 노드 리턴. 함수선언
BTreeNode * bst_search(BTreeNode *pRoot, BTData data);


#endif /* BINARYSEARCHTREE_H_ */
