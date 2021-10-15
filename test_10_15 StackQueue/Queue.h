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

//��ʼ������
void QueueInit(Queue* pq);
//���ٶ���
void QueueDestory(Queue* pq);

//��β��
void QueuePush(Queue* pq, QDataType x);
//��ͷ��
void QueuePop(Queue* pq);

//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);
//��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);
//�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
bool QueueEmpty(Queue* pq);