#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SLNode;

void SListPrint(SLNode* phead);
void SListSize(SLNode* phead);

void SListPushBack(SLNode** pphead, SListDataType x);
void SListPopBack(SLNode** pphead);

void SListPushFront(SLNode* phead, SListDataType x);
void SListPopFront(SLNode* phead);
