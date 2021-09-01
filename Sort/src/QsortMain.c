/*
 * Qsort.c
 *
 *  Created on: 2021. 8. 9.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    if( *(int *)a > *(int *)b)
        return 1;

    else if( *(int *)a < *(int *)b)
        return -1;
    else
    return 0;
}

int main(){
    int N;
    int data[1000001] ={0, };

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    scanf("%d", &data[i]);

    qsort(data, N, sizeof(int), compare);

    for(int i = 0; i < N; i++)
        printf("%d\n", data[i]);

    return 0;
}

