#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

__int64 v[100000];          //n=50ʱint����
//__int64 ar[100000];       //���Ҫ�������
int k=2;                //�����ظ�����
void fib(int n,int k)
{

    for(int i=k; i<=n; i++)//֮ǰ�Ķ���������Բ��ø���
    {
        v[i] = v[i-1]+v[i-2];
//        v[i-2] = v[i-1];
//        v[i-1] = v[i];
    }
}

int main()
{
    int s,count=0;
    v[0] = 0;
    v[1] = 1;
    cin>>s;
    while(s!=-1)
    {
        if(s==0||s==1)
            cout<<s<<endl;
//            ar[count++] = s;
        else
        {
            if(k>s)
//                ar[count++] = v[s];
                cout<<v[s]<<endl;
            else//k<s
            {
                fib(s,k);
                k = s+1;
                cout<<v[s]<<endl;
//                ar[count++] = v[s];
            }
        }

        cin>>s;
    }
//    for(int i=0; i<count; i++)
//    {
//        cout<<ar[i]<<endl;
//    }
    return 0;
}

//12586269025
