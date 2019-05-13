#pragma once
#include<iostream>
// c++를 기준으로 하여 코드를 작성

#define BUFFER 30
// 스택의 크기

char Stack[];									 // 스택을 저장할 배열
char write;										 // item값 입력을 위한 변수

int pop(char stack[], int top, int size);		 // 스택에서 나올시(pop)
int push(char stack[], int top, int size);		 // 스택에 자료 삽입시(push)
void empty();									 // 스택이 빌경우
void overflow();								 // 스택이 꽉찬경우
void output(char stack[], int top);				 // 출력 문