#include <iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>           //输出格式
using namespace std;

int pay[10005];
double ch[10005];
double j[10005];//使用二位数组标记内存超限
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
//        memset(j,1.0,sizeof(j));////只能初始化为整数


        for(int x=0; x<m; x++)
        {

            for(int i=n; i>=pay[x]; i--)//从后向前，避免覆盖
            {
                    j[i] = min(j[i],f(j[i-pay[x]],ch[x]));
            }
        }
        cout<<fixed<<setprecision(1)<<(1-j[n])*100<<'%'<<endl;//fixed和etprecision连用表示小数点后保留位数
    }


//    printf("%0.1f%%\n",j[m][n]*100);//c语言输出表示
    return 0;
}
