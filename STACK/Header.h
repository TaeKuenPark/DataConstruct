#pragma once
#include<iostream>
// c++�� �������� �Ͽ� �ڵ带 �ۼ�

#define BUFFER 30
// ������ ũ��

char Stack[];									 // ������ ������ �迭
char write;										 // item�� �Է��� ���� ����

int pop(char stack[], int top, int size);		 // ���ÿ��� ���ý�(pop)
int push(char stack[], int top, int size);		 // ���ÿ� �ڷ� ���Խ�(push)
void empty();									 // ������ �����
void overflow();								 // ������ �������
void output(char stack[], int top);				 // ��� ��