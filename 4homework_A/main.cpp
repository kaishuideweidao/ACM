#include <iostream>
#include<algorithm>//必须加该头文件不然报错找不到max
using namespace std;
int ar[105][105];

void d(int p)
{
    for(int i=p-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            ar[i][j] = max(ar[i+1][j],ar[i+1][j+1]) + ar[i][j];
        }
    }
}

int main()
{
    int n,m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cin>>ar[i][j];
            }
        }
        d(m);
        cout<<ar[1][1]<<endl;
    }
    return 0;
}
