/*
 * hangle(task).c
 *
 *  Created on: 2021. 7. 7.
 *      Author: polit
 */

//1024 -> 일공이사 출력되게 만들기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int idx = 0;
	int input = 0;
	int size[] = {0, };
	int temp = 0;
	char arr[10][5] = {"0","1","2","3","4","5","6","7","8","9"};
	char arr2[10][5] ={"영","일","이","삼","사","오","육","칠","팔","구"};


	printf("숫자를 입력하세요\n");
	fflush(stdout);
	scanf("%d", &input);

	while(1){
		if(input / 10 == 0) break;

		temp = input % 10;
		input = input / 10;
		size[idx] = temp;
		idx++;

	}

	int length = sizeof(size) / sizeof(int);

	int h = 0;




	return 0;
}


 //강사님이 한 거 //


void changToHangle(char*);

int main(void){
	char arNum[10] = ""; //일차원 문자열배열 선언법 {""} 이거아님
	printf("한글로 변경하실 정수를 입력하세요\n");
	fflush(stdout);
	scanf("%s", arNum);

	changeToHangle(arNum);

	return 0;
}


void changeToHangle(char* arNum){ //이차원 배열이기 떄문에 포인터 배열로 선언
	// 정수, 문자열 1024 / 아스키코드에서 0 = 48 / 2차원 문자열 쓰는 법
	char arHangle[10][5] = {"공", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};
	//arHangle[0]- 48;  아스키코드로 "1" = 49 따라서 48을 빼주면 1이됨

	for(int i = 0; i <strlen(arNum); i++){
		printf("%s", arHangle[arNum[i]-48]);
	}
	printf("\n");
}
