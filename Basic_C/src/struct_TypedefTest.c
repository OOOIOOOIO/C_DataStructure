/*
 * struct_TypedefTest.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */

#include <stdio.h>
#include <string.h>

/*
 과일 구조체 만들기
 과일이름, 가격, 계절
 사과, 배, 바나나
 기화 후 출력
 */

typedef struct fruit{
	char name[20];
	int price;
	char season[20];
}fruit;
int main(void){

	fruit apple = {"사과", 1500, "가을"};
	fruit pear = {"배", 10000, "가을"};
	fruit banana = {"바나나", 900, "사계"};

	printf("%s %d원 %s\n", apple.name, apple.price, apple.season);
	printf("%s %d원 %s\n", pear.name, pear.price, pear.season);
	printf("%s %d원 %s\n", banana.name, banana.price, banana.season);

	double avg = (apple.price + pear.price + banana.price) / 3.0;
	printf("평균 : %.1lf", avg);
	return 0;
}

//-------------------------------------------------------

// 타입데프 쓰는법 //

typedef struct animal{
	char name[20];
	int age;
	char feed[20];
}animal; // 타입데프

int main(void){
	animal dog = {"MAx", 3, "사료"};
	//dog.name = "alal"; // 문자열 오류남
	strcpy(dog.name, "Alex");
	printf("%s\n", dog.name);

	dog.age = 12;
	printf("%d\n", dog.age);

	strcpy(dog.feed, "고기");
	printf("%s\n", dog.feed);
	return 0;
}

