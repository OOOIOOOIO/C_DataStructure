/*
 * ArrayListMain.c
 *
 *  Created on: 2021. 7. 20.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:44w77) // unsigned <-->signed ���� warning (�����Ʃ���

#include "ArrayList.h"

// ����Ʈ ��� ����� �Լ�
void printList(List *pList){
	list_init_iter(pList);
	printf("[");
	while(list_hasNext(pList)){
		printf("%d, ", list_next(pList));
	}
	printf("]\n");
}


int main(void){
	//setvbuf(stdout, NULL, _IONBF, 0); // Windows �� Eclipse�� Console â ���� �� ������ ���� ����
	//setvbuf(stderr, NULL, _IONBF, 0);

	List myList;

	list_init(&myList); // ����Ʈ �ʱ�ȭ

	printList(&myList); // []
	list_add(&myList, 100); // ������ �߰�
	printList(&myList); // [100]
	list_add(&myList, 50);
	printList(&myList); // [100, 50]
	list_add(&myList, 100);
	printList(&myList); // [100, 50, 100]
	list_add(&myList, 20);
	printList(&myList); // [100, 50, 100, 20]
	list_add(&myList, 45); // 45, 75�� �迭�� ���� �ʰ�. ������ �߰� ����
	printList(&myList); // [100, 50, 100, 20]
	list_add(&myList, 75);
	printList(&myList); // [100, 50, 100, 20]

	printf("\n");
	// ������ ����
	list_set(&myList, 0, 40); // ������ ���� : 0��° �����͸� 40���� �����ϰڴٴ� ��
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 40); // ���� ����
	printList(&myList); // [40, 30, 100, 20]

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList)); // 4
	printf("\n");

	//n��° ������ ��ȸ
	Data data;
	if(list_get(&myList, 0, &data)) printf("0��° : %d\n", data); // 40 ���
	if(list_get(&myList, 6, &data)) printf("6��° : %d\n", data); // ����
	if(list_get(&myList, 2, &data)) printf("2��° : %d\n", data); // 100 ���
	printf("\n");


	// ������ ����
	printf("���� ��\n");
	printList(&myList); // [40, 30, 100, 20]
	printf("���� ��\n");
	list_remove(&myList, 2);
	printList(&myList); // [40, 30, 20]
	list_remove(&myList, 2);
	printList(&myList); // [40, 30]
	printf("������ ������ %d\n", list_length(&myList)); // 2
	list_remove(&myList, 0);
	printList(&myList);  // [30]
	list_remove(&myList, 0);
	printList(&myList);  // []
	list_remove(&myList, 0); // ����
	printList(&myList);  // ����
	printf("������ ������ %d\n", list_length(&myList)); // 0
	printf("\n");


	// ������ ����
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList); // [10, 20]
	list_insert(&myList, 1, 40);
	printList(&myList); // [10, 40, 20]
	list_insert(&myList, 0, 5);
	printList(&myList); // [5, 10, 40, 20]
	list_insert(&myList, 0, 50);
	printList(&myList); // ����
	printf("������ ������ %d\n", list_length(&myList)); // 4
	printf("\n");

	list_init(&myList); // �ʱ�ȭ


	// insert�� list�� ���� �߰�(add)�� �����ϰ� �����ϱ�
	list_insert(&myList, 0, 5);
	printList(&myList);
	list_insert(&myList, 1, 25);
	printList(&myList);
	list_insert(&myList, 2, 45);
	printList(&myList);
	list_insert(&myList, 3, 55);
	printList(&myList);
	list_insert(&myList, 4, 75); // ����
	printList(&myList); // [5, 25, 45, 55]




	list_destroy(&myList);

	{				// ���� �׽�Ʈ //
		printf("---------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("�������ϸ� ���� : �ƹ�Ű�� ��������\n");


		printf("%d���� insert...\n", test_size);

		// �������ϸ�
		start = clock();
		for(unsigned int i = 0; i < test_size; i++){
			list_insert(&myList, 0, i);
		}
		end = clock();
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("insert ��� : %ld ms ���\n", end - start);

		//---------------------------------------------------
		printf("�������ϸ� ���� : �ƹ�Ű�� ��������\n");

		printf("%d �� get...\n", test_size);

		// �������ϸ�
		start = clock();
		for(unsigned int i = 0; i < test_size; i++){
			list_get(&myList, i, &data); // 0��° ���� insert
		}
		end = clock();
		printf("get ��� : %d  ms ���\n", end - start);

		//-----------------------------------------------

		printf("�ƹ�Ű�� ������ ������ ���۵˴ϴ�: ������\n");

		printf("%d �� remove...\n", test_size);
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0); // 0��° ���� remove
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("remove ��� : %ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������\n");




		list_destroy(&myList);
	}
	return 0;
}

