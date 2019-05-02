//FJ is about to take his N (1 ≤ N ≤ 2,000) cows to the annual"Farmer of the Year" competition. In this contest every farmer arranges his cows in a line and herds them past the judges.
//
//The contest organizers adopted a new registration scheme this year: simply register the initial letter of every cow in the order they will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that order he just registers BSD). After the registration phase ends, every group is judged in increasing lexicographic order according to the string of the initials of the cows' names.
//
//FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible. He decides to rearrange his cows, who have already lined up, before registering them.
//
//FJ marks a location for a new line of the competing cows. He then proceeds to marshal the cows from the old line to the new one by repeatedly sending either the first or last cow in the (remainder of the) original line to the end of the new line. When he's finished, FJ takes his cows for registration in this new order.
//
//Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.
//
///**Input*/
//* Line 1: A single integer: N
//* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the cow in the ith position in the original line
//
///**Output*/
//The least lexicographic string he can make. Every line (except perhaps the last one) contains the initials of 80 cows ('A'..'Z') in the new line.
//
//

/***
*
*按字典序最小排列，前（后）面小去前（后）面，相等时继续比较里面的
*
*
/


#include <iostream>
#include<cstdio>
using namespace std;
#define N 2005
int main()
{
    int num;
    int count=0;
    cin>>num;
    char ar[N];
    char ans[N];
    for(int i=0;i<num;i++)
    {
        getchar();
        scanf("%c",&ar[i]);
    }
    int k=0;
    int i=0,j=num-1;
    while(i<=j)
    {
        int p,q;
            p = i;
            q = j;
        while(ar[p]==ar[q])
        {
            if(q==p)
                break;
            p++;
            q--;
        }
        if(ar[p]<ar[q] && p!=q)
        {
            ans[k++] = ar[i++];
        }
        else
        {
            ans[k++] = ar[j--];
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%c",ans[i]);
        count++;
        if(count%80==0)
        {
            cout<<endl;
        }
    }

    return 0;
}
