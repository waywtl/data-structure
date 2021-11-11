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

//ǰ,��,�������
void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

//�������
void LevelOrder(BTNode* root);
//�ж��Ƿ�Ϊ��ȫ������
bool TreeComplete(BTNode* root);

//�������
int TreeDepth(BTNode* root);
//����ĳ��Ԫ��
BTNode* TreeFind(BTNode* root, BTDataType x);

//���Ľڵ����
int TreeNodeSize(BTNode* root);
//����Ҷ�Ӹ���
int TreeLeafSize(BTNode* root);
//��K��ڵ����
int TreeLevelKSize(BTNode* root, int k);

//������
void DestroyTree(BTNode* root);