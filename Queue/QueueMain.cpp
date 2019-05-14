#include"Header.h"

int main(void)
{
	char str[MAX];
	
	int n = sizeof(str);
					// ť�� ũ��
	int front;		// ť�� ����
	int rear ;		// ť�� ������
	int sel;		// �б⹮�� ���� ����

	rear = 0;		// ť�� ������ ���� rear
	front = 0;		// ť�� ������ ���� front

	while (1)
	{
		printf("=================================\n");
		printf("    ť, ��ť �� �����ؼ��ʽÿ�.  \n");
		printf("  1. (ť) ����    2. (ť) ����   \n");
		printf("  3. ���         4. ����        \n");
		printf("=================================\n");
		printf(">>");
		scanf("%d", &sel);
		printf("\n");
												// ����� ���� �޴�
												// ���
		switch (sel)
		{
		case 1:											// ���� �б⹮
			rear = insert_Queue(str, n, rear);			// 1 : ť�� �����Ѵ�
			break;
		case 2:
			front = delete_Queue(str, n, front, rear);	// 2: ť�� �����Ѵ�.
			break;
		case 3:
			outPut(str,front, rear);					// 3. ���� �迭�ǻ���
			break;										// (ť�� �������)
		case 4:
			return 0;									// 4 :  ���α׷� ����
		default:
			printf("�߸��� �Է�");						// �̿��� �Է�(default)
			break;	
		}
	}


}
													// ť�� ���� �Լ�
int insert_Queue(char str[], int size, int rear)
{
	char item;										// ������ ������ �����͸� �޴´�.

	if (rear == size)								// �迭�� �ִ�ũ��(size)�� rear�� ������ �����߻�
	{
		puts("==== [����] rear���ǳ��� ���� ===");	// �迭�� ù ��ҷ� ���ư���
		puts("=     �� ù ��ҷ� ���ư���    ==");	// ����, �迭�� ù ��ҿ� ���� �ִ°��
		puts("=       �����ðڽ��ϱ�?(y/n)   ==\n");// front�� ������ �̷������ ���� ��Ȳ�̹Ƿ�,
													// overflow�߻�
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
		printf("====== %d����� =====\n", rear);
		printf("[��� �Է�] ");
		scanf(" %c", &item);	
		

		printf("\n");									// ��Ҹ� �޴´�
		str[rear] = item;
		rear++;
		printf("%c", str[rear]);
	}
	return rear;
}
int delete_Queue(char str[], int size, int front, int rear)
{														// ť�� �����κ�
	if (n > size-1)										// ť�� ������ ť�� ������ ������ ����������,
	{
		char sel;										// front�� rear�� ��ġ�� ������,
		printf("%d", size);								// ������ ��ġ���� ������, �յڷ� ��� ����ִ� ����
		printf("ť�� ���� �����Ͽ����ϴ�.\n");			// empty������ �߻��Ѵ�.
		printf("ť�� �� ó������ ���ư� \n");
		printf("���� �Ͻðڽ��ϱ�?(y/n)");
		scanf(" %c", &sel);
		if (sel == 'y') {
			n = 0;
			printf("===== %d����� ���� ====\n", front);
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
			printf("===== %d����� ���� ====\n", front);				// ������ ��� ��ºκ�
			printf("<str[%d] =  %c>  --> X\n", front, str[front]);
			str[front] = NULL;
			front++;
		}
		
	}
	
	return front;
}

void outPut(char str[],int front, int rear)							// ����� ���
{
	int i;
	printf("=================================\n");
	printf("=             ���              =\n");
	printf("=================================\n");

	if (rear == front)
	{
		printf("=             EMPTY             =\n");				// ť�� �� ��� EMPTY���� ���
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


void empty()													// ����ó�� �Լ�
{
	printf("[����] ���� ť�� ������Դϴ�.\n");					// ť�� ���� ������
}
void overflow()													// ���� �÷ο�
{
	printf("[����] overflow(ť�� �����ų�)\n");
	puts("ù��° �迭�� ��Ұ� �����մϴ�.");
}