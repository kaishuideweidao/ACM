#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int s[10000];
int v[10000];

int main()
{
    int n;
    while(cin>>n)
    {

        for(int i=1; i<=n; i++)
        {
            cin>>s[i];
            v[i] = 1;//memset�ǰ�λ��ʼ�����ȷ�Ϊһ��
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {

                if(s[i]>s[j])//�����ǰ
                {
                    v[i] = max(v[j]+1,v[i]);
                }
            }
        }

        cout<<*max_element(v+1,v+n+1)<<endl;
    }
    return 0;
}


