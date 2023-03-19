#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void checkList(LinkedList L)
{
	if (L == NULL)return;
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	if (*L == NULL)
	{
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}
void DestroyList(LinkedList* L)
{
	if (*L == NULL)return;
	LinkedList temp = *L;
	//为什么警告啊？
	while ((*L)->next != NULL)
	{
		temp = *L;
		*L = (*L)->next;
		free(temp);
	}
	temp = *L;
	free(temp);
	*L = NULL;
}

Status InsertList(LNode* p, LNode* q)
{
	if (p == NULL || q == NULL)return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL || p->next == NULL)return ERROR;
	*e = p->next->data;
	//要暂存L->next,不然改了之后找不回来了
	LNode* temp = p->next;
	p->next = p->next->next;
	free(temp);
	return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//跳过头节点
	if (L != NULL)L = L->next;
	else return;
	while (L != NULL)
	{
		//visit自定义函数
		visit(L->data);
		L->next;
	}
}

Status SearchList(LinkedList L, ElemType e)
{
	//跳过头节点
	if (L != NULL)L = L->next;
	else return ERROR;
	while (L)
	{
		if (L->data == e)return SUCCESS;
		L = L->next;
	}
	return ERROR;
}
Status ReverseList(LinkedList* L)
{
	//如果链表为空直接返回错误
	if ((*L) == NULL)return ERROR;
	//如果链表只有一个头节点或只有一个头节点加一个节点，直接返回成功
	if ((*L)->next == NULL || (*L)->next->next == NULL)return SUCCESS;
	//记录头节点，待会要用
	LinkedList head = (*L);
	//要三个节点指针，temp1，temp2，temp3
	LinkedList temp1 = NULL, temp2 = (*L)->next, temp3 = (*L)->next->next;
	while (temp3->next != NULL) {
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = temp3->next;
	}
	temp2->next = temp1;
	temp3->next = temp2;
	head->next = temp3;
	return SUCCESS;

	//有空补上递归
}

Status IsLoopList(LinkedList L)
{
	//快慢指针法，假如链表不循环，快慢指针不会相遇，反之，他们会相遇
	//不看头节点，假如头节点循环，那么是循环链表，头结点没有存在的必要
	if (L == NULL || L->next == NULL || L->next->next == NULL)return ERROR;
	LinkedList fast = L->next->next, slow = L->next;
	while (fast->next != NULL && slow != NULL && fast->next->next != NULL && slow->next != NULL)
	{
		if (fast == slow)return SUCCESS;
		fast = fast->next->next;
		slow = slow->next;
	}
	return ERROR;
	//只测试了单链表的，没有测试循环的，有空写个循环的测一测
	//逻辑有点繁琐，有空改改
}

LNode* ReverseEvenList(LinkedList* L)
{
	//不懂为什么头节点变成新的了。
	if (*L == NULL || (*L)->next == NULL || (*L)->next->next == NULL) return (*L)->next;
	LinkedList head = (*L)->next->next;
	LinkedList cur = *L;
	//暂存地址
	while (cur->next != NULL && cur->next->next != NULL)
	{
		LinkedList temp1 = cur->next;
		LinkedList temp2 = cur->next->next->next;

		cur->next = cur->next->next;
		cur->next->next = temp1;
		cur->next->next->next = temp2;

		cur = cur->next->next;
	}
	//不是很理解这种思路，要加深印象
	//另外一种思路
	////按奇偶位置拆分链表，得1->3->5->7->NULL和8->6->4->2->NULL
	//	反转偶链表，得1->3->5->7->NULL和2->4->6->8->NULL
		//合并两个有序链表，得1->2->3->4->5->6->7->8->NULL
	return head;
}
LNode* FindMidNode(LinkedList* L)
{
	//快慢指针法
	//中部结点，不算头节点，如果结点个数为奇数，取中间，如果为偶数，取偏左边的
		//空或只有头结点
	if (*L == NULL || (*L)->next == NULL)return NULL;
	//只有一个节点;
	if ((*L)->next->next == NULL)return (*L)->next;

	LinkedList fast = (*L)->next->next, slow = (*L)->next;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
Status CreatList_H(LinkedList L) {
	//头插法建造链表
	int num;
	while (1)
	{
		puts("请输入创造几个结点");
		scanf("%d", &num);
		if (num > 0)break;
	}
	for (int i = 0; i < num; i++) {
		LNode* temp = (LNode*)malloc(sizeof(LNode));
		if (!temp)
			return ERROR;
		puts("请输入结点数据");
		scanf("%d", &temp->data);

		temp->next = L->next;
		L->next = temp;
	}
	return SUCCESS;
}
