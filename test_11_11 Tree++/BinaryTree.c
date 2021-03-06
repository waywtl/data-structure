#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");

	QueueDestroy(&q);
}

bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	//遇到第一个空就停止循环
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//继续出剩下的元素，若遇到非空，则不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
			return false;
	}

	QueueDestroy(&q);
	return true;
}

int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

/*BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* leftRet = TreeFind(root->left, x);
	if (leftRet)
		return leftRet;

	BTNode* rightRet = TreeFind(root->right, x);
	if (rightRet)
		return rightRet;

	return NULL;
}*/

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	BTNode* findNode = NULL;
	if (root->data == x)
		findNode = root;

	if (root->left && findNode == NULL)
		findNode = TreeFind(root->left, x);

	if (root->right && findNode == NULL)
		findNode = TreeFind(root->right, x);

	return findNode;
}

int TreeNodeSize(BTNode* root)
{
	return root == NULL ? 0 : 1 + TreeNodeSize(root->left) + TreeNodeSize(root->right);
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}

void DestroyTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestroyTree(root->left);
	DestroyTree(root->right);

	free(root);
	root = NULL;
}