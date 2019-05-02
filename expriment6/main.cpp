#include <iostream>

using namespace std;

const int n = 4;        //图中顶点个数
void floyd(int a[n][n],int dis[n][n])
{
    int i, j, k;
    for(i = 0;i< n;i++)//初始化矩阵
    {
        for(j = 0;j<n;j++)
        {
            dis[i][j] = a[i][j];
        }
    }
    for(k=0;k<n;k++)//进行N次迭代
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j] = dis[i][k]+dis[k][j];
            }
        }
    }
}


int main()
{
    int a[4][4] = { {0,1,1000000,4},
                    {1,0,1,1000000},
                    {1000000,1,0,1},
                    {3,1000000,1,0} };
    int dis[4][4];
    floyd(a,dis);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
