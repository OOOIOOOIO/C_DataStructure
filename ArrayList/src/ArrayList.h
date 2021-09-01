/*
 * ArrayList.h
 *
 *  Created on: 2021. 7. 20.
 *      Author: polit
 */


#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

/*
*	ArrayList 의 ADT
*
*	ArrayList 의
*	장점 : n번째 조회 빠르다
*	단점 : 삭제, 삽입 느리다.
*
*	장점 : 용량
*/

#define SUCCESS 1
#define FAIL 0
#define LIST_LEN 30000


	/*	<ArrayList의 데이터> */

typedef int Data; // 데이터는 int 타입

typedef struct _ArrayList{
	Data arr[LIST_LEN]; // 데이터(들)
	int numData;        // 리스트 안의 데이터 개수
	int curPosition;    // iteration
}ArrayList;




	/*	<ArrayList의 동작>  */


typedef ArrayList List;


// 리스트 초기화
void list_init(List *pList);

// 리스트 제거
void list_destroy(List *pList);

// 데이터 추가
int list_add(List *pList, Data data);

// n번쨰 데이터 수정
int list_set(List *pList, int n, Data data);

// 데이터 개수
int list_length(List *pList);

// 데이터 조회, iteration 초기화
void list_init_iter(List *pList);

// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List *pList);

// 데이터 조회, iteration 다음 데이터 있나? 확인
int list_hasNext(List *pList);

// 데이터 조회 : n번째 데이터 값 조회
int list_get(List *pList, int n, Data *pData);

// n번째 데이터 삭제
int list_remove(List *pList, int n);

// n번째 데이터 삽입
int list_insert(List *pList, int n, Data data);




#endif /* ARRAYLIST_H_ */
