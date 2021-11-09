#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//前,中,后序遍历
void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

int TreeDepth(BTNode* root);
BTNode* TreeFind(BTNode* root, BTDataType x);

int TreeNodeSize(BTNode* root);
int TreeLeafSize(BTNode* root);
int TreeLevelKSize(BTNode* root, int k);

void DestroyTree(BTNode* root);