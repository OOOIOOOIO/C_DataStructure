/*
 * structStudentTask.c
 *
 *  Created on: 2021. 7. 9.
 *      Author: polit
 */

/*
 * �л� ����ü �����
 * �л���ȣ, �̸�, ����, ����
 * �� ����, ��� ����
 * 2�� �ݿ� 3�� �ִ�
 * 2���� ����ü �迭
 * �ݺ� ���, ����
 * 1�г� ���, ����
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
			printf("1�г� %d�� %d�� �л� �̸� : ", i+1, class[i][j].studentNumber);
			fflush(stdout);
			scanf("%s", class[i][j].name);

			printf("%s �л� ���� : ", class[i][j].name);
			fflush(stdout);
			scanf("%s", class[i][j].sex);

			printf("%s �л��� ���� ���� ���� ������ �Է��ϼ���\n ", class[i][j].name);
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
			printf("%d�� %d�� %s %s\n", i+1, class[i][j].studentNumber, class[i][j].name, class[i][j].sex);
			printf("������ : ");
			for(int k = 0; k < class_length; k++){
				printf("%d��", class[i][j].score + k);
			}
			printf("\n");
		}
		printf("====================================\n");

		printf("%d�� �� ���� : %d��\n", i+1, ban_sum[i]);
		printf("%d�� �� ���� : %d��\n", i+1, ban_avg[i]);
		printf("====================================\n");

	}

	printf("1�г� �� ���� : %d��\n 1�г� �� ��� ���� : \n", sum, avg);
	printf("====================================\n");

	return 0;
}
