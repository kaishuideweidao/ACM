#include <iostream>

using namespace std;
#define MAX 10000
const int n = 3;
bool flag[n] = {true,true,true};

int findMin(int fm[n])                  //�ҵ���Сֵ�±�
{
    int minn = MAX,con = 0;
    for(int i=0; i<n; i++)
    {
        if(fm[i]<minn && flag[i]==true)
        {
            con = i;
            minn = fm[i];
        }
    }
    return con;
}

void dj(int arc[n][n], int dis[n][n])       //�Ͻܿ�˹���㷨
{
    int i, j, k=0, t, lin = 0, linc = 0, p=0;
    for(i=0; i<n; i++)                      //��ʼ������dis
    {
        for(j=0;j<n;j++)
        {
            dis[i][j] = arc[i][j];
        }
    }
    for(k=0; k<n; k++)                      //ÿ������Ϊ��ʼ��
    {
        flag[k] = false;                    //���ʹ�ù��ĵ�
        for(t=1; t<n ;t++)
        {
            int minn = findMin(dis[k]);     //�ҵ���Сֵ��
            flag[minn] = false;
            linc = dis[k][minn];            //Ŀǰ���·������
            lin = minn;                     //minnΪ�м�ڵ�
            for(p=0; p<n; p++)
            {
                if(flag[p]==false)
                    continue;
                if(dis[lin][p]+linc < dis[k][p])
                    dis[k][p] = dis[lin][p]+linc;
            }
        }
        for(int i=0;i<n;i++)
            flag[i] = true;
    }
}
int main()
{
    int arc[n][n] = {
        {0,4,11},
        {6,0,2},
        {3,1000000,0}
    };
    int dis[n][n];
    dj(arc,dis);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
