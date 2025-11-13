#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node,*LinkList;

void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(*L == NULL)
	{
		printf("内存分配失败，链表初始化失败\n");
		exit(1);
	}
	(*L)->next = NULL;
}

void CreateList(LinkList L)
{
	Node *p = L;
	int n,data;
	printf("请输入要创建的链表元素个数：");
	scanf("%d",&n);
	if(n <= 0)
	{
		printf("元素个数非法");
		return;
	}
	printf("请按顺序输入%d个整数(空格分隔)",n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&data);
		Node *newnode = (Node*)malloc(sizeof(Node));
		if(newnode == NULL)
		{
			printf("内存分配失败，创建链表失败\n");
			exit(1);
		}
		newnode->data = data;
		newnode->next = NULL;
		
		p->next = newnode;
		p = newnode;
	}
}

void PrintList(LinkList L)
{
	if(L->next == NULL)
	{
		printf("链表为空\n");
		return;
	}
	Node *p = L->next;
	printf("链表元素：");
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int InsertList(LinkList L,int pos,int data)
{
	if(pos < 1)
	{
		printf("插入位置非法\n");  //pos从1开始，物理意义上的位置
		return 0;
	}
	Node *p = L;
	int count = 0;
	while(p != NULL && count < pos-1)
	{
		p = p->next;
		count++;
	}
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = p->next;
	p->next = newnode;
	
	return 1;
}

int DeleteList(LinkList L,int pos)
{
	if(L->next == NULL)
	
	{
		printf("链表为空，无法删除\n");
		return 0;
	}
	if(pos < 1)
	{
			printf("删除位置非法\n");
			return 0;
	}
	Node *p = L;
	int count = 0;
	while(p != NULL && count < pos-1)
	{
		p = p->next;
		count++;
	}
	Node *denode = p->next;
	p->next = denode->next;
	free(denode);
	return 1;
}

void ReverseList(LinkList L)
{
	if(L->next == NULL || L->next->next == NULL)
	    return;
	Node *pre = NULL;
	Node *cur = L->next;
	Node *nex = NULL;
	while(cur != NULL)
	{
		nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	L->next = pre;
}

void BubbleSort(LinkList L)
{
	if(L->next == NULL || L->next->next == NULL)
	    return;
	int length = 0;
	Node *p = L->next;
	while(p != NULL)
	{
		length++;
		p = p->next;
	}
	int flag = 1;
	for(int i = 0;i < length - 1 && flag;i++)
	{
		flag = 0;
		p = L->next;
		for(int j = 0;j < length -1;j++)
		{
			if(p->data > p->next->data)
			{
				int m = p->data;
				p->data = p->next->data;
				p->next->data = m;
				flag = 1;
			}
			p = p->next;
		}
	}
}

void DestroyList(LinkList L)
{
	Node *p = L->next;
	while(p != NULL)
	{
		Node *temp = p;
		p = p->next;
		free(temp);
	}
	L->next = NULL;
}

int main()
{
	LinkList L;
	int choice,pos,data;
	InitList(&L);
	while(1)
	{
		printf("\n1.创建单链表 2.输出链表元素 3.插入元素 4.删除元素 5.翻转链表 6.冒泡排序 7.删除整个链表 0.退出程序\n");
		printf("请输入您的选择：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: CreateList(L);
			        PrintList(L);
			        break;
			case 2: PrintList(L);
			        break;
			case 3: printf("请输入插入位置：");
			        scanf("%d",&pos);
			        printf("请输入插入的整数");
			        scanf("%d",&data);
					InsertList(L,pos,data);
			        PrintList(L);
			        break;
			case 4: printf("请输入删除位置");
					scanf("%d",&pos);
			        DeleteList(L,pos);
			        PrintList(L);
					break;
			case 5: ReverseList(L);
			        PrintList(L);
			        break;
			case 6: BubbleSort(L);
			        PrintList(L);
			        break;
			case 7: DestroyList(L);
			        PrintList(L);
			        break;
			case 0: DestroyList(L);
			        free(L);
			        printf("程序退出成功\n");
			        return 0;
			default:printf("输入错误，请重新选择(0-7)\n");
            break;
       	}
    }
}
