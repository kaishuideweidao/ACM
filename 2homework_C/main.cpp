//It is very hard to wash and especially to dry clothes in winter. But Jane is a very smart girl.
//She is not afraid of this boring process. Jane has decided to use a radiator to make drying faster.
// But the radiator is small, so it can hold only one thing at a time.
//
//Jane wants to perform drying in the minimal possible time. She asked you to write a program that
// will calculate the minimal time for a given set of clothes.
//
//There are n clothes Jane has just washed. Each of them took ai water during washing. Every minute
//the amount of water contained in each thing decreases by one
//(of course, only if the thing is not completely dry yet). When amount of water contained becomes
//zero the cloth becomes dry and is ready to be packed.
//
//Every minute Jane can select one thing to dry on the radiator. The radiator is very hot, so the
//amount of water in this thing decreases by k this minute
//(but not less than zero — if the thing contains less than k water, the resulting amount of water
// will be zero).
//
//The task is to minimize the total time of drying by means of using the radiator effectively. The
//drying process ends when all the clothes are dry.
//
///**Input*/
//The first line contains a single integer n (1 ≤ n ≤ 100 000). The second line contains ai separated
//by spaces (1 ≤ ai ≤ 109). The third line contains k (1 ≤ k ≤ 109).
//
///**Output*/
//Output a single integer — the minimal possible number of minutes required to dry all clothes.

/**
*设将一件衣服弄干共需要x分钟，设烘干的时间为y，则自然干的时间为（x-y），
*将衣服弄干的条件即为k*y+（x-y）>= a [i]，化简为：y*（k-1）+x >= a[i],因此y = (a[i]-x)/(k-1)。
*ok函数用于测试总时间
*/
#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long  a[100005];
long long  b[100005];
long long N,k;
bool ok(long long t)
{
    long long ans = 0;
    for(int i=0; i<N; i++)
    {
        b[i] = a[i]-t;
    }
    for(int i=0; i<N; i++)
    {
        if(b[i]>0)
        {
            if(b[i]%(k-1)==0)
            {
                ans+=b[i]/(k-1);
            }
            else
            {
                ans+=b[i]/(k-1);
                ans++;
            }

        }
    }
    if(ans>t)               //使用烘干机时间>总时间
        return true;
    else
        return false;
}

int main()
{

    int i;
    long long sum=0;
    scanf("%lld",&N);//衣服数
//    printf("%d\n",N);
    for(i=0; i<N; i++)
    {
        scanf("%lld",&a[i]);
//        printf("%d\n",t);
//        q.push(t);
    }
    sort(a,a+N);
    while(scanf("%lld",&k)!=EOF)//每分钟烘干水量
//    printf("%d\n",k);
    {
        if(k==1)
        {
            printf("%lld",a[N-1]);
            continue;
        }
        long long st=0,mid,ed=a[N-1];
        while(st<ed-1)
        {
            mid = st+(ed-st)/2;
            if(ok(mid))
                st = mid;
            else
                ed = mid;
        }
        printf("%lld\n",ed);
    }

    return 0;
}
/******网上答案*******/

//设将一件衣服弄干共需要x分钟，设烘干的时间为y，则自然干的时间为（x-y），
//将衣服弄干的条件即为k*y+（x-y）>= a [i]，化简为：y*（k-1）+x >= a[i],因此y = (a[i]-x)/(k-1)。
//
//
//
//
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<string>
//#include<algorithm>
//#define maxn 100010
//#define LL long long
//using namespace std;
//
//LL a[maxn],b[maxn];
//LL n,k;
//bool ck(LL x)               //x估计总时间
//{
//    for(LL i=1; i<=n; ++i)
//        b[i] = a[i]-x;
//    LL cnt = 0;
//    for(LL i=1; i<=n; ++i)
//    {
//        if(b[i]>0)
//        {
//            if(b[i]%(k-1)==0)
//                cnt+=b[i]/(k-1);    //烘干时间y
//            else
//            {
//                cnt+=b[i]/(k-1);
//                cnt++;
//            }
//        }
//    }
//    if(cnt>x)
//        return true;        //烘干时间>总时间
//    else
//        return false;       //烘干时间<总时间
//}
//int main()
//{
//    while(scanf("%lld",&n)!=EOF)
//    {
//        for(LL i=1; i<=n; ++i)
//        {
//            scanf("%lld",&a[i]);
//        }
//        sort(a+1,a+1+n);
//        scanf("%lld",&k);
//        if(k==1)
//        {
//            printf("%lld\n",a[n]);
//            continue;
//        }
//        LL l=0,r=a[n],mid=0;
//        while(l<r-1)
//        {
//            mid = l+(r-l)/2;
//            if(ck(mid))
//            {
//                l = mid;
////                cout<<"a"<<l;
//            }
//            else
//            {
//                r = mid;
////                cout<<"b"<<r;
//            }
//        }
//        printf("%lld\n",r);
//    }
//    return 0;
//}
//
//
