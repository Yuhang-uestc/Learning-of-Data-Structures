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
		printf("栈满，无法入栈！\n");
		return 0;
	}
	s->data[++(s->top)] = value;
	return 1;
}

int Pop(Stack *s)
{
	if(IsEmpty(s))
	{
		printf("栈空，无法出栈！\n");
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
	printf("八进制结果：");
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
			printf("输入的不是合法八进制数！\n");
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
	printf("请输入一个十进制整数：");
	scanf("%d",&dec);
	
	DecToOct(dec);
	
	int oct;
	printf("请输入刚才转换得到的八进制数（用于验证）：");
	scanf("%d",&oct);
	int verify_dec = OctToDec(oct);
	if(verify_dec != -1)
	{
		printf("验证：八进制%d转十进制为%d\n",oct,verify_dec);
		if(verify_dec == dec)
			printf("转换正确\n");
		else
		    printf("转换错误\n");
		}
		return 0;
}