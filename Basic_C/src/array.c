/*
 ============================================================================
 Name        : c_class.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

// 2차원 배열 연습

int main(void) {
	int arrData[3][4] = {0,	};
	int cLength = sizeof(arrData[0]) / sizeof(int);
	int rLength = sizeof(arrData) / cLength / sizeof(int);
	int cnt = 0;

	for(int i = 0; i < rLength; i++){
		for(int j = 0; j < cLength; j++){
			cnt += 2;
			*(*(arrData+i)+j) = cnt;
			// == arrData[i][j]
		}
	}

	for(int i = 0; i < rLength; i++){
			for(int j = 0; j < cLength; j++){
				printf("%0 2d\n", arrData[i][j]); // 2자리 수 맞춰줌
			}
		}

}

// 2차원 배열 예제 : 1동, 2동 각 동마다 3호씩 있다.

int main(void){
	int arrDong[2][3] = {0, };
	int cLength = sizeof(arrDong[0]) / sizeof(int);
	int rLength = sizeof(arrDong) / cLength / sizeof(int);
	int total = 0;
	int sum[2] = {0, };

	for(int i = 0; i < rLength; i++){
		for(int j = 0; j < cLength; j++){
			printf("%d동 %d호 월세를 입력하세요(단위 : 만원)", i+1, j+1);
			fflush(stdout);
			scanf("%d", *(arrDong+i)+j);

			total += arrDong[i][j];
			sum[i] += arrDong[i][j];
		}
	}

	for(int i = 0; i <rLength; i++){
		printf("%d동 총월세 : %d만원\n", i+1, sum[i]);
		printf("%d동 평균월세 : %.1lf만원\n", i+1, (double)sum[i]/cLength);

	}
	printf("개나리 아파트 총 월세 : %d 만원", total);
	printf("개나리 아파트 평균 월세 : %.1lf 만원",(double)total/(cLength*rLength));

	return 0;
}
