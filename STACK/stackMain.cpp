#include"Header.h"
#include<string>
int main(void)
{
	char Stack[BUFFER];

	int top;					// 스택의 높이
	int n = sizeof(Stack);
	// 스택의 크기를 본다
	int sel;
	top = -1;					// 0번 배열 부터 저장하므로, -1 부터 시작
	
	char write;
	//쓸 item을 입력하기 위한 변수
	while (1) {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "선택하시오.(1. push 2. pop 3. output 4.종료)" << "\n";
		std::cout << "\n";
		std::cin >> sel;
		switch (sel)
		{
		case 1: 
			top = push(Stack,top, n);	
											// PUSH : 스택에 값을 넣는다.
			break;

		case 2: 
			top = pop(Stack, top, n);
			break;
											// POP : 스택의 값을 뺀다
		case 3:
			output(Stack, top);
			break;							// 출력문

		case 4: 
			return 0;						// 종료

		default:
			
			std::cout << "잘못 입력하셨습니다\n";
			std::cout <<"올바른 번호를다시입력해 주세요\n";
			break;
		}
		std::cout << "[top height]" << top+1 << std::endl;
											// 현재의 스택의 높이를 본다.
	}										//  최대높이는 30

}

int push(char stack[], int top, int size)		// 푸시 부분
{
	char write;									// 아이템 입력 변수

	if (top >= (size - 1))						// top의 높이가 size(최고높이)보다 크면 오버플로 발생
		overflow();
	else {
		top++;									// 먼저 스택값 증가
		std::cout << top;
		std::cout << "[item 입력] ";			// 값을 해당 배열에 입력후 저장
		std::cin >> write;

		
		std::cout << "push\n";
		std::cout << top << std::endl;
		stack[top] = write;	
	}
	
	return top;									// 증가한  높이를 저장하기 위해 출력
}
int pop(char stack[], int top, int size)
{													// pop부분
	
	if (top >-1)									// -1보다 높이가 작으면 더이상 뺄 요소가 없음
	{												// 배열은 0번 부터 저장하므로 -1

			std::cout << "pop -> " << stack[top] << std::endl;
			stack[top] = NULL;						// NULL값을 재지정 한다.
			top--;

	}
	else
	{
		
		empty();
	}
		
	return top;
}

void output(char output[], int top)
{
	int i;
	std::cout << "\\\\\\\\ 현재 스택의 상태 \\\\\\\\\\ \n";
	std::cout << "--------------------------------------\n";
	if (top == -1)
	{
		std::cout << "           공  백                    " << std::endl;
	}			// 공백시 아래의 문장을 출력한다.
	else {
		for (i = 0; i < top + 1; i++)
		{

			std::cout << "Stack[" << i << "] = " << output[i] << std::endl;


		}
	}
	
		std::cout << "--------------------------------------\n";
}
void empty()						// 에러 처리문
{
	std::cout << "[오류] StackEmpty!(스택이 비었습니다)" << std::endl;
	std::cout << "자료를 넣어주십시오.\n";
}
void overflow()
{
	std::cout << "[오류] StackOverFlow(스택이 넘쳤습니다)" << std::endl;
	std::cout << "pop을 해주십시오.\n";
	
}