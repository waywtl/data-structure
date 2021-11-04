#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void AdjustUp(int* a, int child);
void AdjustDown(int* a, int n, int parent);

void Swap(HPDataType* px, HPDataType* py);
void HeapInit(HP* hp);
void HeapDestroy(HP* hp);
void HeapPrint(HP* hp);

void HeapPush(HP* hp, HPDataType x);
void HeapPop(HP* hp);

HPDataType HeapTop(HP* hp);
bool HeapEmpty(HP* hp);