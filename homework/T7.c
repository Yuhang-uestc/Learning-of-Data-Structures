#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct{
	int data[MAX_SIZE];
	int front;
	int rear;
}CirQue;

void InitQue(CirQue *q)
{
	q->front = 0;
	q->rear = 0;
}

int IsQueEmpty(CirQue *q)
{
	return q->front == q->rear;
}

int IsQueFull(CirQue *q)
{
	return (q->rear + 1) % MAX_SIZE == q->front;
}

int EnQue(CirQue *q,int value)
{
	if(IsQueFull(q))
	{
		printf("���������޷���ӣ�\n");
		return 0;
	}
	q->data[q->rear] = value;
	q->rear = (q->rear + 1) % MAX_SIZE;
	return 1;
}

int DeQue(CirQue *q,int *value)
{
	if(IsQueEmpty(q))
	{
		printf("����Ϊ�գ��޷�����\n");
		return 0;
	}
	*value = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	return 1;
}

void PrQue(CirQue *q)
{
    if (IsQueEmpty(q)) 
	{
        printf("����Ϊ�գ�\n");
        return;
    }
    printf("����Ԫ�أ�����->��β��:");
    int i = q->front;
    while(i != q->rear)
    {
    	printf("%d ",q->data[i]);
    	i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}

int main()
{
	CirQue q;
	InitQue(&q);
	
	EnQue(&q,10);
	EnQue(&q,20);
	EnQue(&q,30);
	PrQue(&q);
	
	int num;
	DeQue(&q,&num);
	printf("����Ԫ�أ�%d \n",num);
	PrQue(&q);
	
	for(int i = 40;i < 130;i += 10)
	{
		EnQue(&q,i);
	}
	PrQue(&q);
	return 0;
}