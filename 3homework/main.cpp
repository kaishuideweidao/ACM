//֩��ֽ������
/**
    ֩������windows xp����ϵͳ�Դ���һ��ֽ����Ϸ����Ϸ�����������ģ�
ֻ�ܽ����ϵ�������һ�������棨A��С��K��󣩣�����϶��������а�˳���źõ���ʱ��
��ô��Щ��Ҳ����һ���ƶ�����Ϸ��Ŀ���ǽ����е��ư�ͬһ��ɫ��С�����źã�Ϊ�˼������
���ǵ���Ϸֻ��ͬһ��ɫ��10���ƣ���A��10�����������һ����չ������Ŵ�1��10��
�ѵ�i���ϵ����Ƶ���j�����ϣ��ƶ�����Ϊabs(i-j)��������Ҫ��������������Ϸ����С�ƶ����롣
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
    if(sum>=ans)//�ƶ���Ŀ���ȥ
    return ;
    if(cnt == 9)//�ƶ���ɣ����ƶ��������
    {
        ans = sum;
        return ;
    }
    for(i = 1;i<10;i++)//ѡȡ�����ƶ�ֽ��
    {

        if(!vis[i])
        {
            vis[i] = 1;
            for(j = i+1;j<=10;j++)//Ŀ��λ��
            {
                if(!vis[j])
                {
                    dfs(cnt+1,sum+abs(a[i]-a[j]));//�ݹ�
                    break;
                }
            }
            vis[i] = 0;//���ݣ�ѡ������ֽ��
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
            a[x] = i;//����Ϊx�����ڵ�i��λ��
        }
        memset(vis,0,sizeof(vis));
        ans = 10000000;
        dfs(0,0);
        printf("%d\n",ans);
    }

    return 0;
}
