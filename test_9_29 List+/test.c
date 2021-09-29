#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void TestList1()
{
	/*ListNode* phead = NULL;
	ListInit(&phead);*/

	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	ListPushFront(phead, -1);
	ListPushFront(phead, -2);
	ListPushFront(phead, -3);
	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListDestory(&phead);
}

void TestList2()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 5);
	ListPrint(phead);

	ListNode* pos = ListFind(phead, 5);
	ListInsert(pos, 4);
	ListInsert(pos, 40);
	ListPrint(phead);

	ListErase(pos->prev);
	ListPrint(phead);

	ListDestory(&phead);
}

int main()
{
	TestList1();
	//TestList2();
	return 0;
}