/*
 * ArrayListMain.c
 *
 *  Created on: 2021. 7. 20.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:44w77) // unsigned <-->signed 관련 warning (비쥬얼스튜디오

#include "ArrayList.h"

// 리스트 출력 도우미 함수
void printList(List *pList){
	list_init_iter(pList);
	printf("[");
	while(list_hasNext(pList)){
		printf("%d, ", list_next(pList));
	}
	printf("]\n");
}


int main(void){
	//setvbuf(stdout, NULL, _IONBF, 0); // Windows 용 Eclipse의 Console 창 글자 안 나오는 오류 수정
	//setvbuf(stderr, NULL, _IONBF, 0);

	List myList;

	list_init(&myList); // 리스트 초기화

	printList(&myList); // []
	list_add(&myList, 100); // 데이터 추가
	printList(&myList); // [100]
	list_add(&myList, 50);
	printList(&myList); // [100, 50]
	list_add(&myList, 100);
	printList(&myList); // [100, 50, 100]
	list_add(&myList, 20);
	printList(&myList); // [100, 50, 100, 20]
	list_add(&myList, 45); // 45, 75은 배열의 길이 초과. 데이터 추가 실패
	printList(&myList); // [100, 50, 100, 20]
	list_add(&myList, 75);
	printList(&myList); // [100, 50, 100, 20]

	printf("\n");
	// 데이터 수정
	list_set(&myList, 0, 40); // 데이터 수정 : 0번째 데이터를 40으로 수정하겠다는 뜻
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 40); // 수정 실패
	printList(&myList); // [40, 30, 100, 20]

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList)); // 4
	printf("\n");

	//n번째 데이터 조회
	Data data;
	if(list_get(&myList, 0, &data)) printf("0번째 : %d\n", data); // 40 출력
	if(list_get(&myList, 6, &data)) printf("6번째 : %d\n", data); // 실패
	if(list_get(&myList, 2, &data)) printf("2번째 : %d\n", data); // 100 출력
	printf("\n");


	// 데이터 삭제
	printf("섹제 전\n");
	printList(&myList); // [40, 30, 100, 20]
	printf("섹제 후\n");
	list_remove(&myList, 2);
	printList(&myList); // [40, 30, 20]
	list_remove(&myList, 2);
	printList(&myList); // [40, 30]
	printf("데이터 개수는 %d\n", list_length(&myList)); // 2
	list_remove(&myList, 0);
	printList(&myList);  // [30]
	list_remove(&myList, 0);
	printList(&myList);  // []
	list_remove(&myList, 0); // 실패
	printList(&myList);  // 실패
	printf("데이터 개수는 %d\n", list_length(&myList)); // 0
	printf("\n");


	// 데이터 삽입
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList); // [10, 20]
	list_insert(&myList, 1, 40);
	printList(&myList); // [10, 40, 20]
	list_insert(&myList, 0, 5);
	printList(&myList); // [5, 10, 40, 20]
	list_insert(&myList, 0, 50);
	printList(&myList); // 실패
	printf("데이터 개수는 %d\n", list_length(&myList)); // 4
	printf("\n");

	list_init(&myList); // 초기화


	// insert가 list의 끝에 추가(add)를 가능하게 동작하기
	list_insert(&myList, 0, 5);
	printList(&myList);
	list_insert(&myList, 1, 25);
	printList(&myList);
	list_insert(&myList, 2, 45);
	printList(&myList);
	list_insert(&myList, 3, 55);
	printList(&myList);
	list_insert(&myList, 4, 75); // 실패
	printList(&myList); // [5, 25, 45, 55]




	list_destroy(&myList);

	{				// 성능 테스트 //
		printf("---------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("프로파일링 시작 : 아무키나 누르세요\n");


		printf("%d개를 insert...\n", test_size);

		// 프로파일링
		start = clock();
		for(unsigned int i = 0; i < test_size; i++){
			list_insert(&myList, 0, i);
		}
		end = clock();
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("insert 결과 : %ld ms 경과\n", end - start);

		//---------------------------------------------------
		printf("프로파일링 시작 : 아무키나 누르세요\n");

		printf("%d 개 get...\n", test_size);

		// 프로파일링
		start = clock();
		for(unsigned int i = 0; i < test_size; i++){
			list_get(&myList, i, &data); // 0번째 부터 insert
		}
		end = clock();
		printf("get 결과 : %d  ms 경과\n", end - start);

		//-----------------------------------------------

		printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷\n");

		printf("%d 개 remove...\n", test_size);
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0); // 0번째 부터 remove
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("remove 결과 : %ld ms 경과\n", end - start);

		printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷\n");




		list_destroy(&myList);
	}
	return 0;
}

