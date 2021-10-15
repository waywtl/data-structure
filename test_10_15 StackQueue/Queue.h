#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//初始化队列
void QueueInit(Queue* pq);
//销毁队列
void QueueDestory(Queue* pq);

//队尾入
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);

//获取队列头部元素
QDataType QueueFront(Queue* pq);
//获取队列队尾元素
QDataType QueueBack(Queue* pq);

//获取队列中有效元素个数
int QueueSize(Queue* pq);
//检测队列是否为空，如果为空返回非零结果，如果非空返回0
bool QueueEmpty(Queue* pq);