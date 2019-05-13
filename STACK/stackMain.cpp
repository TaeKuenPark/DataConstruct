#include"Header.h"
#include<string>
int main(void)
{
	char Stack[BUFFER];

	int top;					// ������ ����
	int n = sizeof(Stack);
	// ������ ũ�⸦ ����
	int sel;
	top = -1;					// 0�� �迭 ���� �����ϹǷ�, -1 ���� ����
	
	char write;
	//�� item�� �Է��ϱ� ���� ����
	while (1) {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "�����Ͻÿ�.(1. push 2. pop 3. output 4.����)" << "\n";
		std::cout << "\n";
		std::cin >> sel;
		switch (sel)
		{
		case 1: 
			top = push(Stack,top, n);	
											// PUSH : ���ÿ� ���� �ִ´�.
			break;

		case 2: 
			top = pop(Stack, top, n);
			break;
											// POP : ������ ���� ����
		case 3:
			output(Stack, top);
			break;							// ��¹�

		case 4: 
			return 0;						// ����

		default:
			
			std::cout << "�߸� �Է��ϼ̽��ϴ�\n";
			std::cout <<"�ùٸ� ��ȣ���ٽ��Է��� �ּ���\n";
			break;
		}
		std::cout << "[top height]" << top+1 << std::endl;
											// ������ ������ ���̸� ����.
	}										//  �ִ���̴� 30

}

int push(char stack[], int top, int size)		// Ǫ�� �κ�
{
	char write;									// ������ �Է� ����

	if (top >= (size - 1))						// top�� ���̰� size(�ְ����)���� ũ�� �����÷� �߻�
		overflow();
	else {
		top++;									// ���� ���ð� ����
		std::cout << top;
		std::cout << "[item �Է�] ";			// ���� �ش� �迭�� �Է��� ����
		std::cin >> write;

		
		std::cout << "push\n";
		std::cout << top << std::endl;
		stack[top] = write;	
	}
	
	return top;									// ������  ���̸� �����ϱ� ���� ���
}
int pop(char stack[], int top, int size)
{													// pop�κ�
	
	if (top >-1)									// -1���� ���̰� ������ ���̻� �� ��Ұ� ����
	{												// �迭�� 0�� ���� �����ϹǷ� -1

			std::cout << "pop -> " << stack[top] << std::endl;
			stack[top] = NULL;						// NULL���� ������ �Ѵ�.
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
	std::cout << "\\\\\\\\ ���� ������ ���� \\\\\\\\\\ \n";
	std::cout << "--------------------------------------\n";
	if (top == -1)
	{
		std::cout << "           ��  ��                    " << std::endl;
	}			// ����� �Ʒ��� ������ ����Ѵ�.
	else {
		for (i = 0; i < top + 1; i++)
		{

			std::cout << "Stack[" << i << "] = " << output[i] << std::endl;


		}
	}
	
		std::cout << "--------------------------------------\n";
}
void empty()						// ���� ó����
{
	std::cout << "[����] StackEmpty!(������ ������ϴ�)" << std::endl;
	std::cout << "�ڷḦ �־��ֽʽÿ�.\n";
}
void overflow()
{
	std::cout << "[����] StackOverFlow(������ ���ƽ��ϴ�)" << std::endl;
	std::cout << "pop�� ���ֽʽÿ�.\n";
	
}