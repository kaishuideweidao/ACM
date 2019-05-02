#include <iostream>
#include<cmath>
using namespace std;

int board[5][5];
int t = 0;//���

void ChessBoard(int tr, int tc, int dr, int dc, int size)//���������꣬���ⷽ�������̴�С
{
    int s, t1;
    if(size == 1)
        return;
    t1 = ++t;
    s = size / 2;
    if(dr < tr+s && dc <tc+s)//����
    {
        ChessBoard(tr,tc,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s-1] = t1;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr < tr+s && dc >= tc+s)//����
    {
        ChessBoard(tr,tc+s,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s] = t1;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr >= tr+s && dc < tc+s)//����
    {
        ChessBoard(tr+s,tc,dr,dc,s);
    }
    else
    {
        board[tr+s][tc+s-1] = t1;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr >= tr+s && dc >= tc+s)//����
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
    int ab;            //������
    int ori;               //������
    cin>>ab>>ori;
    ChessBoard(1,1,ab,ori,n);//�ӣ�1,1����ʼ
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
