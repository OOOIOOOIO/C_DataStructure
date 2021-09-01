/*
 * IterTest.c
 *
 *  Created on: 2021. 8. 12.
 *      Author: polit
 */
#include <stdio.h>

#define SUCCESS 1
#define FAIL 0
#define MAX_LENGTH 5

typedef struct _Iteration{
	int arr[MAX_LENGTH];
	int curPosition;
}Iter;


void iter_init(Iter *p){
	p->curPosition = -1;
}


int iter_hasNext(Iter *p){
	if(p->curPosition + 1 < MAX_LENGTH){
		return SUCCESS;
	}
	printf("ㄴ더이상 데이터가 존재하지 않습니다.\n");
	return FAIL;
}


int iter_next(Iter *p){
	p->curPosition++;
	return printf("%d ", p->arr[p->curPosition]);
}


int main(){
	Iter data = {{1, 2, 3, 4, 5}, -1,};
	data.arr[1] = 9;
	printf("%d %d\n", data.arr[1], data.curPosition);

	while(iter_hasNext(&data)){
		printf("%d ", iter_next(&data));
	}
}

