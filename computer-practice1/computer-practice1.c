#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 100  //˳����������
typedef struct {
    int data[MAX_SIZE];  //�洢˳����Ԫ��
    int length;          //˳���Ԫ�ظ���
} SeqList;  // �ṹ�����SeqList

    //-------------------------- 1������˳����� --------------------------
    
//�������ܣ�����˳����Ӽ��̶���Ԫ�أ�
void CreateSL(SeqList *SL) 
{
    int n, i;  // n���û������Ԫ�ظ�����i��ѭ������
    
    SL->length = 0;         //��ʼ��˳���������0��

    printf("������˳����Ԫ�ظ�����");        //��ȡ�����Ԫ�ظ���
    scanf("%d", &n);        //�����ȡԪ�أ�����˳���
    
    printf("������%d���������ո�ָ�): ", n);
    
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &(SL->data[i]));  //������ֵ����data����
        SL->length++;  // ÿ��һ��Ԫ�أ�����+1
    }
    
    printf("������˳���Ԫ�أ�");        //���˳���
    
    for (i = 0; i < SL->length; i++)
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}

    // -------------------------- 2������Ԫ�غ��� --------------------------
    
// �������ܣ���˳���ָ��λ�ò���Ԫ��
int InsertSL(SeqList *SL, int pos1, int value) 
{
    int i;
    
    if (pos1 < 1 || pos1 > SL->length + 1)    //�жϲ���λ���Ƿ���1~length+1֮��
	{
        printf("����λ�ò�����\n");
        return 0;
    }
    if (SL->length >= MAX_SIZE)     //�жϱ��Ƿ�����
	{
        printf("˳����������޷����룡\n");
        return 0;
    }
    
    for (i = SL->length; i >= pos1; i--)    //�����һ��Ԫ�ص�posλ��ǰһ��Ԫ�غ���
	{
        SL->data[i] = SL->data[i - 1];    //����1λ
    }
    
    SL->data[pos1 - 1] = value;    //������Ԫ��
    SL->length++;   //����+1
    
    printf("������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    
    return 1;
}

    //-------------------------- 3��ɾ��Ԫ�غ��� --------------------------
    
//�������ܣ�ɾ��˳���ָ��λ�õ�Ԫ��
int DeleteSL(SeqList *SL, int pos2) 
{
    int i;
    

    if (pos2 < 1 || pos2 > SL->length)    //�ж�ɾ��λ���Ƿ���1~length֮�� 
	{
        printf("ɾ��λ�ò�����\n");
        return 0;
    }
    

    for (i = pos2; i < SL->length; i++)    //��posλ�õ����һ��Ԫ�ص�ǰһ��Ԫ��ǰ�� 
	{
        SL->data[i - 1] = SL->data[i];  // ǰ��1λ
    }
    
    SL->length--;       //����-1
    
    printf("ɾ�����˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) 
	{
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}

    //-------------------------- 4��ͳ�Ʋ�ɾ���������� --------------------------
    
//�������ܣ�ͳ��˳����и�����������ɾ�����и���
void CADNeg(SeqList *SL) 
{
    int i,j,count = 0;   //������������

    for (i=0; i < SL->length; ) 
	{
        if (SL->data[i] < 0)
		{ 
            count++;    //��������������+1
            for (j = i + 1; j < SL->length; j++) 
				{
			        SL->data[j - 1] = SL->data[j];    //ǰ��1λ
			    }
            SL->length--; 
		}
		else
			i++;
    }

    printf("˳����и����ĸ�����%d\n", count);
    printf("ɾ���������˳���Ԫ�أ�");
    
    for (i = 0; i < SL->length; i++) 
        printf("%d ", SL->data[i]);
        
    printf("\n");
}

    //-------------------------- 5���ϲ������+����λ������ --------------------------
    
//�������ܣ��ϲ��������������˳���A��B�����ɵ��������˳���C
void MergeSL(SeqList A, SeqList B, SeqList *C) 
{
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
double GetMedian(SeqList SL) 
{
    if (SL.length == 0) 
	{
        printf("˳���Ϊ�գ�����λ����\n");
        return -1;  // �Ƿ�ֵ���
    }
    if (SL.length % 2 == 1)     //����Ϊ����
	{
        return SL.data[SL.length / 2];  //����ֱ�ӷ����м�Ԫ�أ�"/"ȡ���� 
    } 
	else     //����Ϊż��
	{
        int mid1 = SL.data[(SL.length - 1) / 2];
        int mid2 = SL.data[SL.length / 2];
        return (mid1 + mid2) / 2.0;  // ż������ƽ��ֵ(������) 
    }
}

    //-------------------------- 6��ɾ���ظ�Ԫ�غ��� --------------------------

//�������ܣ�ɾ������˳����е��ظ�Ԫ�أ�ÿ��Ԫ��ֻ����һ�Σ�
void Remove(SeqList *SL) 
{
    int i, j = 0;  //j����¼���ظ�Ԫ�ص�λ�ã���˳����������
    
    if (SL->length <= 1) 
	{
        printf("˳���Ԫ�ظ�����1�����ظ�Ԫ�أ�\n");
        return;
    }

    // ȥ�أ������������ԣ��ظ�Ԫ�ر����ڣ�
    for (i = 1; i < SL->length; i++)    //i=1��֤������ڶ���Ԫ�ؿ�ʼ��ǰһλ����
	{

        if (SL->data[i] != SL->data[j])       // ����ǰԪ����ǰһ�����ظ�������j+1λ�� 
		{
            j++;
            SL->data[j] = SL->data[i];
        }
    }
    // ����˳����ȣ����ظ�Ԫ�صĸ���=j+1��
    SL->length = j + 1;
    
    printf("ɾ���ظ�Ԫ�غ��˳���");
    for (i = 0; i < SL->length; i++) 
        printf("%d ", SL->data[i]);
        
    printf("\n");
}


int main() 
{
    SeqList SL, A, B, C, D;  
    int pos1, value, pos2;    //pos1����Ԫ��λ��,value����Ԫ��ֵ,pos2ɾ��Ԫ��λ�� 
    

    printf("=== ��Ŀ1������˳��� ===\n");
    
    CreateSL(&SL);
    printf("\n");
    

    printf("=== ��Ŀ2������Ԫ�� ===\n");
    
    printf("������Ҫ�����Ԫ��ֵ��λ�ã��ÿո�ָ�����");
    scanf("%d %d", &value, &pos1);
    
    InsertSL(&SL, pos1, value);
    printf("\n");
    

    printf("=== ��Ŀ3��ɾ��Ԫ�� ===\n");
    
    printf("������Ҫɾ����Ԫ��λ�ã�");
    scanf("%d", &pos2);
    
    DeleteSL(&SL, pos2);
    printf("\n");
    

    printf("=== ��Ŀ4��ͳ�Ʋ�ɾ������ ===\n");
    
    CADNeg(&SL);
    printf("\n");
    

    printf("=== ��Ŀ5���ϲ��������������+����λ�� ===\n");

    printf("�������������A��\n");
    CreateSL(&A);
    
    printf("�������������B��\n");
    CreateSL(&B);

    MergeSL(A, B, &C);    //��A��B�ϲ�ΪC 
    double GM = GetMedian(C);     //��GM������λ�� 
    
    if (GM == -1) 
	{
    printf("����������һ�����������˳��������λ������");
    CreateSL(&D);
    GetMedian(D);
    } 
	else
    printf("�ϲ���˳���C��λ����%.1f\n", GM);

    printf("\n");
    
    
    printf("=== ��Ŀ6��ɾ��������е��ظ�Ԫ�� ===\n");

    Remove(&C);    //ȷ�������ִ��ȥ�ز���� 

    return 0;
}

