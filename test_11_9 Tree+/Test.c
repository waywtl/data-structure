#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

void Test()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	if (A == NULL)
	{
		exit(-1);
	}
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	printf("TreeNodeSize: %d\n", TreeNodeSize(A));
	printf("TreeNodeSize: %d\n", TreeNodeSize(B));

	printf("TreeLeafSize: %d\n", TreeLeafSize(A));
	printf("TreeLeafSize: %d\n", TreeLeafSize(B));

	printf("%d\n", TreeDepth(A));

	printf("%d\n", TreeLevelKSize(A, 2));

	BTNode* ret = TreeFind(A, C->data);
	printf("%c\n", ret->data);
}

int main()
{
	Test();
	return 0;
}