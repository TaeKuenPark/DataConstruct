#pragma once
#define _CRT_SECURE_NO_WARNINGS                       // scanf사용시 오류를 해결하기 위한 문장
// 큐(queue)구현
// Dequeue(데크)의 경우 오른쪽 왼쪽, 포인터 변수를 rear, front에 따로 준뒤 함수를 이용해 만들면 됨

#include<stdio.h>
#define MAX 4
char str[];                                                     // 큐의 자료를 저장하기 위한 배열
int n;                                                          // 크기 저장 변수
int front,rear;                                                 // front, rear 값 변수
char item,sel;                                                  // 문자형 데이터 처리변수

int insert_Queue(char str[], int size, int rear);               // 큐 삽입 기능
int delete_Queue(char str[], int size, int front, int rear);    // 큐 삭제 기능

void outPut(char str[], int front, int rear);                   // 출력 기능

                                                                // 오류처리
void empty();                                                   // 삭제시 큐가 빈경우
void overflow();                                                // 삽입시 큐가 꽉찬경우(overflow)
