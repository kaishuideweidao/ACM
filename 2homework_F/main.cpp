
//Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do.
//Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework
// after the deadline, the teacher will reduce his score of the final test. And now we assume that
//  doing everyone homework always takes one day. So Ignatius wants you to help him to arrange the
//  order of doing homework to minimize the reduced score.
///**Input*/
//The input contains several test cases. The first line of the input is a single integer T that is
//the number of test cases. T test cases follow.
//Each test case start with a positive integer N(1<=N<=1000) which indicate the number of
//homework.. Then 2 lines follow. The first line contains N integers that indicate the deadlines
//of the subjects, and the next line contains N integers that indicate the reduced scores.
///**Output*/
//For each test case, you should output the smallest total reduced score, one line per test case.

/**
**
*��������С���򣬷���һ������ֹʱ������
*v[]���ڱ�ǣ���Ǻ��ʾ����ҵ��ÿ����ҵ�ӽ�ֹʱ�俪ʼ���������ܶ�����������ҵ
*����ҵ��ֹʱ��ǰ��ʱ�䱻��Ǻ��ʾ��������ҵ������ҵ�޷����
*
*/

#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;


int v[1005];

struct work
{
    int ed;
    int score;
};

bool cmp(work a,work b)
{
    if(a.score!=b.score)
    {
        return a.score>b.score;
    }
    else
    {
        return a.ed<b.ed;
    }
}
int main()
{
    int M;
    work ans[1005];
    scanf("%d",&M);
    for(int i=0; i<M; i++)
    {
        int N;
        scanf("%d",&N);

        int max=0;          //�����ֹʱ��
        for(int i=0; i<N; i++)
        {
            scanf("%d",&ans[i].ed);
            if(ans[i].ed>max)
                max = ans[i].ed;
        }
        for(int i=0; i<N; i++)
        {
            scanf("%d",&ans[i].score);
        }
        memset(v,0,sizeof(v));
        int s=0;
        sort(ans,ans+N,cmp);
//        for(int i=0;i<N;i++)
//        {
//            cout<<ans[i].score<<" ";
//        }
//        cout<<endl;
        for(int i=0; i<N; i++)
        {
            int j=ans[i].ed;    //�ڽ�ֹʱ�䷶Χ�ھ�������������ҵ
            for(; j>=1; j--)
            {
                if(!v[j])
                {
                    v[j]= 1;
//                    cout<<j<<endl;
                    break;
                }

            }
            if(j==0)
            {
//                cout<<"asd"<<ans[i].score<<endl;
                s+=ans[i].score;
            }
        }
        printf("%d\n",s);
//        for(int i=0;i<N;i++)
//        {
//            cout<<v[i];
//        }
//        cout<<endl;
    }


    return 0;
}
