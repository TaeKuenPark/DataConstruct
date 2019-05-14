#pragma once
#define _CRT_SECURE_NO_WARNINGS
// 큐(Queue)와 데큐(Dequeue)구현

#include<stdio.h>
#define MAX 4
char str[];
int n;
int front,rear;
char item,sel;

int insert_Queue(char str[], int size, int rear);
int delete_Queue(char str[], int size, int front, int rear);



void outPut(char str[], int front, int rear);
void empty();
void overflow();