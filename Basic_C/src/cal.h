/*
 * cal.h
 *
 *  Created on: 2021. 6. 29.
 *      Author: polit
 */

#ifndef CAL_H_
#define CAL_H_

void add(int num1, int num2){
	int result = num1 + num2;
	printf("�� ���� ���� ��� : %d\n", result);
}

void sub(int num1, int num2){
	int result = num1 - num2;
	printf("�� ���� ���� ��� : %d\n", result);
}

void mul(int num1, int num2){
	int result = num1 * num2;
	printf("�� ���� ���� ��� : %d\n", result);
}

void div(int num1, int num2){
	double result = (double)num1 / num2;
	printf("�� ���� ������ ��� : %.2lf\n", result);
}


#endif /* CAL_H_ */
