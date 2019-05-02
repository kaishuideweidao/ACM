//Nike likes playing cards and makes a problem of it.
//
//Now give you n integers, ai(1≤i≤n)ai(1≤i≤n)
//
//We define two identical numbers (eg: 2,22,2) a Duizi,
//and three consecutive positive integers (eg: 2,3,42,3,4) a Shunzi.
//
//Now you want to use these integers to form Shunzi and Duizi as many as possible.
//
//Let s be the total number of the Shunzi and the Duizi you formed.
//
//Try to calculate max(s)max(s).
//
//Each number can be used only once.
///**Input*/
//The input contains several test cases.
//
//For each test case, the first line contains one integer n(1≤n≤1061≤n≤106).
//Then the next line contains n space-separated integers aiai (1≤ai≤n1≤ai≤n)
///**Output*/
//For each test case, output the answer in a line.


/**
*先找对子后找顺子
*数组大小表示相应数值个数
*前两个数只能找对数
*从第三个数开始找顺子，再找对子
*/


#include<cstdio>
#include<cstring>
using namespace std;
int a[1000010];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; i++)
        {
            int h;
            scanf("%d",&h);
            a[h]++;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i <= 2)              //
            {
                cnt += a[i] / 2 ;
                a[i] %= 2;
            }
            else
            {
                if(a[i] && a[i-1] && a[i-2])
                {
                    a[i]--;
                    a[i-1]--;
                    a[i-2]--;
                    cnt++;
                }
                cnt+=a[i]/2;
                a[i] %= 2;
            }
        }
        printf("%d\n",cnt);
    }
}
