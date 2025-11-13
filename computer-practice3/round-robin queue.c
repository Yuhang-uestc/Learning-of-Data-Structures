#include <stdio.h>
#include <stdlib.h>

#define N 20
typedef struct{
	int data[N];
	int front,rear,tag;
}Queue;

void Initqueue(Queue *q)
{
	q->front = q->rear = 0;
    q->tag = 0;
}
int Enqueue(Queue *q,int x)
{
	if(q->rear == q->front && q->tag == 1)
	{
	    printf("队满，无法入队");
	    return 0;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % N;
    if(q->front == q->rear)
        q->tag = 1;
	return 1;
}


int Dequeue(Queue *q,int *x)
{
	if(q->front == q->rear && q->tag == 0)
	{
		printf("队空，无法出队");
		return 0;
	}
	*x = q->data[q->front];
	q->front = (q->front + 1) % N;
    if(q->front == q->rear)
        q->tag = 0;
	return 1;
}

void Printqueue(Queue *q)
{
	if(q->front == q->rear && q->tag == 0)
    {
        printf("队列为空\n");
        return;
    }
    int length = 0;
    int i = q->front;
    while((i != q->rear || q->tag == 1) && length < N)
    {
        length++;
        i = (i+1) % N;
    }
    printf("队列元素(队首到队尾):");
    i = q->front;
    for(int m = 0;m < length;m++)
    {
        printf("%d ",q->data[i]);
        i = (i + 1) % N;
    }
    printf("\n");
}
void DelMinus(Queue *q)
{
	if(q->rear == q->front && q->tag == 0)
        return;
    int x,count = 0,length = 0;
    int i = q->front;
    while((i != q->rear || q->tag ==1) && length < N)    //统计队中元素个数
    {
        length++;
        i = (i+1) % N;
    }
    while(count < length)
    {
        Dequeue(q,&x);
        if(x > 0)
            Enqueue(q,x);
        count++;
    }
}

int main()
{
    Queue q;
    Initqueue(&q);
    int x;
    printf("请输入队列元素(输入-999结束):");
    while(1)
    {
        scanf("%d",&x);
        if(x == -999)
            break;
        Enqueue(&q,x);
    }
    printf("\nDelminus调用前:");
    Printqueue(&q);
    DelMinus(&q);
    printf("\nDelminus调用后:");
    Printqueue(&q);
    return 0;
}