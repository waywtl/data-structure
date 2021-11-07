#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void TestHeap()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	HP hp;
	HeapCreate(&hp, a, sizeof(a)/sizeof(a[0]));

	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

//升序
void HeapSort(int* a, int n)
{
	//方法1：
	/*for (int i = 0; i < n; ++i)
	{
		AdjustUp(a, i);
	}*/

	//方法2：
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//依次选数，调堆
	for (int end = n - 1; end > 0; --end)
	{
		//每次把大堆堆顶的数调到后面,倒着调
		Swap(&a[0], &a[end]);
		//为保持大堆，把换上来的数向下调整
		AdjustDown(a, end, 0);
	}
}

void PrintTopk(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	HeapCreate(&hp, a, n);

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
	int n = 1000000;
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[5547] = 1000000 + 3;
	a[482] = 1000000 + 4;
	a[69] = 1000000 + 5;
	a[3291] = 1000000 + 6;
	a[1485] = 1000000 + 7;
	a[7500] = 1000000 + 8;
	a[2689] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopk(a, n, 10);
}

int main()
{
	TestHeap();
	//TestTopk();
	return 0;
}