/*
 * hangle(task).c
 *
 *  Created on: 2021. 7. 7.
 *      Author: polit
 */

//1024 -> �ϰ��̻� ��µǰ� �����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int idx = 0;
	int input = 0;
	int size[] = {0, };
	int temp = 0;
	char arr[10][5] = {"0","1","2","3","4","5","6","7","8","9"};
	char arr2[10][5] ={"��","��","��","��","��","��","��","ĥ","��","��"};


	printf("���ڸ� �Է��ϼ���\n");
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


 //������� �� �� //


void changToHangle(char*);

int main(void){
	char arNum[10] = ""; //������ ���ڿ��迭 ����� {""} �̰žƴ�
	printf("�ѱ۷� �����Ͻ� ������ �Է��ϼ���\n");
	fflush(stdout);
	scanf("%s", arNum);

	changeToHangle(arNum);

	return 0;
}


void changeToHangle(char* arNum){ //������ �迭�̱� ������ ������ �迭�� ����
	// ����, ���ڿ� 1024 / �ƽ�Ű�ڵ忡�� 0 = 48 / 2���� ���ڿ� ���� ��
	char arHangle[10][5] = {"��", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��"};
	//arHangle[0]- 48;  �ƽ�Ű�ڵ�� "1" = 49 ���� 48�� ���ָ� 1�̵�

	for(int i = 0; i <strlen(arNum); i++){
		printf("%s", arHangle[arNum[i]-48]);
	}
	printf("\n");
}
