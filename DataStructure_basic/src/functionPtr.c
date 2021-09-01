/*
 * functionPtr.c
 *
 *  Created on: 2021. 7. 13.
 *      Author: polit
 */
#include <stdio.h>
#include <stdlib.h> //malloc, rand, atoi - 동적 / 랜덤 / 문자열 변환 함수들
#include <string.h> //strcpy, memcpy - 문자열 함수 / 메모리블럭 함수
#include <conio.h> // _getch, putch - MS기반 C비표준 함수
#include <time.h> // clock - 시간 날짜 함수
//#pragma warnig(disable:4996) // scanf() 등 전통 c 함수 버퍼 문제 해결 (비쥬얼스튜디오
//#pragma warning(disable:4477) // unsigned <-->signed 관련 warning (비쥬얼스튜디오


/*
 *	함후 포인터
 *	'함수이름'이 곧 '포인터'다 !
 */



void fnMinus(int a, int b)
{
	printf("빼기: %d - %d = %d\n", a, b, a - b);
}

void fnMul(int a, int b)
{
	printf("곱셈: %d * %d = %d\n", a, b, a * b);
}

void fnDiv(int a, int b)
{
	printf("나눗셈: %d / %d = %d\n", a, b, a / b);
}

void fnPlus(int a, int b){
	printf("덧셈 : %d + %d = %d\n", a, b, a + b);
}




void doAction(int a, int b, void(*fnOp)(int, int)){ //함수포인터를 사용해 함수를 매개변수로 넘겨줄 수 있는지
	fnOp(a, b);
}

typedef void fnActions(int, int); // 함수포인터 타입 정의하고 51~53처럼 써야됨

void doAction2(int a, int b, fnActions * fnOp){ // 똑같음 위에꺼랑 (45~ 47번째 줄)
	fnOp(a, b);
}



int main(void){

	{
		printf("=======함수포인터 설명======\n");

		fnPlus(10, 20);

		printf("fnPlus -> %p\n", fnPlus); // 주소값나옴

		//함수이름 -> 함수포인터
		// 함수포인터는 '참조' 가 곧 '호출' 동작이다.
		// 참조연산자 * 사용하여 호출

		(*fnPlus)(30, 40);

		// 함수 포인터 타입 변수 선언 가능
		// int *p;   <-- int 에 대한 포인터
		// void 리턴하고 (int, int) 매개변수 받는 함수에 대한 함수 포인터는 아래에

		void(*fnOp)(int, int); //fnOp라는 '함수포인터 변수 선언' !!

		// 포인터 변수 <- 대입 가능하다는 뜻 !

		fnOp = fnPlus;

		//이제 fnOp는 fnPlus함수처럼 사용 가능, 참조연산자도 사용 가능

		(*fnOp)(40, 60);
		fnOp(45, 70); //똑같이 나옴

	}

	printf("\n");

	{
		printf("=======함수포인터를 함수포인터배열에 넣어서 쓰기======\n");
		// 함수포인터의 이점.
		// '동작'을 나중에 연결 가능 (late-binding)

		int op;
		printf("\n동작번호를 입력하세요(0:+ 1:- 2:* 3:/): ");
		fflush(stdout);
		scanf("%d", &op);

		printf("\n======if-else if로 함수출력하기======\n");

		int a = 30, b = 10;
		int i = 0;
		for (i = 0; i < 5; i++){
			if(op == 0)	fnPlus(a, b); 		 // <-- 이 라인의 실행코드는 fnPlus를 호출하도록 컴파일된다.
			else if(op == 1) fnMinus(a, b);  // <-- 이 라인의 실행코드는 fnMinus를 호출하도록 컴파일된다.
			else if(op == 2) fnMul(a, b);
			else if(op == 3) fnDiv(a, b);

		}
		// ↑ 이미 컴파일할때 코드상에 명시된 '특정'함수가
		// 실행되도록 바인딩 된다.  --> Early Binding 이라 함
		// 매 순환문마다 조건문을 통해 고정된 함수 호출을 호출해야 하니, 조건분기문(if-else if) 로드가 큼
		printf("\n");
		printf("=======함수포인터와 함수포인터배열을 이용해서 출력하기======\n");
		// 반면 !
		// 함수포인터 선언
		void(*fnAction)(int, int); //fnAction라는 '함수포인터 변수 선언'


		// 함수포인터의 배열(함수들만 모아놓은 배열)
		void(*fnOpArr[])(int, int) = {fnPlus, fnMinus, fnMul, fnDiv};
		//fnArr[0] => fnPlus ....

		fnAction = fnOpArr[op]; //함수포인터에 함수포인터배열을 넘겨서 사용한다.

		for(i = 0; i < 5; i++){
			fnAction(a, b);
		}
		// 그냥 fnAction 을 수행.. 그런데 컴파일 시점에선 무엇을 실행한진 모른다 (즉 바인딩이 되어 있지 않다)
		// 실행 해야 나중에 동작이 결정된다.   late-binding

		// 장점: 조건문에 의한 로드가 적다.
		// 성능향상!!

	}

	printf("\n");

	{
		printf("=======함수포인터를 이용해 함수를 매개변수로 받아서 출력하기======\n");
		// 함수 포인터도 포인터다!
		// 매개변수로 넘겨줄수도, 리턴값으로 받을수도
		// 배열 원소가 될수도 있다!!


		doAction(333, 444, fnPlus);
		doAction(333, 444, fnMinus);
		doAction(333, 444, fnMul);
		doAction(333, 444, fnDiv);
	}

	printf("\n");

	{
		// 함수 포인터도 포인터다!
		// 매개변수로 넘겨줄수도, 리턴값으로 받을수도
		// 배열 원소가 될수도 있다!!


		doAction2(333, 444, fnPlus);
		doAction2(333, 444, fnMinus);
		doAction2(333, 444, fnMul);
		doAction2(333, 444, fnDiv);
	}


	return 0;
}

