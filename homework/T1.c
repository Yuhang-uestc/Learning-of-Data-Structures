#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct {
	int data[Maxsize];
	int length;
}Seqlist;

void Remove(Seqlist *SL)
{
	int i,j =0;
	if(SL->length <= 1)
	{
		printf("元素个数小于等于1，无重复元素！");
		return; 
	}
	for(i=1;i<SL->length;i++)
	{
		if(SL->data[i] != SL->data[j])
		{
			j++;
			SL->data[j] = SL->data[i];
		}
	}
	SL->length = j+1;
	for(i=0;i < SL->length;i++)
	{
		printf("%d ",SL->data[i]);
	}
}
int main()
{
	Seqlist SL={{1,2,2,3,3,4,5,5},8};
	Remove(&SL);
}
