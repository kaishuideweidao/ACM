#include <iostream>
#include<cmath>
using namespace std;

int board[5][5];
int t = 0;//编号

void ChessBoard(int tr, int tc, int dr, int dc, int size)//子棋盘坐标，特殊方格，子棋盘大小
{
    int s, t1;
    if(size == 1)
        return;
    t1 = ++t;
    s = size / 2;
    if(dr < tr+s && dc <tc+s)//左上
    {
        ChessBoard(tr,tc,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s-1] = t1;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr < tr+s && dc >= tc+s)//右上
    {
        ChessBoard(tr,tc+s,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s] = t1;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr >= tr+s && dc < tc+s)//左下
    {
        ChessBoard(tr+s,tc,dr,dc,s);
    }
    else
    {
        board[tr+s][tc+s-1] = t1;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr >= tr+s && dc >= tc+s)//右下
    {
        ChessBoard(tr+s,tc+s,dr,dc,s);
    }
    else
    {
        board[tr+s][tc+s] = t1;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    int n;
    cin>>n;
    int ab;            //横坐标
    int ori;               //纵坐标
    cin>>ab>>ori;
    ChessBoard(1,1,ab,ori,n);//从（1,1）开始
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
