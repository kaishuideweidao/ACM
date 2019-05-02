#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct node
{
    int x;      //开始坐标
    int y;      //结束坐标
};

int cmp(node a,node b)                              //比较大小
{
    return a.y<b.y;
}
int LengthSum(node str[])
{
    int last = 0;                                   //当前结束坐标
    int length = 0;
    for(int i=0;i<4;i++)
    {
        if(str[i].x <= last && str[i].y >last)      //结点包含当前结束坐标
        {
            length += str[i].y - last;
        }
        else if(str[i].x > last)                    //结点大于当前结束坐标
        {
            length += str[i].y-str[i].x;
        }
        last = str[i].y;                            //更新结束坐标
    }
    cout<< length <<endl;
}
int main()
{
    node str[4];
    int n = 0;
    cin >> n;
    for(int i=0;i<4;i++)
    {
        cin>>str[i].x>>str[i].y;
    }
    sort(str,str+n,cmp);//按结束坐标升序排列
    LengthSum(str);
}
