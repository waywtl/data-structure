#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

//void ListInit(ListNode** pphead);
ListNode* ListInit();
void ListClear(ListNode* phead);
void ListDestory(ListNode** pphead);

ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);

void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);

void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
//在pos前面插入x
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);


/*链表和顺序表(数组)的区别和联系：
*1.顺序表就是在数组的基础上实现增删查改，并且插入时可以动态增长
* 顺序表缺陷：
* a.可能存在一定空间浪费
* b.增容有一些效率损失
* c.中间或者头部插入删除，时间复杂度为O(N),因为要挪动数据
这些问题链表解决了。

链表的缺陷：不能随机访问，缓存命中率低

互补的数据结构*/