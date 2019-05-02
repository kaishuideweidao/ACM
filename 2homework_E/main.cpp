//"Yakexi, this is the best age!" Dong MW works hard and get high pay, he has many 1 Jiao and 5 Jiao
// banknotes(纸币), some day he went to a bank and changes part of his money into 1 Yuan, 5 Yuan,
// 10 Yuan.(1 Yuan = 10 Jiao)
//"Thanks to the best age, I can buy many things!" Now Dong MW has a book to buy, it costs P Jiao.
// He wonders how many banknotes at least,and how many banknotes at most he can use to buy this nice
//  book. Dong MW is a bit strange, he doesn't like to get the change, that is, he will give the
//  bookseller exactly P Jiao.
///**Input*/
//T(T<=100) in the first line, indicating the case number.
//T lines with 6 integers each:
//P a1 a5 a10 a50 a100
//ai means number of i-Jiao banknotes.
//All integers are smaller than 1000000.
///**Output*/
//Two integers A,B for each case, A is the fewest number of banknotes to buy the book exactly,
//and B is the largest number to buy exactly.If Dong MW can't buy the book with no change,
//output "-1 -1".

/**
*换零钱。求钱数能换的最多张数和最小张数。
*假设手上总共有p毛，而价格为q毛，我们用手上最少的数量的纸币去凑（p-q）毛，
*然后再用总数量减去该最少数量即可。
*
*/


#include <cstdio>
#include <iostream>

using namespace std;
int value[5]= {1,5,10,50,100};
int a[10];//1 5 10 50 100
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int min=0,max=0;
        int sum=0;
        int p;//要兑换面值
        scanf("%d",&p);
        for(int i=0; i<5; i++)
        {
            scanf("%d",&a[i]);
            sum = sum + a[i]*value[i];//总钱数

        }
        int r = sum -p;
        int temp;
        for(int i=4; i>=0; i--)
        {
            if(p/value[i]<a[i])
            {
                temp = p/value[i];
                p -= temp*value[i];
                min+=temp;
            }
            else
            {
                p -= a[i]*value[i];
                min+=a[i];
            }
        }
        if(p!=0)
        {
            cout<<-1<<" "<<-1<<endl;
        }
        else
        {
//            int r = sum - p; //剩余钱数
            for(int i=4; i>=0; i--)
            {
                if(r/value[i]<a[i])
                {
                    temp = r/value[i];
                    r -= temp*value[i];
                    max+=temp;
                }
                else
                {
                    r -= a[i]*value[i];
                    max+=a[i];
                }
            }
            int s=0;
            for(int i=0;i<5;i++)
            {
                s += a[i];
            }
            cout<<min<<" "<<s-max<<endl;
        }
    }
    return 0;
}
