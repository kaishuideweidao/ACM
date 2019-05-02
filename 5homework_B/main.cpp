
//青蛙的约会（扩展欧几里得）
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
using namespace std;
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{    if(b==0){
        x=1;y=0;
        return a;
    }else{
        long long r=extend_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
int main()
{
　　 long long x,y,m,n,L;
    long long a,b,c,gcd;
    while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&L)!=EOF)
    {    a=m-n;
        b=L;
        c=y-x;
        if(a<0)
        {    a=-a;
            c=-c;
        }
        gcd=extend_gcd(a,b,x,y);
        if(c%gcd!=0)
            cout<<"Impossible"<<endl;
        else{
            x=x*c/gcd;
            int t=b/gcd;
            if(x>=0)
                x=x%t;
            else
                x=x%t+t;
            cout<<x<<endl;
        }
    }
    return 0;
}
