#include <iostream>
using namespace std;

void deleteCount(int k,int con)
{
    int str[20];
    int i=0;
    while(con>0)              //�����ַֽ�
    {
        str[i] = con%10;
        i++;
        con = con/10;
    }
    int t = i;              //�������ָ���
    for(int j=0; j<i; j++,i--) //����
    {
        swap(str[j],str[i-1]);
    }
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<t; j++)
        {
            if(str[j] == -1)//����-1
                continue;
            if(str[j] > str[j+1] || j == t-1)        //ɾ���ݼ����е�һ�������ǵݼ��������һ����
            {
                str[j] = -1;
                break;
            }
        }
    }
    for(int i=0; i<t; i++)
    {
        if(str[i] != -1)
        {
            cout<<str[i];
        }
    }
}

int main()
{
    int n, k;
    cin>>n>>k;
    deleteCount(k,n);
    return 0;
}
