#include <iostream>
#include <stack>
using namespace std;

int s[10][10];
struct
{
    int x;
    int y;
} v[81];
int num,ok;

int isok(int i,int n)
{
    for(int j=1; j<10; j++)
    {
        if(s[v[n].x][j]==i || s[j][v[n].y]==i)
            return 0;
    }
    int x = (v[n].x%3==0)?v[n].x/3*3-2:v[n].x/3*3+1;
    int y = (v[n].y%3==0)?v[n].y/3*3-2:v[n].y/3*3+1;
//    int x = v[n].x/3?v[n].x/3:v[n].x/3*3+1;
//    int y = v[n].y/3?v[n].y/3:v[n].y/3*3+1;
//    cout<<x<<" "<<y<<endl;
    for(int j=0; j<3; j++)
    {
        for(int k=0; k<3; k++)
        {
            if(s[x+j][y+k] == i)
                return 0;
        }
    }
    return 1;
}


void dfs(int n)
{
    if(n == num)
    {
        for(int i=1; i<10; i++)
        {

            for(int j=1; j<9; j++)
            {
                cout<<s[i][j]<<" ";
            }
                        cout<<s[i][9];
            cout<<endl;
        }
//        cout<<endl;
        ok=1;
        return;
    }
    else
    {
        for(int i=1; i<10; i++)
        {
            if(isok(i,n)&&!ok)
            {
                s[v[n].x][v[n].y] = i;
                dfs(n+1);
                s[v[n].x][v[n].y] = 0;
            }

        }
    }
    return;
}
int main()
{
    int i=1,j=1;
    char a;
    int cas=0;
    while(cin>>a)
    {
        num=0;
        if(a=='?')
            s[i][j] = 0;
        else
            s[i][j] = a-'0';
        for(i=1; i<10; i++)
        {
            for(j=1; j<10; j++)
            {
                if(!(i==1&&j==1))
                {
                    cin>>a;
                }
                if(a=='?')
                {
                    s[i][j] = 0;
                    v[num].x = i;
                    v[num].y = j;
                    num++;
                }
                else
                    s[i][j] = a-'0';
            }
        }
        ok=0;
           if(cas++)cout<<endl;
        dfs(0);
    }

    return 0;
}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//int map[9][9];
//int num,ok;
//struct node
//{
//    int x,y;
//}q[81];
//bool check(int k,int cur)//判断所填的数是否合法 k为准备要填的数，cur为要填的位置在q中的编号
//{
//     for(int i=0;i<9;i++)
//     {
//         if(map[q[cur].x][i]==k||map[i][q[cur].y]==k)return 0;//判断行和列是否用过k
//     }
//     int x=q[cur].x/3*3;
//     int y=q[cur].y/3*3;
//     for(int i=0;i<3;i++)//判断9个格子的小块是否用过k
//         for(int j=0;j<3;j++)
//         {
//             if(map[x+i][y+j]==k)return 0;
//         }
//
//     return 1;
//}
//void DFS(int cur)
//{
//    if(cur==num)//数独表形成
//    {
//         for(int i=0;i<9;i++)//注意应该在这个位置就马上打印 否则回溯掉 表就没了
//         {
//           for(int j=0;j<8;j++)
//           {
//               printf("%d ",map[i][j]);
//           }
//           printf("%d\n",map[i][8]);
//         }
//        ok=1;
//        return;
//    }
//    else
//    {
//        for(int i=1;i<=9;i++)
//        {
//            if(check(i,cur)&&!ok)//填的数合法且最终答案还未形成
//            {
//                map[q[cur].x][q[cur].y]=i;//填表
//                DFS(cur+1);//递归
//                map[q[cur].x][q[cur].y]=0;//回溯
//            }
//        }
//    }
//    return;
//}
//int main()
//{
//    char s;
//    int cas=0;
//    while(cin>>s)
//    {
//        num=0;
//        if(s=='?')map[0][0]=0;
//        else map[0][0]=s-'0';
//        for(int i=0;i<9;i++)
//           for(int j=0;j<9;j++)
//           {
//               if(!(i==0&&j==0))cin>>s;
//               if(s=='?')
//               {
//                   map[i][j]=0;
//                   q[num].x=i;q[num].y=j;//把问号格子的坐标存在q里
//                   num++;
//               }
//               else map[i][j]=s-'0';
//           }
//           ok=0;
//           if(cas++)printf("\n");
//       DFS(0);
//
//
//    }
//}
