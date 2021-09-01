/*
 * struct_1.c
 *
 *  Created on: 2021. 7. 15.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - ���� / ���� / ���ڿ� ��ȯ �Լ���
#include <string.h> //strcpy, memcpy - ���ڿ� �Լ� / �޸𸮺� �Լ�
#include <conio.h> // _getch, putch - MS��� C��ǥ�� �Լ�
#include <time.h> // time, clock - �ð� ��¥ �Լ�
//#pragma warnig(disable:4996) // scanf() �� ���� c �Լ� ���� ���� �ذ� (�����Ʃ���
//#pragma warning(disable:4477) // unsigned <-->signed ���� warning (�����Ʃ���



struct Student{ // struct Student�� �ϳ��� Ÿ��
	int age;		// ���������
	char gender;
	char name[30];
};

typedef struct _Stu{
	int age;
	char gender;
	char name[30];
}Stu;  	// typedef���� ���ǵ� Ÿ�Ը����� ������ ����� �� ����



char* fmt1 = "�̸� : %s, ���� : %c, ���� %d\n"; //���˸�����


void printStudent(Stu* p){
	printf(fmt1, p->name, p->gender, p->age);
} // ����ü�� �Ű������� �޴� �Լ� �ۼ��� ������ �����ͷ� ����.(�޸𸮿���)


int main(void){



	{	// �Ϲ��� strut
		//����ü struct
		//���� �����͵��� ��� ������ ����� ���� ��������

		struct Student stu1; //����

		stu1->age = 10; //����
		stu1.gender = "m";
		strcpy(stu1.name, "�輺ȣ"); //���ڿ� �Է� �Լ�

		printf(fmt1, stu1.name, stu1.gender, stu1.age);
	}

	printf("\n");

	{
		//typedef�� �̿�

		Stu stu1, stu2;
		Stu stu3 = {100, "f", "����ȣ"};

		printf(fmt1, stu3.name, stu3.gender, stu3.age);

		Stu *p = &stu3; // ����ü ������ ����
		printf(fmt1, (*p).name, (*p).gender, (*p).age);
		printf(fmt1, p->name, p->gender, p->age);
		//����ü �����ͷ� ��� ���ٽ� -> ������ ����ϱ�

		printStudent(p);

	}


	return 0;
}



