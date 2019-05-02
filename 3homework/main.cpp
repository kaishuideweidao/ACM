//蜘蛛纸牌问题
/**
    蜘蛛牌是windows xp操作系统自带的一款纸牌游戏，游戏规则是这样的：
只能将牌拖到比她大一的牌上面（A最小，K最大），如果拖动的牌上有按顺序排好的牌时，
那么这些牌也跟着一起移动，游戏的目的是将所有的牌按同一花色从小到大排好，为了简单起见，
我们的游戏只有同一花色的10张牌，从A到10，且随机的在一行上展开，编号从1到10，
把第i号上的牌移到第j号牌上，移动距离为abs(i-j)，现在你要做的是求出完成游戏的最小移动距离。
*/
#include <stdio.h>
#include <string.h>

int a[15],vis[15],ans;
int abs(int x)
{
    if(x<0)
    return -x;
    return x;
}
void dfs(int cnt,int sum)
{
    int i,j;
    if(sum>=ans)//移动数目大除去
    return ;
    if(cnt == 9)//移动完成，将移动次数输出
    {
        ans = sum;
        return ;
    }
    for(i = 1;i<10;i++)//选取本次移动纸牌
    {

        if(!vis[i])
        {
            vis[i] = 1;
            for(j = i+1;j<=10;j++)//目标位置
            {
                if(!vis[j])
                {
                    dfs(cnt+1,sum+abs(a[i]-a[j]));//递归
                    break;
                }
            }
            vis[i] = 0;//回溯，选择其他纸牌
        }
    }
}

int main()
{
    int t,i,x;
    scanf("%d",&t);
    while(t--)
    {
        for(i = 1;i<=10;i++)
        {
            scanf("%d",&x);
            a[x] = i;//牌面为x的牌在第i个位置
        }
        memset(vis,0,sizeof(vis));
        ans = 10000000;
        dfs(0,0);
        printf("%d\n",ans);
    }

    return 0;
}
