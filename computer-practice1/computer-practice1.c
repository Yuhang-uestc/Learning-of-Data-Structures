#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 100  //顺序表最大容量
typedef struct {
    int data[MAX_SIZE];  //存储顺序表的元素
    int length;          //顺序表元素个数
} SeqList;  // 结构体别名SeqList

    //-------------------------- 1：创建顺序表函数 --------------------------
    
//函数功能：创建顺序表（从键盘读入元素）
void CreateSL(SeqList *SL) 
{
    int n, i;  // n：用户输入的元素个数；i：循环变量
    
    SL->length = 0;         //初始化顺序表（长度置0）

    printf("请输入顺序表的元素个数：");        //读取输入的元素个数
    scanf("%d", &n);        //逐个读取元素，存入顺序表
    
    printf("请输入%d个整数（空格分隔): ", n);
    
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &(SL->data[i]));  //将输入值存入data数组
        SL->length++;  // 每存一个元素，长度+1
    }
    
    printf("创建的顺序表元素：");        //输出顺序表
    
    for (i = 0; i < SL->length; i++)
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}

    // -------------------------- 2：插入元素函数 --------------------------
    
// 函数功能：在顺序表指定位置插入元素
int InsertSL(SeqList *SL, int pos1, int value) 
{
    int i;
    
    if (pos1 < 1 || pos1 > SL->length + 1)    //判断插入位置是否在1~length+1之间
	{
        printf("插入位置不合理！\n");
        return 0;
    }
    if (SL->length >= MAX_SIZE)     //判断表是否已满
	{
        printf("顺序表已满，无法插入！\n");
        return 0;
    }
    
    for (i = SL->length; i >= pos1; i--)    //从最后一个元素到pos位置前一个元素后移
	{
        SL->data[i] = SL->data[i - 1];    //后移1位
    }
    
    SL->data[pos1 - 1] = value;    //插入新元素
    SL->length++;   //长度+1
    
    printf("插入后的顺序表元素：");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    
    return 1;
}

    //-------------------------- 3：删除元素函数 --------------------------
    
//函数功能：删除顺序表指定位置的元素
int DeleteSL(SeqList *SL, int pos2) 
{
    int i;
    

    if (pos2 < 1 || pos2 > SL->length)    //判断删除位置是否在1~length之间 
	{
        printf("删除位置不合理！\n");
        return 0;
    }
    

    for (i = pos2; i < SL->length; i++)    //从pos位置到最后一个元素的前一个元素前移 
	{
        SL->data[i - 1] = SL->data[i];  // 前移1位
    }
    
    SL->length--;       //长度-1
    
    printf("删除后的顺序表元素：");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}

    //-------------------------- 4：统计并删除负数函数 --------------------------
    
//函数功能：统计顺序表中负数个数，并删除所有负数
void CADNeg(SeqList *SL) 
{
    int i,j,count = 0;   //负数个数变量

    for (i=0; i < SL->length; ) 
	{
        if (SL->data[i] < 0)
		{ 
            count++;    //遇到负数，计数+1
            for (j = i + 1; j < SL->length; j++) 
				{
			        SL->data[j - 1] = SL->data[j];    //前移1位
			    }
            SL->length--; 
		}
		else
			i++;
    }

    printf("顺序表中负数的个数：%d\n", count);
    printf("删除负数后的顺序表元素：");
    
    for (i = 0; i < SL->length; i++) 
        printf("%d ", SL->data[i]);
        
    printf("\n");
}

    //-------------------------- 5：合并有序表+求中位数函数 --------------------------
    
//函数功能：合并两个递增有序的顺序表A、B，生成递增有序的顺序表C
void MergeSL(SeqList A, SeqList B, SeqList *C) 
{
    int i = 0, j = 0, k = 0;  // i：A的索引；j：B的索引；k：C的索引
    
    while (i < A.length && j < B.length) 
	{
        if (A.data[i] <= B.data[j]) 
            C->data[k++] = A.data[i++];
		else
            C->data[k++] = B.data[j++];
    }
    
    // 处理A中剩余的元素
    while (i < A.length) 
	{
        C->data[k++] = A.data[i++];
    }
    // 处理B中剩余的元素
    while (j < B.length) {
        C->data[k++] = B.data[j++];
    }
    // 更新C的长度
    C->length = k;
    
    // 5. 输出合并后的顺序表
    printf("合并后的有序顺序表C：");
    for (int m = 0; m < C->length; m++) 
    {
        printf("%d ", C->data[m]);
    }
    printf("\n");
}

// 函数功能：求有序顺序表的中位数
double GetMedian(SeqList SL) 
{
    if (SL.length == 0) 
	{
        printf("顺序表为空，无中位数！\n");
        return -1;  // 非法值标记
    }
    if (SL.length % 2 == 1)     //长度为奇数
	{
        return SL.data[SL.length / 2];  //奇数直接返回中间元素（"/"取整） 
    } 
	else     //长度为偶数
	{
        int mid1 = SL.data[(SL.length - 1) / 2];
        int mid2 = SL.data[SL.length / 2];
        return (mid1 + mid2) / 2.0;  // 偶数返回平均值(浮点数) 
    }
}

    //-------------------------- 6：删除重复元素函数 --------------------------

//函数功能：删除升序顺序表中的重复元素（每个元素只保留一次）
void Remove(SeqList *SL) 
{
    int i, j = 0;  //j：记录不重复元素的位置（新顺序表的索引）
    
    if (SL->length <= 1) 
	{
        printf("顺序表元素个数≤1，无重复元素！\n");
        return;
    }

    // 去重（利用升序特性：重复元素必相邻）
    for (i = 1; i < SL->length; i++)    //i=1保证从数组第二个元素开始与前一位查重
	{

        if (SL->data[i] != SL->data[j])       // 若当前元素与前一个不重复，存入j+1位置 
		{
            j++;
            SL->data[j] = SL->data[i];
        }
    }
    // 更新顺序表长度（不重复元素的个数=j+1）
    SL->length = j + 1;
    
    printf("删除重复元素后的顺序表：");
    for (i = 0; i < SL->length; i++) 
        printf("%d ", SL->data[i]);
        
    printf("\n");
}


int main() 
{
    SeqList SL, A, B, C, D;  
    int pos1, value, pos2;    //pos1插入元素位置,value插入元素值,pos2删除元素位置 
    

    printf("=== 题目1：创建顺序表 ===\n");
    
    CreateSL(&SL);
    printf("\n");
    

    printf("=== 题目2：插入元素 ===\n");
    
    printf("请输入要插入的元素值和位置（用空格分隔）：");
    scanf("%d %d", &value, &pos1);
    
    InsertSL(&SL, pos1, value);
    printf("\n");
    

    printf("=== 题目3：删除元素 ===\n");
    
    printf("请输入要删除的元素位置：");
    scanf("%d", &pos2);
    
    DeleteSL(&SL, pos2);
    printf("\n");
    

    printf("=== 题目4：统计并删除负数 ===\n");
    
    CADNeg(&SL);
    printf("\n");
    

    printf("=== 题目5：合并两个递增有序表+求中位数 ===\n");

    printf("创建递增有序表A：\n");
    CreateSL(&A);
    
    printf("创建递增有序表B：\n");
    CreateSL(&B);

    MergeSL(A, B, &C);    //将A、B合并为C 
    double GM = GetMedian(C);     //用GM接受中位数 
    
    if (GM == -1) 
	{
    printf("请重新输入一个合理的升序顺序表进行中位数操作");
    CreateSL(&D);
    GetMedian(D);
    } 
	else
    printf("合并后顺序表C中位数是%.1f\n", GM);

    printf("\n");
    
    
    printf("=== 题目6：删除升序表中的重复元素 ===\n");

    Remove(&C);    //确认升序后，执行去重并输出 

    return 0;
}

