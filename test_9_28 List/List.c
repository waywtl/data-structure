#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

/*void ListInit(ListNode** pphead)
{
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}*/

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("%d\n", cur->data);
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;

	phead->prev = tailPrev;
	tailPrev->next = phead;
	free(tail);
	tail = NULL;
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}