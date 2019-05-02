#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct node
{
    int x;      //��ʼ����
    int y;      //��������
};

int cmp(node a,node b)                              //�Ƚϴ�С
{
    return a.y<b.y;
}
int LengthSum(node str[])
{
    int last = 0;                                   //��ǰ��������
    int length = 0;
    for(int i=0;i<4;i++)
    {
        if(str[i].x <= last && str[i].y >last)      //��������ǰ��������
        {
            length += str[i].y - last;
        }
        else if(str[i].x > last)                    //�����ڵ�ǰ��������
        {
            length += str[i].y-str[i].x;
        }
        last = str[i].y;                            //���½�������
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
    sort(str,str+n,cmp);//������������������
    LengthSum(str);
}
