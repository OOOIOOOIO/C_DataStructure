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

// 2���� �迭 ����

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
				printf("%0 2d\n", arrData[i][j]); // 2�ڸ� �� ������
			}
		}

}

// 2���� �迭 ���� : 1��, 2�� �� ������ 3ȣ�� �ִ�.

int main(void){
	int arrDong[2][3] = {0, };
	int cLength = sizeof(arrDong[0]) / sizeof(int);
	int rLength = sizeof(arrDong) / cLength / sizeof(int);
	int total = 0;
	int sum[2] = {0, };

	for(int i = 0; i < rLength; i++){
		for(int j = 0; j < cLength; j++){
			printf("%d�� %dȣ ������ �Է��ϼ���(���� : ����)", i+1, j+1);
			fflush(stdout);
			scanf("%d", *(arrDong+i)+j);

			total += arrDong[i][j];
			sum[i] += arrDong[i][j];
		}
	}

	for(int i = 0; i <rLength; i++){
		printf("%d�� �ѿ��� : %d����\n", i+1, sum[i]);
		printf("%d�� ��տ��� : %.1lf����\n", i+1, (double)sum[i]/cLength);

	}
	printf("������ ����Ʈ �� ���� : %d ����", total);
	printf("������ ����Ʈ ��� ���� : %.1lf ����",(double)total/(cLength*rLength));

	return 0;
}
