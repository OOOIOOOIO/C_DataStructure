/*
 * BstMain.c
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

int main(){

	BTreeNode *pRoot; // BST�� ��Ʈ

	BTreeNode *pSearchNode; // Ž�� ���

	bst_make_init(&pRoot); // �ʱ�ȭ(����������)

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
	*          ��     ��
	*         8        17
	*       �� ��     ��  ��
	*      4    9    13   21
	*   ��  ��   ��
	*   2   7    10
	*/


	BTreeNode *p =  bst_search(pRoot, 9);
	if(p) printf("%d\n", p->data);
	else printf("����");

	//-----------------------------------------

	btree_delete(pRoot);


	return 0;
}
