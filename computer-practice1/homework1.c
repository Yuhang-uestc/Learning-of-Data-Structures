#include <stdio.h>
#include <stdlib.h> 

// ����˳���ṹ��
#define MAX_SIZE 100  // ˳�������������ɸ������������
typedef struct {
    int data[MAX_SIZE];  // �洢˳����Ԫ��
    int length;          // ˳���ǰ��Ԫ�ظ�������ʼΪ0��
} SeqList;  // ���ṹ�������SeqList������ʹ�ø����

// �������ܣ�����˳����Ӽ��̶���Ԫ�أ�
// ������SL :ָ��SeqList��ָ�루Ҫ������˳���
void CreateSeqList(SeqList *SL) 
{
    int n, i;  // n���û������Ԫ�ظ�����i��ѭ������
    
    // ��ʼ��˳�����������0��
    SL->length = 0;
    // ��ȡ�����Ԫ�ظ���
    printf("������˳����Ԫ�ظ�����");
    scanf("%d", &n);
    
    // �����ȡԪ�أ�����˳���
    printf("������%d���������ո�ָ�): ", n);
    
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &(SL->data[i]));  // ������ֵ����data����
        SL->length++;  // ÿ��һ��Ԫ�أ�����+1
    }
    
    // ���˳���
    printf("������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++)
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}

// �������ܣ���˳���ָ��λ�ò���Ԫ��
// ������SL :ָ��SeqList��ָ�룻pos :����λ�ã�1-based�������û�ϰ�ߣ���value :Ҫ�����Ԫ��ֵ
// ����ֵ��int - 1��ʾ����ɹ���0��ʾʧ�ܣ�λ�÷Ƿ�/������
int InsertSeqList(SeqList *SL, int pos1, int value) 
{
    int i;
    
    // �жϲ���λ���Ƿ���1~length+1֮�䣬�ұ�δ��
    if (pos1 < 1 || pos1 > SL->length + 1)
	{
        printf("����λ�ò�����\n");
        return 0;
    }
    if (SL->length >= MAX_SIZE) 
	{
        printf("˳����������޷����룡\n");
        return 0;
    }
    
    // Ԫ�غ��ƣ������һ��Ԫ�ؿ�ʼ����posλ�õ�ǰһ��Ԫ�أ�
    for (i = SL->length; i >= pos1; i--) {
        SL->data[i] = SL->data[i - 1];  // ����1λ
    }
    
    // ������Ԫ��
    SL->data[pos1 - 1] = value;
    SL->length++;  // ����+1
    
    // ���������˳���
    printf("������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}

// �������ܣ�ɾ��˳���ָ��λ�õ�Ԫ��
// ������SL :ָ��SeqList��ָ�룻pos :ɾ��λ�ã�1-based��
int DeleteSeqList(SeqList *SL, int pos2) 
{
    int i;
    
    // �ж�ɾ��λ���Ƿ���1~length֮��
    if (pos2 < 1 || pos2 > SL->length) 
	{
        printf("ɾ��λ�ò�����\n");
        return 0;
    }
    
    // Ԫ��ǰ�ƣ���posλ�ÿ�ʼ�������һ��Ԫ�ص�ǰһ����
    for (i = pos2; i < SL->length; i++) 
	{
        SL->data[i - 1] = SL->data[i];  // ǰ��1λ
    }
    
    SL->length--;       // ����-1
    
    // ���ɾ�����˳���
    printf("ɾ�����˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}

// �������ܣ�ͳ��˳����и�����������ɾ�����и���
// ������SL - ָ��SeqList��ָ��
void CountAndDeleteNegative(SeqList *SL) 
{
    int i,j,count = 0;  // ������������
    
    // ����˳���
    for (i=0; i < SL->length; ) 
	{
        if (SL->data[i] < 0)
		{ 
            count++;  // ��������������+1
            for (j = i + 1; j < SL->length; j++) 
				{
			        SL->data[j - 1] = SL->data[j];  // ǰ��1λ
			    }
            SL->length--; 
		}
		else
			i++;
    }
    // ������
    printf("˳����и����ĸ�����%d\n", count);
    printf("ɾ���������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) 
        printf("%d ", SL->data[i]);
    printf("\n");
}

// �������ܣ��ϲ��������������˳���A��B�����ɵ��������˳���C
// ������A��B - Դ˳����������򣩣�C - Ŀ��˳����洢�ϲ������
// ����ֵ���ޣ�ֱ���޸�C��
void MergeSortedSeqList(SeqList A, SeqList B, SeqList *C) {
    int i = 0, j = 0, k = 0;  // i��A��������j��B��������k��C������
    
    while (i < A.length && j < B.length) 
	{
        if (A.data[i] <= B.data[j]) 
            C->data[k++] = A.data[i++];
		else
            C->data[k++] = B.data[j++];
    }
    
    // ����A��ʣ���Ԫ��
    while (i < A.length) 
	{
        C->data[k++] = A.data[i++];
    }
    // ����B��ʣ���Ԫ��
    while (j < B.length) {
        C->data[k++] = B.data[j++];
    }
    // ����C�ĳ���
    C->length = k;
    
    // 5. ����ϲ����˳���
    printf("�ϲ��������˳���C��");
    for (int m = 0; m < C->length; m++) 
    {
        printf("%d ", C->data[m]);
    }
    printf("\n");
}

// �������ܣ�������˳������λ��
// ������SL - ����˳�������/�ݼ����ɣ�
// ����ֵ��double - ��λ����������Ϊż���������м���������ƽ��ֵ��
double GetMedian(SeqList SL) 
{
    if (SL.length == 0) 
	{
        printf("˳���Ϊ�գ�����λ����\n");
        return -1;  // �Ƿ�ֵ���
    }
    // ��λ�������߼���
    // - ����Ϊ�������м�λ�õ�Ԫ�أ�����=length/2������������
    // - ����Ϊż�����м�����Ԫ�ص�ƽ��ֵ������=(length-1)/2 �� length/2��
    if (SL.length % 2 == 1) 
	{
        return SL.data[SL.length / 2];  // ������ֱ�ӷ����м�Ԫ��
    } 
	else 
	{
        int mid1 = SL.data[(SL.length - 1) / 2];
        int mid2 = SL.data[SL.length / 2];
        return (mid1 + mid2) / 2.0;  // ż��������ƽ��ֵ����2.0ȷ����������
    }
}

// ���ܣ��ж�˳���SL�Ƿ�Ϊ���򣨷ǵݼ���
// ������SL - ָ��Ҫ�жϵ�˳����ָ��
// ����ֵ��1�����򣩡�0�������򣩡�-1���ձ����⴦��
int IsAscending(SeqList *SL) 
{
    // �߽����1���ձ��ֻ��1��Ԫ�أ�Ĭ��������
    if (SL->length <= 1)
        return 1;
    // ��������Ԫ�أ�����Ƿ����㡰ǰ <= �󡱣��ǵݼ�������ʵ���С��������򡱵ĳ������壩
    for (int i = 0; i < SL->length - 1; i++) 
	{
        // ������ǰԪ�� > ��Ԫ�أ�ֱ�ӷ��ط�����
        if (SL->data[i] > SL->data[i + 1]) 
            return 0;
    }
    // �����������쳣����������
    return 1;
}

// ���ܣ���˳���SL������������
void SortSeqList(SeqList *SL) 
{
    int i, j, temp;
    // �������򣺴ӵ�2��Ԫ�ؿ�ʼ��i=1������ǰ���뵽����λ��
    for (i = 1; i < SL->length; i++)
   {
        temp = SL->data[i]; // ������Ԫ��
        j = i - 1;
        // ��ǰ�ұ�temp���Ԫ�أ����κ���
        while (j >= 0 && SL->data[j] > temp) {
            SL->data[j + 1] = SL->data[j];
            j--;
        }
        // ����temp����ȷλ��
        SL->data[j + 1] = temp;
    }
}

// �������ܣ�ɾ������˳����е��ظ�Ԫ�أ�ÿ��Ԫ��ֻ����һ�Σ�
// ������SL - ָ������˳����ָ��
void RemoveDuplicates(SeqList *SL) 
{
    int i, j = 0;  // j����¼���ظ�Ԫ�ص�λ�ã���˳����������
    
    if (SL->length <= 1) 
	{
        printf("˳���Ԫ�ظ�����1�����ظ�Ԫ�أ�\n");
        return;
    }

    // ȥ�أ������������ԣ��ظ�Ԫ�ر����ڣ�
    for (i = 1; i < SL->length; i++) 
	{
        // ����ǰԪ����ǰһ�����ظ���jλ�õ�Ԫ�أ��������j+1λ��
        if (SL->data[i] != SL->data[j]) 
		{
            j++;
            SL->data[j] = SL->data[i];
        }
    }
    
    // ����˳����ȣ����ظ�Ԫ�صĸ���=j+1��
    SL->length = j + 1;
    
    // ���ȥ�غ��˳���
    printf("ɾ���ظ�Ԫ�غ��˳���");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}


int main() 
{
    SeqList SL, A, B, C;  // SL��������Ŀ1-4��6��A��B��C��������Ŀ5
    int pos1,pos2,value;        // �洢����/ɾ����λ�úͲ���ֵ
    
    // -------------------------- ��Ŀ1������˳��� --------------------------
    printf("=== ��Ŀ1������˳��� ===\n");
    CreateSeqList(&SL);
    printf("\n");
    
    // -------------------------- ��Ŀ2������Ԫ�� --------------------------
    printf("=== ��Ŀ2������Ԫ�� ===\n");
    printf("������Ҫ�����Ԫ��ֵ��λ�ã��ÿո�ָ�����");
    scanf("%d %d", &value, &pos1);
    InsertSeqList(&SL, pos1, value);
    printf("\n");
    
    // -------------------------- ��Ŀ3��ɾ��Ԫ�� --------------------------
    printf("=== ��Ŀ3��ɾ��Ԫ�� ===\n");
    printf("������Ҫɾ����Ԫ��λ�ã�");
    scanf("%d", &pos2);
    DeleteSeqList(&SL, pos2);
    printf("\n");
    
    // -------------------------- ��Ŀ4��ͳ�Ʋ�ɾ������ --------------------------
    printf("=== ��Ŀ4��ͳ�Ʋ�ɾ������ ===\n");
    CountAndDeleteNegative(&SL);
    printf("\n");
    
    // -------------------------- ��Ŀ5���ϲ������+����λ�� --------------------------
    printf("=== ��Ŀ5���ϲ��������������+����λ�� ===\n");
    // �ȴ����������������˳���A��B��ʾ����A=[1,3,5], B=[2,4,6]��
    printf("�������������A��\n");
    CreateSeqList(&A);
    printf("�������������B��\n");
    CreateSeqList(&B);
    // �ϲ�A��B��C
    MergeSortedSeqList(A, B, &C);
    // ��C����λ��
    double M = GetMedian(C);
    printf("�ϲ���˳���C����λ����%.1f\n", M);
    printf("\n");
    
    // -------------------------- ��Ŀ6��ɾ���ظ�Ԫ�� --------------------------
    printf("=== ��Ŀ6��ɾ��������е��ظ�Ԫ�� ===\n");
        // ���жϵ�ǰSL�Ƿ�Ϊ����
    if (IsAscending(&SL)) 
	{
        printf("��ǰ˳���Ϊ����ֱ��ִ��ȥ�ز���\n");
    } 
    else
	{
        SortSeqList(&SL);
    }
    // ȷ�������ִ��ȥ�ز���� 
    RemoveDuplicates(&SL);
    
    return 0;
}

