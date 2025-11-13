#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next; 
}Snode;

int push(Snode **top,int x)
{
	Snode *newnode = (Snode*)malloc(sizeof(Snode));
	if(!newnode)
	    return 0;
	newnode->data = x;
	newnode->next = *top;
	*top = newnode;
	return 1;
}

int pop(Snode **top,int *x)
{
	if(*top == NULL)    //栈空
	    return 0;
    Snode *temp = *top;    //临时指针temp存储top地址便于清除内存
    *x = temp->data;    //存储出栈元素
    *top = temp->next;
    free(temp);
    return 1;
}

void PrintStack(Snode *top)
{
	if(top == NULL)
	{
		printf("栈空,栈中无元素\n");
		return;
	}
	printf("栈中元素(顶到底):");
	Snode *p = top;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
int Min(Snode **top)
{
    if(*top == NULL)
        return 0;
    Snode *i = *top;
    int num = i->data;
    while(i->next != NULL)
    {
        i = i->next;
        if(i->data < num)
            num = i->data;
    }
    return num;
}
int main()
{
    Snode *top = NULL; 
 	int x;
 	printf("请输入入栈的元素(输入-999结束):");
 	while(1)
 	{
	 	scanf("%d",&x);
 	    if(x == -999)
			break;
		push(&top,x);
 	}
    int minnum = Min(&top);
    if(minnum == 0)
        printf("栈空，无最小元素");
    else
        printf("该栈中的最小元素为%d",minnum);
    return 0;
}