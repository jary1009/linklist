#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"
int main()
{
	void checkList(LinkedList L);
	Status CreatList_H(LinkedList L);
	puts("_____________________________________");
	puts("1.初始化链表  2 创造链表");
	puts("3.销毁链表    4 查看链表");
	puts("5.插入结点    6 删除结点");
	puts("7.反转链表    8 查找结点");
	puts("9.遍历链表    10 判断是否为循环链表");
	puts("11.找到中间节点");
	puts("12.退出");
	LinkedList L = NULL;
	int index = 0;
	int aa = 0;
	LinkedList temp2 = L;
	LinkedList temp4 = FindMidNode(&L);
	while (1)
	{
		LNode* temp1 = (LinkedList)malloc(sizeof(LNode));
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			InitList(&L);
			break;
		case 2:
			CreatList_H(L);
			break;
		case 3:
			DestroyList(&L);
			break;
		case 4:
			checkList(L);
			break;
		case 5:
			puts("请输入数据");
			//LNode* temp1 = (LinkedList)malloc(sizeof(LNode));
			scanf("%d", &temp1->data);
			temp1->next = NULL;
			InsertList(L, temp1);
			break;
		case 6:
			checkList(L);
			puts("删除第几个？");
			index = 0;
			aa = 0;
			temp2 = L;
			scanf("%d", &index);

			for (int i = 0; i < index - 1; i++) {
				temp2 = temp2->next;
			}
			DeleteList(temp2, &aa);
			checkList(L);
			break;
		case 7:
			ReverseList(&L);
			break;
		case 8:
			puts("请输入查找的节点数据");
			int temp3;
			scanf("%d", &temp3);
			if (SearchList(L, temp3))
				puts("存在");
			else
				puts("不存在");
			break;
		case 9:
			puts("还没写遍历的函数");
			break;
		case 10:
			if (IsLoopList(L))
				puts("循环");
			else
				puts("不循环");
			break;
		case 11:
			temp4 = FindMidNode(&L);
			if (temp4 != NULL) { printf("%d\n", temp4->data); }
			else printf("链表为空");
			break;
		case 12:
			goto final;
			break;
		}
	}
	final:;
}

