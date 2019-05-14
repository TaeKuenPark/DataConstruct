#include"Header.h"

int main(void)
{
	char str[MAX];
	
	int n = sizeof(str);
					// 큐의 크기
	int front;		// 큐의 왼쪽
	int rear ;		// 큐의 오른쪽
	int sel;		// 분기문을 위한 변수

	rear = 0;		// 큐의 삽입을 위한 rear
	front = 0;		// 큐의 삭제를 위한 front

	while (1)
	{
		printf("=================================\n");
		printf("    큐, 데큐 값 설정해수십시오.  \n");
		printf("  1. (큐) 삽입    2. (큐) 삭제   \n");
		printf("  3. 출력         4. 종료        \n");
		printf("=================================\n");
		printf(">>");
		scanf("%d", &sel);
		printf("\n");
												// 명령을 위한 메뉴
												// 출력
		switch (sel)
		{
		case 1:											// 선택 분기문
			rear = insert_Queue(str, n, rear);			// 1 : 큐를 삽입한다
			break;
		case 2:
			front = delete_Queue(str, n, front, rear);	// 2: 큐를 삭제한다.
			break;
		case 3:
			outPut(str,front, rear);					// 3. 현재 배열의상태
			break;										// (큐의 상태출력)
		case 4:
			return 0;									// 4 :  프로그램 종료
		default:
			printf("잘못된 입력");						// 이외의 입력(default)
			break;	
		}
	}


}
													// 큐의 삽입 함수
int insert_Queue(char str[], int size, int rear)
{
	char item;										// 삽입할 문자형 데이터를 받는다.

	if (rear == size)								// 배열의 최대크기(size)와 rear가 만나면 오류발생
	{
		puts("==== [오류] rear가맨끝에 도달 ===");	// 배열의 첫 요소로 돌아가고
		puts("=     맨 첫 요소로 돌아가도    ==");	// 만일, 배열의 첫 요소에 값이 있는경우
		puts("=       좋으시겠습니까?(y/n)   ==\n");// front의 삭제가 이루워지지 않은 상황이므로,
													// overflow발생
		scanf(" %c", &sel);
		if (sel == 'y')
			rear = 0;
		else {
			overflow();
			return rear;
		}
	}
	
	if (rear > size-1 && str[0] !=NULL)
	{
		overflow();
	} else
	{
		if (rear == size)
			rear = 0;
		printf("====== %d번요소 =====\n", rear);
		printf("[요소 입력] ");
		scanf(" %c", &item);	
		

		printf("\n");									// 요소를 받는다
		str[rear] = item;
		rear++;
		printf("%c", str[rear]);
	}
	return rear;
}
int delete_Queue(char str[], int size, int front, int rear)
{														// 큐의 삭제부분
	if (n > size-1)										// 큐의 삭제는 큐의 끝까지 삭제를 진행하지만,
	{
		char sel;										// front와 rear의 위치가 같으면,
		printf("%d", size);								// 동일한 위치에서 움직여, 앞뒤로 모두 비어있는 상태
		printf("큐의 끝에 도달하였습니다.\n");			// empty오류가 발생한다.
		printf("큐의 맨 처음으로 돌아가 \n");
		printf("삭제 하시겠습니까?(y/n)");
		scanf(" %c", &sel);
		if (sel == 'y') {
			n = 0;
			printf("===== %d번요소 삭제 ====\n", front);
			printf("<str[%d] =  %c>  --> X\n", front, str[front]);
			str[front] = NULL;
			front++;
		}
		else if (sel == 'y' && front == rear)
		{
			empty();
		}
		
	}
	else {
		if (rear == front)
		{
			empty();
		}
		else {
			printf("===== %d번요소 삭제 ====\n", front);				// 삭제된 결과 출력부분
			printf("<str[%d] =  %c>  --> X\n", front, str[front]);
			str[front] = NULL;
			front++;
		}
		
	}
	
	return front;
}

void outPut(char str[],int front, int rear)							// 결과문 출력
{
	int i;
	printf("=================================\n");
	printf("=             출력              =\n");
	printf("=================================\n");

	if (rear == front)
	{
		printf("=             EMPTY             =\n");				// 큐가 빈 경우 EMPTY문장 출력
		printf("=================================\n");
	}
	else {
		for (i = front; i < rear; i++)
		{
			printf("str[%d] = %c \n", i, str[i]);
		}
	}
	
	printf("=================================\n");
}


void empty()													// 오류처리 함수
{
	printf("[오류] 현재 큐가 빈상태입니다.\n");					// 큐가 빈경우 삭제시
}
void overflow()													// 오버 플로우
{
	printf("[오류] overflow(큐가 꽉차거나)\n");
	puts("첫번째 배열에 요소가 존재합니다.");
}