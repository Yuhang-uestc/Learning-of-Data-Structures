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

void ReverseList(LinkList head)
{
	if(head->next == NULL || head->next->next == NULL)
        return;
    LN *pre = NULL;
    LN *cur = head->next;
    LN *next = NULL;
    
    while(cur != NULL)
    {
    	next = cur->next;
    	cur->next = pre;
    	pre = cur;
    	cur = next;
	}
	head->next = pre;
}

void PrintfList(LinkList head)
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
	int arr[] = {1,2,3,4};
	LinkList head;
	
	CreateLinkList(&head,arr,4);
	
	printf("原链表：");
	PrintfList(head);
	
	ReverseList(head);
	
	printf("逆转后：");
	PrintfList(head);
	
	return 0; 
}
