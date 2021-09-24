#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestSList1()
{
	//SLNode * phead = NULL;
	SLNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList);
	SListPrint(pList);

	SListPushFront(&pList, 5);
	SListPushFront(&pList, 6);
	SListPushFront(&pList, 7);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);

}

void TestSList2()
{
	SLNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SLNode* pos = SListFind(pList, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(pList);

	SListInsertAfter(pos, 31);
	SListPrint(pList);

	SListEraseAfter(pos);
	SListPrint(pList);

}

int main()
{
	//TestSList1();
	TestSList2();
	return 0;
}