/*
 * structStudentTask.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */

/*
 * 학생 구조체 만들기
 * 학생번호, 이름, 성별, 점수
 * 총 점수, 평균 점수
 * 2개 반에 3명씩 있다
 * 2차원 구조체 배열
 * 반별 평균, 총합
 * 1학년 평균, 총합
 */


#include <stdio.h>
#define ROW_SIZE 2
#define COL_SIZE 3
typedef struct student{
	int studentNumber;
	char name[20];
	char sex[20];
	int score;
}student;

int main(void){
	student class[ROW_SIZE][COL_SIZE];
	int ban_sum[ROW_SIZE] = {0, };
	double ban_avg[ROW_SIZE] = {0.0, };
	int cnt = 0, sum = 0;
	int class_length = sizeof(class[0][0].score/sizeof(int));


	for(int i = 0; i < ROW_SIZE; i++){
		cnt = 0;
		for(int j = 0; j < COL_SIZE; j++){
			printf("==============================\n");
			cnt++;
			class[i][j].studentNumber = cnt;
			printf("1학년 %d반 %d번 학생 이름 : ", i+1, class[i][j].studentNumber);
			fflush(stdout);
			scanf("%s", class[i][j].name);

			printf("%s 학생 성별 : ", class[i][j].name);
			fflush(stdout);
			scanf("%s", class[i][j].sex);

			printf("%s 학생의 국어 영어 수학 성적을 입력하세요\n ", class[i][j].name);
			for(int k = 0; k < class_length; k++){
				fflush(stdout);
				scanf("%d", class[i][j].score + k);
				ban_sum[i] += class[i][j].score + k;
				sum += class[i][j].score + k;
			}

		}
		ban_avg[i] = (double)ban_sum[i] / COL_SIZE;

	}

	double avg = (double)sum / (ROW_SIZE*COL_SIZE);

	for(int i = 0; i < ROW_SIZE; i++){
		for(int j = 0; j < COL_SIZE; j++){
			printf("%d반 %d번 %s %s\n", i+1, class[i][j].studentNumber, class[i][j].name, class[i][j].sex);
			printf("국영수 : ");
			for(int k = 0; k < class_length; k++){
				printf("%d점", class[i][j].score + k);
			}
			printf("\n");
		}
		printf("====================================\n");

		printf("%d반 총 점수 : %d점\n", i+1, ban_sum[i]);
		printf("%d반 총 점수 : %d점\n", i+1, ban_avg[i]);
		printf("====================================\n");

	}

	printf("1학년 총 점수 : %d점\n 1학년 총 평균 점수 : \n", sum, avg);
	printf("====================================\n");

	return 0;
}
