#include <stdio.h>
#include <stdlib.h>  // 用于内存操作（若用动态数组）

// 1. 定义顺序表结构体（顺序表的核心存储结构）
#define MAX_SIZE 100  // 顺序表最大容量（可根据需求调整）
typedef struct {
    int data[MAX_SIZE];  // 存储顺序表的元素（int类型，实验要求处理整数）
    int length;          // 顺序表当前的元素个数（初始为0）
} SeqList;  // 给结构体起别名SeqList，后续使用更简洁
// 函数功能：创建顺序表（从键盘读入元素）
// 参数：SL - 指向SeqList的指针（要操作的顺序表）
// 返回值：无（直接修改传入的顺序表）
void CreateSeqList(SeqList *SL) {
    int n, i;  // n：用户输入的元素个数；i：循环变量
    
    // 初始化顺序表（长度先置0）
    SL->length = 0;
    
    // 1. 读取用户输入的元素个数
    printf("请输入顺序表的元素个数（不超过%d）：", MAX_SIZE);
    scanf("%d", &n);
    
    // 合法性判断：避免元素个数超过最大容量
    if (n < 0 || n > MAX_SIZE) {
        printf("元素个数非法！\n");
        return;
    }
    
    // 2. 逐个读取元素，存入顺序表
    printf("请输入%d个整数（空格分隔）：", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(SL->data[i]));  // 将输入值存入data数组
        SL->length++;  // 每存一个元素，长度+1
    }
    
    // 3. 输出创建好的顺序表
    printf("创建的顺序表元素：");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}
// 函数功能：在顺序表指定位置插入元素
// 参数：SL - 指向SeqList的指针；pos - 插入位置（1-based，符合用户习惯）；value - 要插入的元素值
// 返回值：int - 1表示插入成功，0表示失败（位置非法/表满）

int InsertSeqList(SeqList *SL, int pos, int value) {
    int i;
    
    // 1. 合法性判断（插入位置必须在1~length+1之间，且表未满）
    if (pos < 1 || pos > SL->length + 1) {
        printf("插入位置非法！\n");
        return 0;
    }
    if (SL->length >= MAX_SIZE) {
        printf("顺序表已满，无法插入！\n");
        return 0;
    }
    
    // 2. 元素后移（从最后一个元素开始，到pos位置的前一个元素）
    // 注意：数组是0-based，pos转换为数组索引是pos-1
    for (i = SL->length; i >= pos; i--) {
        SL->data[i] = SL->data[i - 1];  // 后移1位
    }
    
    // 3. 插入新元素
    SL->data[pos - 1] = value;
    SL->length++;  // 长度+1
    
    // 4. 输出插入后的顺序表
    printf("插入后的顺序表元素：");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}
// 函数功能：删除顺序表指定位置的元素
// 参数：SL - 指向SeqList的指针；pos - 删除位置（1-based）
// 返回值：int - 1表示删除成功，0表示失败（位置非法）

int DeleteSeqList(SeqList *SL, int pos) {
    int i;
    
    // 1. 合法性判断（删除位置必须在1~length之间，且表非空）
    if (pos < 1 || pos > SL->length) {
        printf("删除位置非法！\n");
        return 0;
    }
    if (SL->length == 0) {
        printf("顺序表为空，无法删除！\n");
        return 0;
    }
    
    // 2. 元素前移（从pos位置开始，到最后一个元素的前一个）
    for (i = pos; i < SL->length; i++) {
        SL->data[i - 1] = SL->data[i];  // 前移1位
    }
    
    // 3. 长度-1（无需清空最后一个元素，后续操作会覆盖）
    SL->length--;
    
    // 4. 输出删除后的顺序表
    printf("删除后的顺序表元素：");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}

// 函数功能：统计顺序表中负数个数，并删除所有负数
// 参数：SL - 指向SeqList的指针
// 返回值：int - 统计的负数个数
int CountAndDeleteNegative(SeqList *SL) {
    int count = 0;  // 统计负数个数
    int i, j = 0;   // j：记录非负数的位置（新顺序表的索引）
    
    // 1. 遍历顺序表：统计负数+筛选非负数（覆盖原数组）
    for (i = 0; i < SL->length; i++) {
        if (SL->data[i] < 0) {
            count++;  // 遇到负数，计数+1
        } else {
            SL->data[j] = SL->data[i];  // 非负数存入j位置
            j++;  // j后移（非负数的个数）
        }
    }
    
    // 2. 更新顺序表长度（新长度=非负数个数=j）
    SL->length = j;
    
    // 3. 输出结果
    printf("顺序表中负数的个数：%d\n", count);
    printf("删除负数后的顺序表元素：");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return count;
}

// 函数功能：合并两个递增有序的顺序表A、B，生成递增有序的顺序表C
// 参数：A、B - 源顺序表（递增有序）；C - 目标顺序表（存储合并结果）
// 返回值：无（直接修改C）
void MergeSortedSeqList(SeqList A, SeqList B, SeqList *C) {
    int i = 0, j = 0, k = 0;  // i：A的索引；j：B的索引；k：C的索引
    
    // 1. 双指针合并（类似归并排序的合并步骤）
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {  // 取较小值（保持递增）
            C->data[k++] = A.data[i++];
        } else {
            C->data[k++] = B.data[j++];
        }
    }
    
    // 2. 处理A中剩余的元素
    while (i < A.length) {
        C->data[k++] = A.data[i++];
    }
    
    // 3. 处理B中剩余的元素
    while (j < B.length) {
        C->data[k++] = B.data[j++];
    }
    
    // 4. 更新C的长度
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
// 参数：SL - 有序顺序表（递增/递减均可）
// 返回值：double - 中位数（若长度为偶数，返回中间两个数的平均值）
double GetMedian(SeqList SL) {
    if (SL.length == 0) {
        printf("顺序表为空，无中位数！\n");
        return -1;  // 非法值标记
    }
    
    // 中位数计算逻辑：
    // - 长度为奇数：中间位置的元素（索引=length/2，整数除法）
    // - 长度为偶数：中间两个元素的平均值（索引=(length-1)/2 和 length/2）
    if (SL.length % 2 == 1) {
        return SL.data[SL.length / 2];  // 奇数：直接返回中间元素
    } else {
        int mid1 = SL.data[(SL.length - 1) / 2];
        int mid2 = SL.data[SL.length / 2];
        return (mid1 + mid2) / 2.0;  // 偶数：返回平均值（用2.0确保浮点数）
    }
}

// 函数功能：删除升序顺序表中的重复元素（每个元素只保留一次）
// 参数：SL - 指向升序顺序表的指针
// 返回值：无（直接修改原顺序表）
void RemoveDuplicates(SeqList *SL) {
    int i, j = 0;  // j：记录不重复元素的位置（新顺序表的索引）
    
    if (SL->length <= 1) {
        printf("顺序表元素个数≤1，无重复元素！\n");
        return;
    }
    
    // 1. 双指针去重（利用升序特性：重复元素必相邻）
    for (i = 1; i < SL->length; i++) {
        // 若当前元素与前一个不重复（j位置的元素），则存入j+1位置
        if (SL->data[i] != SL->data[j]) {
            j++;
            SL->data[j] = SL->data[i];
        }
    }
    
    // 2. 更新顺序表长度（不重复元素的个数=j+1）
    SL->length = j + 1;
    
    // 3. 输出去重后的顺序表
    printf("删除重复元素后的顺序表：");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList SL, A, B, C;  // SL：用于题目1-4、6；A、B、C：用于题目5
    int pos, value;        // 存储插入/删除的位置和插入值
    
    // -------------------------- 题目1：创建顺序表 --------------------------
    printf("=== 题目1：创建顺序表 ===\n");
    CreateSeqList(&SL);
    printf("\n");
    
    // -------------------------- 题目2：插入元素 --------------------------
    printf("=== 题目2：插入元素 ===\n");
    printf("请输入要插入的元素值和位置（用空格分隔）：");
    scanf("%d %d", &value, &pos);
    InsertSeqList(&SL, pos, value);
    printf("\n");
    
    // -------------------------- 题目3：删除元素 --------------------------
    printf("=== 题目3：删除元素 ===\n");
    printf("请输入要删除的元素位置：");
    scanf("%d", &pos);
    DeleteSeqList(&SL, pos);
    printf("\n");
    
    // -------------------------- 题目4：统计并删除负数 --------------------------
    printf("=== 题目4：统计并删除负数 ===\n");
    CountAndDeleteNegative(&SL);
    printf("\n");
    
    // -------------------------- 题目5：合并有序表+求中位数 --------------------------
    printf("=== 题目5：合并两个递增有序表+求中位数 ===\n");
    // 先创建两个递增有序的顺序表A和B（示例：A=[1,3,5], B=[2,4,6]）
    printf("创建递增有序表A：\n");
    CreateSeqList(&A);
    printf("创建递增有序表B：\n");
    CreateSeqList(&B);
    // 合并A和B到C
    MergeSortedSeqList(A, B, &C);
    // 求C的中位数
    double median = GetMedian(C);
    printf("合并后顺序表C的中位数：%.1f\n", median);
    printf("\n");
    
    // -------------------------- 题目6：删除重复元素 --------------------------
    printf("=== 题目6：删除升序表中的重复元素 ===\n");
    // 先确保SL是升序（若之前操作破坏了升序，可重新创建一个升序表，示例：[1,2,2,3,3,3]）
    printf("（若当前表非升序，先重新创建一个升序表）\n");
    CreateSeqList(&SL);
    RemoveDuplicates(&SL);
    printf("\n");
    
    return 0;
}

