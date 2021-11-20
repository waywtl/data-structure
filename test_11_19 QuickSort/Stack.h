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

//初始化栈
void StackInit(ST* ps);
//销毁栈
void StackDestroy(ST* ps);

//栈顶插入删除数据
//入栈
void StackPush(ST* ps,STDataType x);
//出栈
void StackPop(ST* ps);

//获取栈顶元素
STDataType StackTop(ST* ps);

//获取栈中有效元素个数
int StackSize(ST* ps);

//检测栈是否为空，如果为空返回非零结果，如果不为空返回0
bool StackEmpty(ST* ps);