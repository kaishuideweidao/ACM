//Farmer John wants to repair a small length of the fence around the pasture. He measures the fence
//and finds that he needs N (1 ≤ N ≤ 20,000) planks of wood, each having some integer length Li
//(1 ≤ Li ≤ 50,000) units. He then purchases a single long board just long enough to saw into the N
//planks (i.e., whose length is the sum of the lengths Li). FJ is ignoring the "kerf", the extra
//length lost to sawdust when a sawcut is made; you should ignore it, too.
//
//FJ sadly realizes that he doesn't own a saw with which to cut the wood, so he mosies over to Farmer
// Don's Farm with this long board and politely asks if he may borrow a saw.
//
//Farmer Don, a closet capitalist, doesn't lend FJ a saw but instead offers to charge Farmer John for
// each of the N-1 cuts in the plank. The charge to cut a piece of wood is exactly equal to its length.
//  Cutting a plank of length 21 costs 21 cents.
//
//Farmer Don then lets Farmer John decide the order and locations to cut the plank. Help Farmer John
//determine the minimum amount of money he can spend to create the N planks. FJ knows that he can cut
//the board in various different orders which will result in different charges since the resulting
//intermediate planks are of different lengths.
//
///**Input*/
//
//Line 1: One integer N, the number of planks
//Lines 2..N+1: Each line contains a single integer describing the length of a needed plank
///**Output*/
//
//Line 1: One integer: the minimum amount of money he must spend to make N-1 cuts
//Sample Input


/**
**
*哈弗曼树
*每次选择最小的两个值相加最终结果最小
*
*
**/
#include <iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    long long int sum=0;
    int N,t,min1,min2;
    while(~scanf("%d",&N))
    {
        priority_queue<int,vector<int>,greater<int> > q;//优先级队列，升序排列
        for(int i=0;i<N;i++)
        {
            scanf("%d",&t);
            q.push(t);
        }
        sum=0;
        if(q.size()==1)
        {
            sum+=q.top();
            q.pop();
        }
        while(q.size()>1)
        {
            min1 = q.top();
            q.pop();
            min2 = q.top();
            q.pop();
            int temp = min1 + min2;
            sum += temp;
            q.push(temp);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
