#include <iostream>
#include<cmath>
using namespace std;

//int s[10005];

//int mod(int a,int b)//最大公约数
//{
//    if(b==0)
//        return a;
//    else
//    {
//        if(a>b)
//            mod(b,a-b);
//        else
//            mod(a,b-a);
//    }
//}
//
//int PrimeNum(int a)//计算从1到a与 a 公约数 只有1的数 个数
//{
//    int count=0;
//    for(int i=1;i<a;i++)
//    {
//        if(mod(i,a)==1)
//            count++;
//    }
//    return count;
//}
bool jus(int a)
{
    if(a==2)
        return true;
    int  i;
    for(i=2;i<sqrt(a);i++)
    {
        if(a%i==0)
            break;
    }
    if(i<=sqrt(a))
        return false;
    else
        return true;
}
int main()
{
    long long n;
    cin>>n;
    long long k;
    for(k=1;k<=n;k++)
    {
        long long a;
        cin>>a;
        long long sum=0;
        long long count;
        for(int i=1; i<=a; i++)
        {
            cin>>count;
            while(!jus(++count));
            sum+=count;
        }
        cout<<"Case "<<k<<": "<<sum<<" Xukha"<<endl;
    }
    return 0;
}
