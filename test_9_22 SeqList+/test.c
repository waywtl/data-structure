#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPrint(&s);

	int pos = SeqListFind(&s, 5);
	if(pos != -1)
		SeqListErase(&s, pos);
	SeqListPrint(&s);
	//SeqListSort(&s);
	//SeqListPrint(&s);
	//SeqListBinaryFind(&s, 7);

	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPrint(&s);

	//SeqListPushFront(&s, -1);
	//SeqListPushFront(&s, -2);
	//SeqListPushFront(&s, -3);
	//SeqListPrint(&s);

	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPrint(&s);

	//SeqListInsert(&s, 4, 16);
	//SeqListPrint(&s);
	//SeqListInsert(&s, 6, 8);
	//SeqListPrint(&s);


	//SeqListErase(&s, 4);
	//SeqListPrint(&s);
	//SeqListErase(&s, 5);
	//SeqListPrint(&s);

	SeqListDestory(&s);
}

int main()
{
	TestSeqList1();
	return 0;
}