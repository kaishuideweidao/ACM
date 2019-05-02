#include <iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
/** Catch That Cow **/
/**90 280
22
15 36
4

9 1
8
10000 98765
2350
32165 99999
7168
50 50
0
*/
struct node
{
    int x;
    int v;
    int t;
};

int bfs(int n,int k)
{
    queue<node> s;
    while(!s.empty())
        s.pop();
    node temp[100005];
    int next;
    for(int i=1; i<100005; i++)
    {
        temp[i].t = 0;
        temp[i].x  =0;
        temp[i].v = 0;
    }
    temp[n].x = n;
    temp[n].v = 1;
    temp[n].t = 0;
    s.push(temp[n]);

    while(s.size()>0)
    {
        node p = s.front();
        s.pop();
        for(int i=0; i<3; i++)
        {
            if(i==0)
            {
                next = p.x - 1;
            }
            else if(i==1)
            {
                next = p.x+1;
            }
            else
            {
                next = 2 * p.x;
            }
            if(next<0 ||next >100005)
                continue;
            if(temp[next].v==0)
            {
                temp[next].x = next;
                temp[next].t = p.t+1;
                s.push(temp[next]);
                temp[next].v = 1;
            }
            if(next == k)
                return temp[next].t;
        }
    }
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        if(n>=k)
        {
            printf("%d\n",n-k);
        }
        else
        {
            printf("%d\n",bfs(n,k));

        }
    }

    return 0;
}

