#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
    int one[MAXSIZE];
    int two[MAXSIZE];
    int oneTop,twoTop;
}SQ;

void PrintSQ(SQ *sq)
{
	if(sq->oneTop == -1 && sq->twoTop == -1)
	{
		printf("队列为空\n");
		return;
	}
	printf("当前队列: ");
    for(int i = sq->twoTop;i >= 0;i--)
    {
        printf("%d ",sq->two[i]);
    }
    for(int j = 0;j <= sq->oneTop;j++)
    {
        printf("%d ",sq->one[j]);
    }
	printf("\n");
}

void InitSQ(SQ *sq)
{
    sq->oneTop = -1;
    sq->twoTop = -1;
}

int EnSQ(SQ *sq,int x)
{
    if(sq->oneTop == MAXSIZE - 1)
    {
        printf("队满，无法入队");
        return 0;
    }
    sq->one[++sq->oneTop] = x;
    printf("元素%d入队成功 ",x);
    PrintSQ(sq);
    return 1;
}

int DeSQ(SQ *sq,int *x)
{
    if(sq->twoTop == -1)
    {
        if(sq->oneTop == -1)
        {
            printf("队列为空,无法出队");
            return 0;
        }
        while(sq->oneTop != -1)
        {
            int temp = sq->one[sq->oneTop--];
            sq->two[++sq->twoTop] = temp;
        }
    }
    *x = sq->two[sq->twoTop--];
    printf("元素%d出队成功 ",*x);
    PrintSQ(sq);
    return 1;
}

int main()
{
    SQ sq;
    InitSQ(&sq);
    int choice,x;
    while(1)
    {
        printf("1.入队 2.出队 3.退出程序\n");
        printf("请输入你的选择:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("请输入要入队的元素: ");
                scanf("%d",&x);
                EnSQ(&sq,x);
                break;
            case 2:
                DeSQ(&sq,&x);
                break;
            case 3:
                printf("已退出程序");
                exit(0);
            default:
                printf("请输入正确的选项(1~3)");
        }
        printf("\n");
    }
    return 0;
}
