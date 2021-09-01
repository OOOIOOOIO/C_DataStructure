/*
 * Heap.c
 *
 *  Created on: 2021. 8. 2.
 *      Author: polit
 */
#include "HeapS.h"

#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // time, clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오


//--------------------------------------------------

//부모노드 인덱스 구하기
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx / 2 // >>, << 비트연산



// left 자식노드 인덱스 구하기
#define GET_LEFT_IDX(idx) ((idx) << 1) // idx * 2



// right 자식노드 인덱스 구하기
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // idx * 2 + 1


// 비교함수 대신 메크로(성능 up)
#define COMP_ASC(d1, d2) ((d2) - (d1)) // 오름차순
#define COMP_DESC(d1, d2) ((d1) - (d2)) // 내림차순

// idx의 자식들 중 우선 순위가 높은 자식의 index 값 리턴 --> delete에 사용
int getHigherPriority(Heap *ph, int idx){

	// 자식노드가 없다면 0 리턴
	if(GET_LEFT_IDX(idx) > ph->numData) return 0;

	// 자식이 하나만(유일하다면) 있다면 left임
	if(GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);

	// 자식이 둘 있는 경우 우선 순위 비교함수 사용
	if(COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
		return GET_RIGHT_IDX(idx); // Right가 더 우선순위가 높다

	else return GET_LEFT_IDX(idx); // Left가 더 우선순위가 높다
}

//----------------------------------------------------



// 동적메모리 초기화
void heap_init(Heap *ph, int len){
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) *(len + 1)); // +1개 만큼 메모리 필요 1-base이기 때문
	g_hp = ph;
}

// 동적메모리 해제
void heap_destroy(Heap *ph){
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}


// 힙이 비어있나
int heap_is_empty(Heap *ph){
	if(ph->numData == 0) return SUCCESS;

	return FAIL;
}



// 힙에 데이터 추가 (Insert)
void heap_insert(Heap *ph, HData data){
	//새로 Insert 되는 데이터는 맨 끝에시작
	int idx = ph->numData + 1; // 배열 인덱스는 '1'부터 시작.
							   // 전체 노드의 개수는 numData이고
							   // numData는 곧 마지막 노드의 인덱스다.

	//아래 while문 수행하면서 새로 insert 된 data가 위치할 idx를 결정
	while(idx != 1){ // 최상위 root에 도달할 때까지 수행 (최상위 노드 idx = 1)

		// 부모보다 우선순위가 높다면 부모와 자리(idx) 바꾸기
		if(COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0){
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)]; // 부모가 내려옴
			idx = GET_PARENT_IDX(idx); // idx -> 부모 idx
		}
		// 부모보다 우선순위가 같거나 작다면 멈춤
		else{
			break;
		}


	}

	ph->heapArr[idx] = data; // idx가 멈춘 곳에 새로 insert된 data 넣기
	ph->numData++; // 데이터 개수 증가
}



// 힙에서 (root를) 삭제하여 리턴 (Delete)
HData heap_delete(Heap *ph){
	// 인덱스 1번이 루트노드. 이를 제거하고 리턴
	HData rootData = ph->heapArr[1];

	// 마지막 노드가 자리잡을 위치의 idx를 결정
	// idx가 결정될 때까지 마지막 노드의 data를 보관해 놓는다
	HData lastElement = ph->heapArr[ph->numData]; // numData는 마지막 노드

	int idx = 1;  // 마지막 노드를 일단 root에 앉힘
	int childIdx;

	// 일단 자식노드중 우선순위가 높은 애를 선택
	// 만약 자식이 하나도 없다면 0이 리턴되어 whild문 종료
	// 아래 while 문은 결국 idx 값을 결정학 위함

	while(childIdx = getHigherPriority(ph, idx)){
		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료
		if(COMP_ASC(lastElement, ph->heapArr[childIdx]) >= 0)
			break;

		// 자식의 우선순위가 더 크다면 자식이 부모와 교체
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// 다음 비교를 위해 마지막 노드의 idx를 좀전의 자식위치로 내리기
		idx = childIdx;
	}
	// while이 다 끝난 자리(idx)가 마지막 노드(lastElement)가 위차할 곳

	ph->heapArr[idx] = lastElement;
	ph->numData--;

	return rootData; // 최초에 저장해 놓았던 root data 리턴
}

// 힙정렬
void HeapSort(int arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		heap_insert(g_hp, arr[i]);
	}

	for(i = 0; i < n; i++){
		arr[i] = heap_delete(g_hp);
	}
}



