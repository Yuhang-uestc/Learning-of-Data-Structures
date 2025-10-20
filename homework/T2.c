#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode *LinkList;
typedef struct Lnode{
	int data;
	LinkList next;
}LN;
// LN = *LinkList

void CreateLinkList(LinkList *head,int arr[],int n)
{
	*head = (LinkList)malloc(sizeof(LN));
	(*head)->next = NULL;
	LN *tail = *head;
	
	for(int i=0;i<n;i++)
	{
		LN *Newnode = (LinkList)malloc(sizeof(LN));
		Newnode->data = arr[i];
		Newnode->next = NULL;
		tail->next = Newnode;
		tail = Newnode;
	}
}

LinkList MergeLinkList(LinkList L1,LinkList L2)
{
	LinkList newhead = (LinkList)malloc(sizeof(LN));
	newhead->next = NULL;
	LN *p1 = L1->next, *p2 = L2->next, *tail = newhead;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data < p2->data)
		{
			tail->next = p1;
			p1 = p1->next;
		}
		else if(p1->data > p2->data)
		{
			tail->next = p2;
			p2 = p2->next;
		}
		else
		{
			tail->next = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		tail = tail->next;
	}
	tail->next = (p1 != NULL) ? p1 : p2;
	free(L1);
	free(L2);
	return newhead;
}

void PrintfLinkList(LinkList head)
{
	LN *p = head->next;
	while(p != NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int arr1[]={1,3,5,7},arr2[]={2,3,6,7,9};
	LinkList L1,L2,Merge;
	CreateLinkList(&L1,arr1,4);
	CreateLinkList(&L2,arr2,5);
	
	printf("L1:");
	PrintfLinkList(L1);
	
	printf("L2:");
	PrintfLinkList(L2);
	
	Merge = MergeLinkList(L1,L2);
	printf("合并后为：");
	PrintfLinkList(Merge);
	
	return 0;
}
