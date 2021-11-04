#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void TestHeap()
{
	int a[] = { 70,56,30,25,15,10,75 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void PrintTopk(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < k; i++)
	{
		HeapPush(&hp, a[i]);
	}

	for (int i = k; i < n; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			hp.a[0] = a[i];
			AdjustDown(hp.a, hp.size, 0);
		}
	}
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void TestTopk()
{
	int a[] = {5,8,1,7,4,6,9,2,3};
	int n = sizeof(a) / sizeof(a[0]);
	PrintTopk(a, n, 5);
}

int main()
{
	//TestHeap();
	TestTopk();
	return 0;
}