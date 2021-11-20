#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int GetMidIndex(int* a, int left, int right)
{
	//int mid = (left + right) / 2;
	int mid = left + ((right - left) >> 1);
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
}

int Partion(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	int cur = left + 1;
	int prev = left;
	while (cur <= right)
	{
		//cur找小，把小的换到左边
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

/*void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//小区间优化，让需要排的数很少的，直接用插入排序，减少递归次数
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int keyi = Partion(a, left, right);

		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}*/

//QuickSort的非递归写法 —— 把区间入栈
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);

		//排这个区间
		int keyi = Partion(a, begin, end);
		//把左右区间入栈
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}

int main()
{
	int a[] = { 6,10,7,9,3,4,8,2,1,5 };
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}