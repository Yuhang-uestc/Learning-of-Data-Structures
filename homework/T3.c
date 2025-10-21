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

LinkList ReverseList(LinkList head)
{
    LN *pre = NULL;
    LN *cur = head;
    LN *next = NULL;
    
    while(cur != NULL)
    {
    	next = cur->next;
    	cur->next = pre;
    	pre = cur;
    	cur = next;
	}
	return pre; 
}

void PrintfList(LinkList head)
{
	LN *p = head;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{

	LinkList head;
	
	CreateLinkList(&head);
	
	printf("原链表：");
	PrintfList(head);
	
	head = ReverseList(head);
	
	printf("逆转后：");
	PrintfList(head);
	
	LinkList temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	
	return 0; 
}
