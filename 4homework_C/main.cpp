#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int value[1005];
int vol[1005];
int just[1005][1005];
int N,V;
void d(int x)
{
    if(x==N+1)
    {
        return;
    }
    else
    {
        for(int i=0; i<=V; i++)         //考虑总体积为0，物品体积为0情况
        {
            if(i>=vol[x])
            {
                just[x][i] = max(just[x-1][i-vol[x]]+value[x],just[x-1][i]);

            }
            else
            {
                just[x][i] = just[x-1][i];
            }

        }
        d(++x);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>V;
        for(int i=1; i<=N; i++)
        {
            cin>>value[i];
        }
        for(int i=1; i<=N; i++)
        {
            cin>>vol[i];
        }
        memset(just,0,sizeof(just));            //不加初始化也通过，加后时间变长
        d(1);
//        for(int i=0;i<=N;i++)
//        {
//            for(int j=0;j<=V;j++)
//            {
//                cout<<just[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<just[N][V]<<endl;
    }
    return 0;
}
