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

void ListClear(ListNode* phead)
{
	assert(phead);

	//清理所有的数据节点，保留头节点，可以继续使用
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = phead;
	phead->prev = phead;
}

void ListDestory(ListNode** pphead)
{
	assert(*pphead);

	//销毁
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
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
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	//assert(phead);

	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);

	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;

	//phead->prev = tailPrev;
	//tailPrev->next = phead;
	//free(tail);
	//tail = NULL;

	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	//assert(phead);

	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);

	//phead->next = newnode;
	//newnode->prev = phead;

	//newnode->next = first;
	//first->prev = newnode;

	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);

	//ListNode* first = phead->next;
	//ListNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;

	ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//在pos前面插入x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;

	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	//assert(pos != phead);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}
