/*****�����ƽ���������**********/
#include <iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
#define NUM 100005


int main()
{
    int N,i,p;
    long long k;
    long long ans[NUM];
    long long count=0;
    while(scanf("%d%I64d",&N,&k)!=EOF)
    {
        for(i=0; i<N; i++)
        {
            scanf("%I64d",&ans[i]);
        }
        for(p=0; p<N; p++)
        {
            for(i=0; i<N-1; i++)
            {
                if(ans[i+1]<ans[i])
                {
                    swap(ans[i],ans[i+1]);
                    count++;
                }
            }
        }
        long long a = count-k;
        if(a<0)
            printf("%d\n",0);
        else
            printf("%I64d\n",a);

    }

    return 0;
}

/*****�鲢������������*****/
//#include <stdlib.h>
//#include <stdio.h>
//
//int Count;
//
//void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
//{
//    int i = startIndex, j=midIndex+1, k = startIndex;
//    while(i!=midIndex+1 && j!=endIndex+1)
//    {
//        if(sourceArr[i] > sourceArr[j])       //�������鶼������ģ���<ǰ���õ�������
//        {
//        	tempArr[k++] = sourceArr[j++];
//        	Count += midIndex - i + 1;
//        }
//        else
//            tempArr[k++] = sourceArr[i++];
//    }
//    while(i != midIndex+1)                    //�������ֱ�Ӽӵ�����
//        tempArr[k++] = sourceArr[i++];
//    while(j != endIndex+1)
//        tempArr[k++] = sourceArr[j++];
//    for(i=startIndex; i<=endIndex; i++)       //��ԭ�����޸�Ϊ�Ӽ�����
//        sourceArr[i] = tempArr[i];
//}
//
////�ڲ�ʹ�õݹ�
//void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
//{
//    int midIndex;
//    if(startIndex < endIndex)//��һ�������һ������ȵĻ�return������������
//    {
//        midIndex = (startIndex + endIndex) / 2;
//        MergeSort(sourceArr, tempArr, startIndex, midIndex);
//        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
//        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
//    }
//}
//
//int main(int argc, char * argv[])
//{
//    int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
//    int i, b[8];//��ʱ��������
//    MergeSort(a, b, 0, 7);
//    for(i=0; i<8; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//    printf("%d\n",Count);
//    return 0;
//}
