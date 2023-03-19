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
	//Ϊʲô���氡��
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
	//Ҫ�ݴ�L->next,��Ȼ����֮���Ҳ�������
	LNode* temp = p->next;
	p->next = p->next->next;
	free(temp);
	return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//����ͷ�ڵ�
	if (L != NULL)L = L->next;
	else return;
	while (L != NULL)
	{
		//visit�Զ��庯��
		visit(L->data);
		L->next;
	}
}

Status SearchList(LinkedList L, ElemType e)
{
	//����ͷ�ڵ�
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
	//�������Ϊ��ֱ�ӷ��ش���
	if ((*L) == NULL)return ERROR;
	//�������ֻ��һ��ͷ�ڵ��ֻ��һ��ͷ�ڵ��һ���ڵ㣬ֱ�ӷ��سɹ�
	if ((*L)->next == NULL || (*L)->next->next == NULL)return SUCCESS;
	//��¼ͷ�ڵ㣬����Ҫ��
	LinkedList head = (*L);
	//Ҫ�����ڵ�ָ�룬temp1��temp2��temp3
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

	//�пղ��ϵݹ�
}

Status IsLoopList(LinkedList L)
{
	//����ָ�뷨����������ѭ��������ָ�벻����������֮�����ǻ�����
	//����ͷ�ڵ㣬����ͷ�ڵ�ѭ������ô��ѭ������ͷ���û�д��ڵı�Ҫ
	if (L == NULL || L->next == NULL || L->next->next == NULL)return ERROR;
	LinkedList fast = L->next->next, slow = L->next;
	while (fast->next != NULL && slow != NULL && fast->next->next != NULL && slow->next != NULL)
	{
		if (fast == slow)return SUCCESS;
		fast = fast->next->next;
		slow = slow->next;
	}
	return ERROR;
	//ֻ�����˵�����ģ�û�в���ѭ���ģ��п�д��ѭ���Ĳ�һ��
	//�߼��е㷱�����пոĸ�
}

LNode* ReverseEvenList(LinkedList* L)
{
	//����Ϊʲôͷ�ڵ����µ��ˡ�
	if (*L == NULL || (*L)->next == NULL || (*L)->next->next == NULL) return (*L)->next;
	LinkedList head = (*L)->next->next;
	LinkedList cur = *L;
	//�ݴ��ַ
	while (cur->next != NULL && cur->next->next != NULL)
	{
		LinkedList temp1 = cur->next;
		LinkedList temp2 = cur->next->next->next;

		cur->next = cur->next->next;
		cur->next->next = temp1;
		cur->next->next->next = temp2;

		cur = cur->next->next;
	}
	//���Ǻ��������˼·��Ҫ����ӡ��
	//����һ��˼·
	////����żλ�ò��������1->3->5->7->NULL��8->6->4->2->NULL
	//	��תż������1->3->5->7->NULL��2->4->6->8->NULL
		//�ϲ���������������1->2->3->4->5->6->7->8->NULL
	return head;
}
LNode* FindMidNode(LinkedList* L)
{
	//����ָ�뷨
	//�в���㣬����ͷ�ڵ㣬���������Ϊ������ȡ�м䣬���Ϊż����ȡƫ��ߵ�
		//�ջ�ֻ��ͷ���
	if (*L == NULL || (*L)->next == NULL)return NULL;
	//ֻ��һ���ڵ�;
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
	//ͷ�巨��������
	int num;
	while (1)
	{
		puts("�����봴�켸�����");
		scanf("%d", &num);
		if (num > 0)break;
	}
	for (int i = 0; i < num; i++) {
		LNode* temp = (LNode*)malloc(sizeof(LNode));
		if (!temp)
			return ERROR;
		puts("������������");
		scanf("%d", &temp->data);

		temp->next = L->next;
		L->next = temp;
	}
	return SUCCESS;
}
