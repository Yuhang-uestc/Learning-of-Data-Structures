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
		printf("ջ�����޷���ջ��\n");
		return 0;
	}
	s->data[++(s->top)] = value;
	return 1;
}

int Pop(Stack *s)
{
	if(IsEmpty(s))
	{
		printf("ջ�գ��޷���ջ��\n");
		return -1;
	}
	return s->data[(s->top)--];
}

void DecToOct(int dec)
{
	Stack s;
	InitStack(&s);
	
	if(dec == 0)
	    Push(&s,0);
	while(dec > 0)
	{
		int rem = dec % 8;
		Push(&s,rem);
		dec = dec / 8;
	}
	printf("�˽��ƽ����");
	while(!IsEmpty(&s))
	{
		printf("%d",Pop(&s));
	}
	printf("\n");
}

int OctToDec(int oct)
{
	int dec = 0;
	int base =1;
	while(oct > 0)
	{
		int digit = oct % 10;
		if(digit >= 8)
		{
			printf("����Ĳ��ǺϷ��˽�������\n");
			return -1;
		}
		dec += digit * base;
		oct = oct / 10;
		base *= 8;
	}
	return dec;
}

int main()
{
	int dec;
	printf("������һ��ʮ����������");
	scanf("%d",&dec);
	
	DecToOct(dec);
	
	int oct;
	printf("������ղ�ת���õ��İ˽�������������֤����");
	scanf("%d",&oct);
	int verify_dec = OctToDec(oct);
	if(verify_dec != -1)
	{
		printf("��֤���˽���%dתʮ����Ϊ%d\n",oct,verify_dec);
		if(verify_dec == dec)
			printf("ת����ȷ\n");
		else
		    printf("ת������\n");
		}
		return 0;
}