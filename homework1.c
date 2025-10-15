#include <stdio.h>
#include <stdlib.h>  // �����ڴ���������ö�̬���飩

// 1. ����˳���ṹ�壨˳���ĺ��Ĵ洢�ṹ��
#define MAX_SIZE 100  // ˳�������������ɸ������������
typedef struct {
    int data[MAX_SIZE];  // �洢˳����Ԫ�أ�int���ͣ�ʵ��Ҫ����������
    int length;          // ˳���ǰ��Ԫ�ظ�������ʼΪ0��
} SeqList;  // ���ṹ�������SeqList������ʹ�ø����
// �������ܣ�����˳����Ӽ��̶���Ԫ�أ�
// ������SL - ָ��SeqList��ָ�루Ҫ������˳���
// ����ֵ���ޣ�ֱ���޸Ĵ����˳���
void CreateSeqList(SeqList *SL) {
    int n, i;  // n���û������Ԫ�ظ�����i��ѭ������
    
    // ��ʼ��˳�����������0��
    SL->length = 0;
    
    // 1. ��ȡ�û������Ԫ�ظ���
    printf("������˳����Ԫ�ظ�����������%d����", MAX_SIZE);
    scanf("%d", &n);
    
    // �Ϸ����жϣ�����Ԫ�ظ��������������
    if (n < 0 || n > MAX_SIZE) {
        printf("Ԫ�ظ����Ƿ���\n");
        return;
    }
    
    // 2. �����ȡԪ�أ�����˳���
    printf("������%d���������ո�ָ�����", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(SL->data[i]));  // ������ֵ����data����
        SL->length++;  // ÿ��һ��Ԫ�أ�����+1
    }
    
    // 3. ��������õ�˳���
    printf("������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}
// �������ܣ���˳���ָ��λ�ò���Ԫ��
// ������SL - ָ��SeqList��ָ�룻pos - ����λ�ã�1-based�������û�ϰ�ߣ���value - Ҫ�����Ԫ��ֵ
// ����ֵ��int - 1��ʾ����ɹ���0��ʾʧ�ܣ�λ�÷Ƿ�/������

int InsertSeqList(SeqList *SL, int pos, int value) {
    int i;
    
    // 1. �Ϸ����жϣ�����λ�ñ�����1~length+1֮�䣬�ұ�δ����
    if (pos < 1 || pos > SL->length + 1) {
        printf("����λ�÷Ƿ���\n");
        return 0;
    }
    if (SL->length >= MAX_SIZE) {
        printf("˳����������޷����룡\n");
        return 0;
    }
    
    // 2. Ԫ�غ��ƣ������һ��Ԫ�ؿ�ʼ����posλ�õ�ǰһ��Ԫ�أ�
    // ע�⣺������0-based��posת��Ϊ����������pos-1
    for (i = SL->length; i >= pos; i--) {
        SL->data[i] = SL->data[i - 1];  // ����1λ
    }
    
    // 3. ������Ԫ��
    SL->data[pos - 1] = value;
    SL->length++;  // ����+1
    
    // 4. ���������˳���
    printf("������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}
// �������ܣ�ɾ��˳���ָ��λ�õ�Ԫ��
// ������SL - ָ��SeqList��ָ�룻pos - ɾ��λ�ã�1-based��
// ����ֵ��int - 1��ʾɾ���ɹ���0��ʾʧ�ܣ�λ�÷Ƿ���

int DeleteSeqList(SeqList *SL, int pos) {
    int i;
    
    // 1. �Ϸ����жϣ�ɾ��λ�ñ�����1~length֮�䣬�ұ�ǿգ�
    if (pos < 1 || pos > SL->length) {
        printf("ɾ��λ�÷Ƿ���\n");
        return 0;
    }
    if (SL->length == 0) {
        printf("˳���Ϊ�գ��޷�ɾ����\n");
        return 0;
    }
    
    // 2. Ԫ��ǰ�ƣ���posλ�ÿ�ʼ�������һ��Ԫ�ص�ǰһ����
    for (i = pos; i < SL->length; i++) {
        SL->data[i - 1] = SL->data[i];  // ǰ��1λ
    }
    
    // 3. ����-1������������һ��Ԫ�أ����������Ḳ�ǣ�
    SL->length--;
    
    // 4. ���ɾ�����˳���
    printf("ɾ�����˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return 1;
}

// �������ܣ�ͳ��˳����и�����������ɾ�����и���
// ������SL - ָ��SeqList��ָ��
// ����ֵ��int - ͳ�Ƶĸ�������
int CountAndDeleteNegative(SeqList *SL) {
    int count = 0;  // ͳ�Ƹ�������
    int i, j = 0;   // j����¼�Ǹ�����λ�ã���˳����������
    
    // 1. ����˳���ͳ�Ƹ���+ɸѡ�Ǹ���������ԭ���飩
    for (i = 0; i < SL->length; i++) {
        if (SL->data[i] < 0) {
            count++;  // ��������������+1
        } else {
            SL->data[j] = SL->data[i];  // �Ǹ�������jλ��
            j++;  // j���ƣ��Ǹ����ĸ�����
        }
    }
    
    // 2. ����˳����ȣ��³���=�Ǹ�������=j��
    SL->length = j;
    
    // 3. ������
    printf("˳����и����ĸ�����%d\n", count);
    printf("ɾ���������˳���Ԫ�أ�");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
    return count;
}

// �������ܣ��ϲ��������������˳���A��B�����ɵ��������˳���C
// ������A��B - Դ˳����������򣩣�C - Ŀ��˳����洢�ϲ������
// ����ֵ���ޣ�ֱ���޸�C��
void MergeSortedSeqList(SeqList A, SeqList B, SeqList *C) {
    int i = 0, j = 0, k = 0;  // i��A��������j��B��������k��C������
    
    // 1. ˫ָ��ϲ������ƹ鲢����ĺϲ����裩
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {  // ȡ��Сֵ�����ֵ�����
            C->data[k++] = A.data[i++];
        } else {
            C->data[k++] = B.data[j++];
        }
    }
    
    // 2. ����A��ʣ���Ԫ��
    while (i < A.length) {
        C->data[k++] = A.data[i++];
    }
    
    // 3. ����B��ʣ���Ԫ��
    while (j < B.length) {
        C->data[k++] = B.data[j++];
    }
    
    // 4. ����C�ĳ���
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
double GetMedian(SeqList SL) {
    if (SL.length == 0) {
        printf("˳���Ϊ�գ�����λ����\n");
        return -1;  // �Ƿ�ֵ���
    }
    
    // ��λ�������߼���
    // - ����Ϊ�������м�λ�õ�Ԫ�أ�����=length/2������������
    // - ����Ϊż�����м�����Ԫ�ص�ƽ��ֵ������=(length-1)/2 �� length/2��
    if (SL.length % 2 == 1) {
        return SL.data[SL.length / 2];  // ������ֱ�ӷ����м�Ԫ��
    } else {
        int mid1 = SL.data[(SL.length - 1) / 2];
        int mid2 = SL.data[SL.length / 2];
        return (mid1 + mid2) / 2.0;  // ż��������ƽ��ֵ����2.0ȷ����������
    }
}

// �������ܣ�ɾ������˳����е��ظ�Ԫ�أ�ÿ��Ԫ��ֻ����һ�Σ�
// ������SL - ָ������˳����ָ��
// ����ֵ���ޣ�ֱ���޸�ԭ˳���
void RemoveDuplicates(SeqList *SL) {
    int i, j = 0;  // j����¼���ظ�Ԫ�ص�λ�ã���˳����������
    
    if (SL->length <= 1) {
        printf("˳���Ԫ�ظ�����1�����ظ�Ԫ�أ�\n");
        return;
    }
    
    // 1. ˫ָ��ȥ�أ������������ԣ��ظ�Ԫ�ر����ڣ�
    for (i = 1; i < SL->length; i++) {
        // ����ǰԪ����ǰһ�����ظ���jλ�õ�Ԫ�أ��������j+1λ��
        if (SL->data[i] != SL->data[j]) {
            j++;
            SL->data[j] = SL->data[i];
        }
    }
    
    // 2. ����˳����ȣ����ظ�Ԫ�صĸ���=j+1��
    SL->length = j + 1;
    
    // 3. ���ȥ�غ��˳���
    printf("ɾ���ظ�Ԫ�غ��˳���");
    for (i = 0; i < SL->length; i++) {
        printf("%d ", SL->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList SL, A, B, C;  // SL��������Ŀ1-4��6��A��B��C��������Ŀ5
    int pos, value;        // �洢����/ɾ����λ�úͲ���ֵ
    
    // -------------------------- ��Ŀ1������˳��� --------------------------
    printf("=== ��Ŀ1������˳��� ===\n");
    CreateSeqList(&SL);
    printf("\n");
    
    // -------------------------- ��Ŀ2������Ԫ�� --------------------------
    printf("=== ��Ŀ2������Ԫ�� ===\n");
    printf("������Ҫ�����Ԫ��ֵ��λ�ã��ÿո�ָ�����");
    scanf("%d %d", &value, &pos);
    InsertSeqList(&SL, pos, value);
    printf("\n");
    
    // -------------------------- ��Ŀ3��ɾ��Ԫ�� --------------------------
    printf("=== ��Ŀ3��ɾ��Ԫ�� ===\n");
    printf("������Ҫɾ����Ԫ��λ�ã�");
    scanf("%d", &pos);
    DeleteSeqList(&SL, pos);
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
    double median = GetMedian(C);
    printf("�ϲ���˳���C����λ����%.1f\n", median);
    printf("\n");
    
    // -------------------------- ��Ŀ6��ɾ���ظ�Ԫ�� --------------------------
    printf("=== ��Ŀ6��ɾ��������е��ظ�Ԫ�� ===\n");
    // ��ȷ��SL��������֮ǰ�����ƻ������򣬿����´���һ�������ʾ����[1,2,2,3,3,3]��
    printf("������ǰ������������´���һ�������\n");
    CreateSeqList(&SL);
    RemoveDuplicates(&SL);
    printf("\n");
    
    return 0;
}

