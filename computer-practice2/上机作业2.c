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
		printf("�ڴ����ʧ�ܣ������ʼ��ʧ��\n");
		exit(1);
	}
	(*L)->next = NULL;
}

void CreateList(LinkList L)
{
	Node *p = L;
	int n,data;
	printf("������Ҫ����������Ԫ�ظ�����");
	scanf("%d",&n);
	if(n <= 0)
	{
		printf("Ԫ�ظ����Ƿ�");
		return;
	}
	printf("�밴˳������%d���������ÿո�ָ�����",n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&data);
		Node *newnode = (Node*)malloc(sizeof(Node));
		if(newnode == NULL)
		{
			printf("�ڴ����ʧ��\n");
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
		printf("����Ϊ��\n");
		return;
	}
	Node *p = L->next;
	printf("����Ԫ�أ�");
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
		printf("����λ�÷Ƿ�\n");
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
		printf("����Ϊ��\n");
		return 0;
	}
	if(pos < 1)
	{
			printf("����λ�÷Ƿ�\n");
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
		printf("\n1.�������� 2.������� 3.����Ԫ�� 4.ɾ��Ԫ�� 5.��ת���� 6.�������� 7.ɾ���������� 0.�˳�\n");
		printf("������ѡ��");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: CreateList(L);
			        PrintList(L);
			        break;
			case 2: PrintList(L);
			        break;
			case 3: printf("����λ�ã�");
			        scanf("%d",&pos);
			        printf("����Ԫ�أ�");
			        scanf("%d",&data);
					InsertList(L,pos,data);
			        PrintList(L);
			        break;
			case 4: printf("ɾ��λ�ã�");
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
			        printf("�˳���\n");
			        return 0;
       	}
    }
}
