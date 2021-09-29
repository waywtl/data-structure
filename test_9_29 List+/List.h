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
//��posǰ�����x
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);


/*�����˳���(����)���������ϵ��
*1.˳������������Ļ�����ʵ����ɾ��ģ����Ҳ���ʱ���Զ�̬����
* ˳���ȱ�ݣ�
* a.���ܴ���һ���ռ��˷�
* b.������һЩЧ����ʧ
* c.�м����ͷ������ɾ����ʱ�临�Ӷ�ΪO(N),��ΪҪŲ������
��Щ�����������ˡ�

�����ȱ�ݣ�����������ʣ����������ʵ�

���������ݽṹ*/