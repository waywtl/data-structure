#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int x = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = x;
	}
}

void ShellSort(int* a, int n)
{
	//���Ԥ����(gap > 1) + ֱ�Ӳ���( gap == 1)
	int gap = n;
	while (gap > 1)
	{
		//ʹgap���һ��һ���ܵ�1
		//gap /= 2;
		gap = gap / 3 + 1;
		//����һ����
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = x;
		}
	}
}

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	for (int end = n - 1; end > 0; --end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				exchange = 1;
				Swap(&a[i], &a[i + 1]);
			}
		}
		if (exchange == 0)
			break;
	}
}

//������ȡ��
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

//hoare��
int Partion1(int* a, int left, int right)
{

	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//����ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

//�ڿӷ�
int Partion2(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int key = a[left];
	int pivot = left;
	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//���滻,�ŵ���߿�
		a[pivot] = a[right];
		pivot = right;
		//����ߣ��Ҵ�
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//���滻���ŵ��ұ߿�
		a[pivot] = a[left];
		pivot = left;
	}
	a[pivot] = key;
	return pivot;
}

//ǰ��ָ�뷨 �������Ƽ�
int Partion3(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	int cur = left + 1;
	int prev = left;
	while (cur <= right)
	{
		//cur��С����С�Ļ������
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//С�����Ż�������Ҫ�ŵ������ٵģ�ֱ���ò������򣬼��ٵݹ����
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int keyi = Partion3(a, left, right);

		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//�������������е�Ԫ�ؿ�����ԭ��������
	for (int j = left; j <= right; ++j)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}