#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"
int main()
{
	void checkList(LinkedList L);
	Status CreatList_H(LinkedList L);
	puts("_____________________________________");
	puts("1.��ʼ������  2 ��������");
	puts("3.��������    4 �鿴����");
	puts("5.������    6 ɾ�����");
	puts("7.��ת����    8 ���ҽ��");
	puts("9.��������    10 �ж��Ƿ�Ϊѭ������");
	puts("11.�ҵ��м�ڵ�");
	puts("12.�˳�");
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
			puts("����������");
			//LNode* temp1 = (LinkedList)malloc(sizeof(LNode));
			scanf("%d", &temp1->data);
			temp1->next = NULL;
			InsertList(L, temp1);
			break;
		case 6:
			checkList(L);
			puts("ɾ���ڼ�����");
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
			puts("��������ҵĽڵ�����");
			int temp3;
			scanf("%d", &temp3);
			if (SearchList(L, temp3))
				puts("����");
			else
				puts("������");
			break;
		case 9:
			puts("��ûд�����ĺ���");
			break;
		case 10:
			if (IsLoopList(L))
				puts("ѭ��");
			else
				puts("��ѭ��");
			break;
		case 11:
			temp4 = FindMidNode(&L);
			if (temp4 != NULL) { printf("%d\n", temp4->data); }
			else printf("����Ϊ��");
			break;
		case 12:
			goto final;
			break;
		}
	}
	final:;
}

