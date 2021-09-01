/*
 * baseballgame.c
 *
 *  Created on: 2021. 7. 6.
 *      Author: polit
 */

 //기존 배열을 섞은 후
 //레벨별로 자릿수를 선정한다
 //섞는 법 : 0번째 방을 고정시키고 ? 번째 방과 위치를 바꾼다.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	int baseball[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int cnt = 0, s = 0, b = 0;
	int r = 0, temp = 0, level = 0;
	int choice = 0, rest = 0;
	srand(time(NULL));

	for(int i = 0; i < 10000; i++){
		r = rand() % 9 + 1;
		temp = baseball[0];
		baseball[0] = baseball[r];
		baseball[r] = temp;
	}

	printf("BASEBALL GAME START\n");

	while(1){
		printf("레벨을 입력하세요(1레벨 : 3자리,c최대 8레벨)\n");
		fflush(stdout);
		scanf("%d", &level);
		if(level > 0 && level < 9){
			break;
		}
		else{
			printf("1~8까지의 수만 입력 가능합니다.");
		}
	}

	printf("cpu : ");
	for(int i = 0; i < level+2; i++){
		printf("%d", baseball[i]);
	}
	printf("\n");

	while(1){
		s = 0;
		b = 0;
		printf("user : ");
		fflush(stdout);
		scanf("%d", &choice);
		cnt++;

		for(int i = level + 1; i >= 0; i--){
			rest = choice % 10;
			if(baseball[i] == rest){
				s++;

			}
			for(int j = level + 1; j >= 0; j--){
				if(baseball[j] == rest) {
					b++;
				}
			}
			choice /= 10;
		}
		if(s == level + 2){
			break;
		}
		printf("%d strike %d ball\n", s, b-s);
	}
	printf("%d번만에 성공!\n", cnt);
	return 0;
}
