/*
 * CountingSortMain.c
 *
 *  Created on: 2021. 8. 9.
 *      Author: polit
 */
#include <stdio.h>

// �ܼ� Counting Sort
#define size 10001

int main(){

int N, num;
int count[size] = {0, };
scanf("%d", &N);

for(int i = 0; i < N; i++){
    scanf("%d", &num);
    count[num]++;
}

for(int i = 0; i < size; i++){
    if(count[i] == 0) continue;

    for(int j = 0; j < count[i]; j++){
        printf("%d\n", i);
    }
}

    return 0;
}
//----------------------------------------------------------------------

// �������� �̿��� Counting Sort
#define MAX_SIZE 1001
#define MAX_NUM 10001

int main(){
    int N, A[MAX_SIZE], B[MAX_SIZE], count[MAX_NUM], countSum[MAX_NUM];

    //������ ���� N�� MAX_SIZE���Ͽ����մϴ�.
    scanf("%d", &N);

    //count�迭�� ��� 0���� �ʱ�ȭ
    for(int i = 0; i<= N ; i++)
        count[i] = 0;

    //���� A�� �ԷµǴ� ���� MAX_NUM ���Ͽ����մϴ�.
    for(int i =1 ; i<= N ; i++){
        scanf("%d", &A[i]);

        //���� ���� Ƚ�� ����
        count[A[i]]++;
    }

    //������ ����
    countSum[0] = count[0];
    for(int i = 1 ; i<= MAX_NUM ; i++)
        countSum[i] = countSum[i-1]+count[i];

    //�ڿ��� ���� ���� A ��ȸ�Ѵ�.
    for(int i = N ; i >= 1; i--){
        B[countSum[A[i]]] = A[i];
        countSum[A[i]]--;
    }

    //���� A�� ������ ����� ���� B�� ����Ѵ�.
    for(int i =1 ; i<= N ; i++)
        printf("%d ", B[i]);
}
