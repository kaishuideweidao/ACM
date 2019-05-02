#include <iostream>

using namespace std;

int B(int a[],int b[],int n)
{
    int i, k;
    int x[5], sum1[5], sum2[5];
    int best = 50;
    for(i=1;i<=n;i++)
    {
        x[i] = -1;
        sum1[i] = 0;
        sum2[i] = 0;
    }
    sum1[0] = 0;
    sum2[0] = 0;
    k = 1;
    while(k>=1)
    {
        x[k] = x[k]+1;
        while(x[k]<n)
        {
            for(i=1;i<k;i++)
                if(x[i]==x[k])
                    break;
            if(i==k)
            {
                sum1[k] = sum1[k-1] + a[x[k]];
                if(sum2[k-1]<sum1[k])
                    sum2[k] = sum1[k]+b[x[k]];
                else
                    sum2[k] = sum2[k-1] + b[x[k]];
                if(sum2[k] < best)
                    break;
                else
                    x[k] = x[k]+1;
            }
            else
                x[k]+=1;
        }

        if(x[k]<n && k==n)
            {
                if(best >sum2[k])
                {
                    best = sum2[k];
                    for(int j=1;j<=n;j++)
                    {
                        cout<<x[j]+1<<" ";
                    }
                cout<<best<<endl;
                }
            }
        if(x[k]<n && k<n)
            k = k+1;
        else
        {
//            if(x[k]<n && k==n)
//            {
//                if(best >sum2[k])
//                {
//                    best = sum2[k];
//                    for(int j=1;j<=n;j++)
//                    {
//                        cout<<x[j]+1<<" ";
//                    }
//                cout<<best<<endl;
//                }
                x[k] = -1;
                k = k-1;
//            }
        }
    }
    return best;
}

int main()
{
    int a[4] = {2,5,4,3};
    int b[4] = {3,2,8,5};
    B(a,b,4);
    return 0;
}
