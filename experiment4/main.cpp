#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int str[10];

//����
int Partition(int str[],int first,int end)
{
    int i = first, j = end;
    while(i<j)
    {
        while(i<j && str[i]<str[j])//��ɨ��
        {
            j--;
        }
        if(i<j)
        {
            swap(str[i++],str[j]);//Сֵ��ǰ��
        }
        while(i<j && str[i]<str[j])//��ɨ��
        {
            i++;
        }
        if(i<j)
        {
            swap(str[i],str[j--]);//��ֵ�ź���
        }
    }
    return i;
}
//���ѡȡ��ֵ
int Random(int str[],int first,int end)
{
    int RandomNum = rand()%(end-first+1)+first;
    swap(str[first],str[RandomNum]);
    Partition(str,first,end);
}
//��������
void QuickSort(int str[],int first,int end)
{
    int AxialValue;
    if(first < end)
    {
        AxialValue = Random(str,first,end);
        QuickSort(str,first,AxialValue-1);
        QuickSort(str,AxialValue+1,end);
    }
}
int main()
{
    int i, j;
    char s;                             //�����Ƿ����
    for(i=0; i<100 && s != '\n'; i++)
    {
        cin>>str[i];
        s = getchar();
    }
    QuickSort(str,0,i-1);
    for(int j=0;j<=i-1;j++)
    {
        cout<<str[j]<<" ";
    }
    return 0;
}
