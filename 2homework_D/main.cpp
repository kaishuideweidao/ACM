/**今年暑假不AC */
//“今年暑假不AC？”
//“是的。”
//“那你干什么呢？”
//“看世界杯呀，笨蛋！”
//“@#$%^&*%...”
//
//确实如此，世界杯来了，球迷的节日也来了，估计很多ACMer也会抛开电脑，奔向电视了。
//作为球迷，一定想看尽量多的完整的比赛，当然，作为新时代的好青年，你一定还会看一些其它的节目，
//比如新闻联播（永远不要忘记关心国家大事）、非常6+7、超级女生，以及王小丫的《开心辞典》等等，
//假设你已经知道了所有你喜欢看的电视节目的转播时间表，你会合理安排吗？（目标是能看尽量多的完整节目）
///**Input*/
//输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100)，表示你喜欢看的节目的总数，
//然后是n行数据，每行包括两个数据Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。n=0表示输入结束，不做处理。
///**Output*/
//对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行。





#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
    int st;
    int ed;
};

bool cmp(node node1,node node2)
{
    return node1.ed<node2.ed;
}

int main()
{
    int i,j,num,ans,now=0;
    struct node nodes[105];
    while(scanf("%d",&num)&&num)
    {
        for(i=0; i<num; i++)
        {
            scanf("%d%d",&nodes[i].st,&nodes[i].ed);
//        cin>>nodes[i].st>>nodes[i].ed;
        }
        sort(nodes,nodes+num,cmp);

        now = nodes[0].ed;
        ans = 1;

        for(j=1; j<num; j++)
        {
            if(nodes[j].st>=now)
            {
                now = nodes[j].ed;

                ans++;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
