#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
char map[30][30][30];        //��¼�ڵ���Ϣ
int sta[30][30][30];        //����Ƿ����
int base[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };//�����Ӧ
int L, R, C;
struct Piont
{
    int x, y, z;            //λ������
    int step;                //�����㵽�õ�Ĳ���
};
struct Piont s;                //���
struct Piont e;                //�յ�
struct Piont curp;            //����ѭ��ʱ�Ľڵ�

/******************�ж��Ƿ񵽴��յ�*********************/
bool success(struct Piont cur)
{
    if (cur.x == e.x && cur.y == e.y && cur.z == e.z)
        return true;
    else
        return false;
}

/**************�жϸõ��Ƿ�Ϸ�*************************/
bool check(int x, int y, int z)
{
    if ((x >= 0) && (x < L) && (y >= 0) && (y < R) && (z >= 0) && (z < C) && (!sta[x][y][z]) && (map[x][y][z] == '.' || map[x][y][z] == 'E'))
        return true;
    else
        return false;
}

/*************************���ѣ�����̣�***************************///����������*/
void bfs()
{
    struct Piont next;
    queue<Piont>q;
    q.push(s);
    //int flag = 0;
    while (!q.empty())
    {
        curp = q.front();
        q.pop();
        if (success(curp))
            return;
        else
        {
            sta[curp.x][curp.y][curp.z] = 1;
            for (int i = 0; i < 6; i++)
            {
                next.x = curp.x + base[i][0];
                next.y = curp.y + base[i][1];
                next.z = curp.z + base[i][2];
                if (check(next.x, next.y, next.z))        //��չ����
                {
                    next.step = curp.step + 1;
                    sta[next.x][next.y][next.z] = 1;
                    q.push(next);
                }
             }
        }
    }
}
int main()
{
    while (scanf("%d%d%d", &L, &R, &C))
    {
        if((L == 0) && (R == 0) && (C == 0))
            break;
        memset(sta, 0, sizeof(sta));
        for (int i = 0; i < L; i++) {
            getchar();
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++)
                {
                    scanf("%c", &map[i][j][k]);
                    if (map[i][j][k] == 'S') {
                        s.x = i;
                        s.y = j;
                        s.z = k;
                        s.step = 0;
                    }
                    else if (map[i][j][k] == 'E')
                    {
                        e.x = i;
                        e.y = j;
                        e.z = k;
                    }
                }
                getchar();
            }
        }
        bfs();
        if (curp.x == e.x && curp.y == e.y && curp.z == e.z)
            printf("Escaped in %d minute(s).\n", curp.step);
        else
            printf("Trapped!\n");
    }
    return 0;
}
