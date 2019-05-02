/***Sort it**/
//You want to processe a sequence of n distinct integers by swapping two adjacent sequence elements
//until the sequence is sorted in ascending order. Then how many times it need.
//For example, 1 2 3 5 4, we only need one operation : swap 5 and 4.
///**Input*/
//The input consists of a number of test cases. Each case consists of two lines: the first line
//contains a positive integer n (n <= 1000); the next line contains a permutation of the n integers
// from 1 to n.
///**Output*/
//For each case, output the minimum times need to sort it in ascending order on a single line.







#include <iostream>
#include<cstdio>
using namespace std;
#define NUM 1005
int main()
{
    int N;
    int s[NUM];
    int i,j,k;
    while(scanf("%d",&N)!=EOF)
    {
        for(k=0; k<N; k++)
        {
            scanf("%d",&s[k]);
        }
        int count=0;
        for(i=0; i<N-1; i++)
        {
            for(j=i+1; j<N; j++)
            {
                if(s[i]>s[j])
                {
                    swap(s[i],s[j]);
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
