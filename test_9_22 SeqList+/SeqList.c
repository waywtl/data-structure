#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	/*s.size = 0;
	s.a = NULL;
	s.capacity = 0;*/

	ps->a = malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps)
{
	//���������Ҫ����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}
//β��βɾ
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	ps->size--;
}

//ͷ��ͷɾ
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps)
{
	assert(ps);

	int start = 0;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start+1];
		start++;
	}
	ps->size--;
}

//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);

	SeqListCheckCapacity(ps);
	
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

//����
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//����
void SeqListSort(SL* ps)
{
	assert(ps);

	int i, j;
	for (i = 0; i < ps->size; ++i)
	{
		for (j = 0; j < ps->size - i - 1; ++j)
		{
			if (ps->a[j] > ps->a[j + 1])
			{
				int tmp = ps->a[j];
				ps->a[j] = ps->a[j + 1];
				ps->a[j + 1] = tmp;
			}
		}
	}
}

//���ֲ���
int SeqListBinaryFind(SL* ps, SLDataType x)
{
	assert(ps);

	int left = 0;
	int right = ps->size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (ps->a[mid] != x)
		{
			if (ps->a[mid] < x)
				left = mid;
			else
				right = mid;
		}
		else
		{
			return mid;
			break;
		}
	}
	return -1;
}