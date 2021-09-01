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
	printf("µÎ ¼öÀÇ µ¡¼À °á°ú : %d\n", result);
}

void sub(int num1, int num2){
	int result = num1 - num2;
	printf("µÎ ¼öÀÇ »¬¼À °á°ú : %d\n", result);
}

void mul(int num1, int num2){
	int result = num1 * num2;
	printf("µÎ ¼öÀÇ °ö¼À °á°ú : %d\n", result);
}

void div(int num1, int num2){
	double result = (double)num1 / num2;
	printf("µÎ ¼öÀÇ ³ª´°¼À °á°ú : %.2lf\n", result);
}


#endif /* CAL_H_ */
