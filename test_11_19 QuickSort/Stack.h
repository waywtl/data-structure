#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ��ջ
void StackInit(ST* ps);
//����ջ
void StackDestroy(ST* ps);

//ջ������ɾ������
//��ջ
void StackPush(ST* ps,STDataType x);
//��ջ
void StackPop(ST* ps);

//��ȡջ��Ԫ��
STDataType StackTop(ST* ps);

//��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps);

//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
bool StackEmpty(ST* ps);