#include <iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>           //�����ʽ
using namespace std;

int pay[10005];
double ch[10005];
double j[10005];//ʹ�ö�λ�������ڴ泬��
int n,m;

double min(double a,double b)
{
    if(a>b)
        return b;
    else
        return a;
}
double  f(double a,double b)
{
    return a*b;
}

int main()
{

    int i=0;
    double t;

    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        for(int i=0; i<m; i++)
        {

            cin>>pay[i]>>ch[i];
            ch[i] = 1.0-ch[i];
        }
        for(int i=0;i<=n;i++)
        {
            j[i] = 1.0;
        }
//        memset(j,1.0,sizeof(j));////ֻ�ܳ�ʼ��Ϊ����


        for(int x=0; x<m; x++)
        {

            for(int i=n; i>=pay[x]; i--)//�Ӻ���ǰ�����⸲��
            {
                    j[i] = min(j[i],f(j[i-pay[x]],ch[x]));
            }
        }
        cout<<fixed<<setprecision(1)<<(1-j[n])*100<<'%'<<endl;//fixed��etprecision���ñ�ʾС�������λ��
    }


//    printf("%0.1f%%\n",j[m][n]*100);//c���������ʾ
    return 0;
}
