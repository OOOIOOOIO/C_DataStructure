/*
 * cal.c
 *
 *  Created on: 2021. 6. 29.
 *      Author: polit
 */
#include <stdio.h>
#include <string.h>
#include "cal.h"

int main(void){
	int a = 0, b = 0;
	char c[3] = {"", };



	while(1){
		printf("�� ���� �Է��ϼ���.\n");
		fflush(stdout);
		scanf("%d %c %d",&a, c, &b);

		if(!strcmp(c, "+")){
			add(a, b);
			break;
		}

		else if(!strcmp(c, "-")){
			sub(a, b);
			break;
		}

		else if(!strcmp(c, "*")){
			mul(a, b);
			break;
		}

		else if(!strcmp(c, "/")){
			if(b > 0){
				div(a, b);
				break;
			}
			else{
				printf("0���� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n\n");
			}

		}

	}

return 0;
}

