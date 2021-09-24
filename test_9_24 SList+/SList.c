#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SLNode* BuySListNode(SListDataType x)
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
	{
		printf("ÉêÇë½ÚµãÊ§°Ü\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLNode** pphead, SListDataType x)
{
	SLNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//ÕÒÎ²
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

void SListPopBack(SLNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* prev = NULL;
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPushFront(SLNode** pphead, SListDataType x)
{
	SLNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

void SListPopFront(SLNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SLNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

SLNode* SListFind(SLNode* phead, SListDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLNode* pos, SListDataType x)
{
	assert(pos);

	SLNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

void SListEraseAfter(SLNode* pos)
{
	assert(pos);

	if (pos->next)
	{
		SLNode* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}