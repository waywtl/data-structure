#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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

//层序遍历
void LevelOrder(BTNode* root);
//判断是否为完全二叉树
bool TreeComplete(BTNode* root);

//树的深度
int TreeDepth(BTNode* root);
//查找某个元素
BTNode* TreeFind(BTNode* root, BTDataType x);

//树的节点个数
int TreeNodeSize(BTNode* root);
//树的叶子个数
int TreeLeafSize(BTNode* root);
//第K层节点个数
int TreeLevelKSize(BTNode* root, int k);

//销毁树
void DestroyTree(BTNode* root);