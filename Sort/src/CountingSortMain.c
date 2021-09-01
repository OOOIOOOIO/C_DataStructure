/*
 * CountingSortMain.c
 *
 *  Created on: 2021. 8. 9.
 *      Author: polit
 */
#include <stdio.h>

// 단순 Counting Sort
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

// 누적합을 이용한 Counting Sort
#define MAX_SIZE 1001
#define MAX_NUM 10001

int main(){
    int N, A[MAX_SIZE], B[MAX_SIZE], count[MAX_NUM], countSum[MAX_NUM];

    //수열의 길이 N은 MAX_SIZE이하여야합니다.
    scanf("%d", &N);

    //count배열을 모두 0으로 초기화
    for(int i = 0; i<= N ; i++)
        count[i] = 0;

    //수열 A에 입력되는 수는 MAX_NUM 이하여야합니다.
    for(int i =1 ; i<= N ; i++){
        scanf("%d", &A[i]);

        //숫자 등장 횟수 세기
        count[A[i]]++;
    }

    //누적합 구성
    countSum[0] = count[0];
    for(int i = 1 ; i<= MAX_NUM ; i++)
        countSum[i] = countSum[i-1]+count[i];

    //뒤에서 부터 수열 A 순회한다.
    for(int i = N ; i >= 1; i--){
        B[countSum[A[i]]] = A[i];
        countSum[A[i]]--;
    }

    //수열 A를 정렬한 결과인 수열 B를 출력한다.
    for(int i =1 ; i<= N ; i++)
        printf("%d ", B[i]);
}
