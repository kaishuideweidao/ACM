///*As Easy As A+B*/
//These days, I am thinking about a question, how can I get a problem as easy as A+B? It is fairly
//difficulty to do such a thing. Of course, I got it after many waking nights.
//Give you some integers, your task is to sort these number ascending (ÉýÐò).
//You should know how easy the problem is now!
//Good luck!
///**Input*/
//Input contains multiple test cases. The first line of the input is a single integer T which is the
// number of test cases. T test cases follow. Each test case contains an integer N (1<=N<=1000 the
//number of integers to be sorted) and then N integers follow in the same line.
//It is guarantied that all integers are in the range of 32-int.
///**Output*/
//For each case, print the sorting result, and one line one case.


#include <iostream>
#include<algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    int N;

    while(cin>>N&&N!=0)
    {
        for(int i=0;i<N;i++)
        {
            int ans[1005];
            int T;
            cin>>T;
            for(int j=0;j<T;j++)
            {
                cin>>ans[j];
            }
            sort(ans,ans+T,cmp);
            for(int j=0;j<T-1;j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<ans[T-1]<<endl;
        }
    }

    return 0;
}
