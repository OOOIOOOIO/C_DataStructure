/*
 * ArrayList.h
 *
 *  Created on: 2021. 7. 20.
 *      Author: polit
 */


#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

/*
*	ArrayList �� ADT
*
*	ArrayList ��
*	���� : n��° ��ȸ ������
*	���� : ����, ���� ������.
*
*	���� : �뷮
*/

#define SUCCESS 1
#define FAIL 0
#define LIST_LEN 30000


	/*	<ArrayList�� ������> */

typedef int Data; // �����ʹ� int Ÿ��

typedef struct _ArrayList{
	Data arr[LIST_LEN]; // ������(��)
	int numData;        // ����Ʈ ���� ������ ����
	int curPosition;    // iteration
}ArrayList;




	/*	<ArrayList�� ����>  */


typedef ArrayList List;


// ����Ʈ �ʱ�ȭ
void list_init(List *pList);

// ����Ʈ ����
void list_destroy(List *pList);

// ������ �߰�
int list_add(List *pList, Data data);

// n���� ������ ����
int list_set(List *pList, int n, Data data);

// ������ ����
int list_length(List *pList);

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List *pList);

// ������ ��ȸ, iteration ���� ������ ����
Data list_next(List *pList);

// ������ ��ȸ, iteration ���� ������ �ֳ�? Ȯ��
int list_hasNext(List *pList);

// ������ ��ȸ : n��° ������ �� ��ȸ
int list_get(List *pList, int n, Data *pData);

// n��° ������ ����
int list_remove(List *pList, int n);

// n��° ������ ����
int list_insert(List *pList, int n, Data data);




#endif /* ARRAYLIST_H_ */
