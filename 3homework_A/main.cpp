/**素数环问题*/


#include <iostream>
#include <cstdio>
#include <cmath>
#include<cstring>
using namespace std;

int judge[25],ar[25];
int n;
/**素数判断*/
int prime(int sum)
{
    if(sum < 2)
        return 0;
    for(int i=2; i<=sqrt(sum); i++)
    {
        if(sum % i == 0)
            return 0;
    }
    return 1;
}


void dfs(int p)//第p位置应放什么书
{
    if(p==n&&prime(ar[p]+ar[1]))
    {
        for(int i=1; i<n; i++)
        {
            printf("%d ",ar[i]);
        }
        printf("%d\n",ar[n]);
    }
    if(p==n)
        return;
    for(int j=2; j<=n; j++)
    {
        if(!judge[j] && prime(ar[p]+j))
        {
            ar[p+1] = j;
            judge[j] = 1;
            dfs(p+1);
            judge[j] = 0;
        }
    }
}


int main()
{
    int s=0;
    while(~scanf("%d",&n))//-1取反是0，或者scanf("%d",&n)!=EOF,直接写scanf时间超限
    {
        s++;
        memset(judge,0,sizeof(judge));
        judge[1] = 1;
        ar[1] = 1;
        printf("Case %d:\n",s);
        dfs(1);
        printf("\n");
    }
    return 0;
}
