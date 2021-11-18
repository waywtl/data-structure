#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* a, int n);

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);

void SelectSort(int* a, int n);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);
void QuickSort(int* a, int left, int right);

void MergeSort(int* a, int n);