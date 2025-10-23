#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode *LinkList;
typedef struct Lnode{
	int data;
	LinkList next;
}LN;
// LN = *LinkList

void CreateLinkList(LinkList *head)
{
	*head = NULL;
	LinkList newnode,tail = NULL;
	int num;
	
	printf("请输入链表元素（空格分隔，输入-1结束）：");
	while(scanf("%d",&num) == 1)
	{
		if(num == -1)
		    break;
  
		newnode = (LinkList)malloc(sizeof(LN));
		if(newnode == NULL)
		{
			printf("内存分配失败！\n");
			exit(1);
		}
		newnode->data = num;
		newnode->next = NULL;
		
	    if(*head == NULL)
	    {
		    *head = newnode;
		    tail = newnode;
        }
	    else
	    {
		    tail->next = newnode;
		    tail = newnode;
	    }
	}
}

LinkList MergeList(LinkList L1,LinkList L2)
{
	LinkList temp_head = (LinkList)malloc(sizeof(LN));
    temp_head->next = NULL;
	LN *p1 = L1, *p2 = L2, *tail = temp_head;
	
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
			LinkList temp = p2;
			p2 = p2->next;
			free(temp);
		}
		tail = tail->next;
	}
	tail->next = (p1 != NULL) ? p1 : p2;
	LinkList newhead = temp_head->next;
	free(temp_head);
	
	return newhead;
}

void PrintfList(LinkList head)
{
	LN *p = head;
	while(p != NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList L1,L2,Merge;
	CreateLinkList(&L1);
	CreateLinkList(&L2);
	
	printf("L1:");
	PrintfList(L1);
	
	printf("L2:");
	PrintfList(L2);
	
	Merge = MergeList(L1,L2);
	printf("合并后为：");
	PrintfList(Merge);
	
	return 0;
}
