/*
 * ListBasedStack.h
 *
 *  Created on: 2021. 7. 23.
 *      Author: polit
 */

#ifndef LISTBASEDSTACK_H_
#define LISTBASEDSTACK_H_

#define SUCCESS 1
#define FAIL 0

	/*	������ ������ */

typedef int Data;

typedef struct _node{
	Data data; //�׸�ĭ ���� ������

	struct _node *pNext; // �׸�ĭ ���� �ؽ�Ʈ

}Node;


typedef struct _listStack{
	Node *pTop; // �̹� ���������� numData�� ��� ����, pHead��� ����

}ListStack;


typedef ListStack Stack;




	/*	������ ����	 */

// ���� �ʱ�ȭ
void stack_init(Stack* pStack);

// ���� ����
void stack_destroy(Stack* pStack);

// ������ ������� Ȯ��
int stack_is_empty(Stack* pStack);

// push : top�� ������ �߰�
int stack_push(Stack* pStack, Data data);

// pop : top�� ������ ������
int stack_pop(Stack* pStack, Data* pData);

// peak : pop�� ������ �б�
int stack_peek(Stack* pStack, Data* pData);

#endif /* LISTBASEDSTACK_H_ */
