/*
 * struct_1.c
 *
 *  Created on: 2021. 7. 15.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오



struct Student{ // struct Student가 하나의 타입
	int age;		// 멤버변수들
	char gender;
	char name[30];
};

typedef struct _Stu{
	int age;
	char gender;
	char name[30];
}Stu;  	// typedef으로 정의된 타입명으로 간단히 사용할 수 있음



char* fmt1 = "이름 : %s, 성별 : %c, 나이 %d\n"; //포맷만들음


void printStudent(Stu* p){
	printf(fmt1, p->name, p->gender, p->age);
} // 구조체를 매개변수로 받는 함수 작성시 가급적 포인터로 받자.(메모리용이)


int main(void){



	{	// 일반적 strut
		//구조체 struct
		//여러 데이터들을 모아 정의한 사용자 정의 데이터형

		struct Student stu1; //선언

		stu1->age = 10; //접근
		stu1.gender = "m";
		strcpy(stu1.name, "김성호"); //문자열 입력 함수

		printf(fmt1, stu1.name, stu1.gender, stu1.age);
	}

	printf("\n");

	{
		//typedef를 이용

		Stu stu1, stu2;
		Stu stu3 = {100, "f", "김지호"};

		printf(fmt1, stu3.name, stu3.gender, stu3.age);

		Stu *p = &stu3; // 구조체 포인터 선언
		printf(fmt1, (*p).name, (*p).gender, (*p).age);
		printf(fmt1, p->name, p->gender, p->age);
		//구조체 포인터로 멤버 접근시 -> 연산자 사용하기

		printStudent(p);

	}


	return 0;
}



