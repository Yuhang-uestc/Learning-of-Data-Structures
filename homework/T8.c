#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
typedef struct{
	int data[MAX_SIZE];
	int top;
}Stack;

void InitStack(Stack *s)
{
	s->top = -1;
}

int IsEmpty(Stack *s)
{
	return s->top == -1;
}
int IsFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int Push(Stack *s,int value)
{
	if(IsFull(s))
	{
		printf("鏍堟弧锛乗n");
		return 0;
	}
	s->data[++(s->top)] = value;
	return 1;
}

int Pop(Stack *s)
{
	if(IsEmpty(s))
	{
		printf("鏍堢┖锛乗n");
		return -1;
	}
	return s->data[(s->top)--];
}

int GetTop(Stack *s)
{
	if(IsEmpty(s))
	{
		printf("鏍堢┖锛乗n");
		return -1;
	}
	return s->data[s->top ];
}

typedef struct{
	Stack stack_in;
	Stack stack_out;
}Que;

void InitQue(Que *q)
{
	InitStack(&q->stack_in);
	InitStack(&q->stack_out);
}

int EnQue(Que *q,int value)
{
	return Push(&q->stack_in,value);
}

int DeQue(Que *q)
{
	if(IsEmpty(&q->stack_out))
	{
		while(!IsEmpty(&q->stack_in))
		{
			int val = Pop(&q->stack_in);
			Push(&q->stack_out,val);
		}
	}
	if(IsEmpty(&q->stack_out))
	{
		printf("闃熷垪涓虹┖锛屾棤娉曞嚭闃燂紒\n");
		return -1;
	}
	return Pop(&q->stack_out);
}

int Front(Que *q)
{
	if(IsEmpty(&q->stack_out))
	{
		while(!IsEmpty(&q->stack_in))
		{
		int val = Pop(&q->stack_in);
        Push(&q->stack_out, val);
		}
	}
	if (IsEmpty(&q->stack_out)) 
	{
        printf("闃熷垪涓虹┖锛屾棤闃熼鍏冪礌锛乗n");
        return -1;
    }
    return GetTop(&q->stack_out);
}

int main()
{
	Que q;
	InitQue(&q);
	
	EnQue(&q,1);
	EnQue(&q,2);
	EnQue(&q,3);
	printf("闃熼鍏冪礌锛�%d\n",Front(&q));
	printf("鍑洪槦鍏冪礌锛�%d\n",DeQue(&q));
	printf("闃熼鍏冪礌锛�%d\n",Front(&q));
	
	EnQue(&q, 4);
    printf("鍑洪槦鍏冪礌锛�%d\n", DeQue(&q));
    printf("鍑洪槦鍏冪礌锛�%d\n", DeQue(&q));
    printf("闃熼鍏冪礌锛�%d\n", Front(&q));
    printf("鍑洪槦鍏冪礌锛�%d\n", DeQue(&q));
    printf("鍑洪槦鍏冪礌锛�%d\n", DeQue(&q));
    
    return 0;
}
