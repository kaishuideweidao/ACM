/**Oil Deposits **/

#include <iostream>
#include<cstdio>

using namespace std;

char ar[105][105];
int m,n;
int dirc[8][2] =
{
    {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}//·½Ïò
};

void dfs(int x,int y)
{
    int new_x,new_y;
    for(int i=0;i<8;i++)
    {
        new_x = x+dirc[i][0];
        new_y = y+dirc[i][1];
    if(new_x>=1&&new_x<=m&&new_y>=0&&new_y<=n&&ar[new_x][new_y]=='@')
    {
        ar[new_x][new_y] = '*';
        dfs(new_x,new_y);
    }
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n)&&m)
    {

        int sum=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%s",&ar[i]);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ar[i][j] == '@')
                {
                    sum++;
                    ar[i][j] = '*';
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
