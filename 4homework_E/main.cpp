/**�ǹ���ս
*https://blog.csdn.net/wuxinxiaohuangdou/article/details/10263103
*f(A) = f(A|B1)f(B1) + f(A|B2)f(B2) + f(A|B3)f(B3) +....
*1��ʤ�ĸ���p,2��ʤ�ĸ���q
*��f(A)Ϊ������A���ǹ�ʱ��ʤ�ĸ���
*f(A) = f(A+1)q(1-p) + f(A-1)p(1-q) + f(A)(1-(1-p)-(1-q))
/////////////////////
*p(1-q)*(f(i+1)-f(i)) = q(1-p)*(f(i)-f(i-1))
*��g(i)=f(i)-f(i-1),
����p(1-q)*g(i) = q(1-p)g(i-1),��g(i)�ǵȱ�����,
��k=q(1-p)/(p(1-q))����g(i) = k*g(i-1)g(1) = f(1)-f(0)
g(2) = f(1)-f(0)
...
g(n) = f(n)-f(n-1)
...
g(n+m) = f(n+m)-f(n+m-1)
������ĸ�����ʽ��ӵģ�g(1)+g(2)+...+g(n+m)=f(n+m)-f(0)=1
g(1)+g(2)+...+g(n+m)=g(1)*(1-k^(n+m))/(1-k)
g(1)+g(2)+...+g(n)=g(1)*(1-k^(n))/(1-k)
�ص���ʼ���壬����֪��f(0)=0 (��ʾ�Ѿ�����)��f(n+m)=1(��ʾ�Ѿ�Ӯ��)
g(1)=f(1)-f(0)=f(1)
���g(1)+g(2)+...+g(n+m) = f(1)*(1-k^(n+m))/(1-k)=1............................................��1��
g(1)+g(2)+...+g(n) = f(1)*(1-k^(n))/(1-k)=f(n)...................................................��2��
����Ҫ��ľ���f(n)���ڣ�2��ʽ�У�ֻҪf(1)��δ֪�ģ�
�����Ҫ����1�������f(1).����f(n)=(1-k^n)/(1-k^(m+n))��Ҫע��ļ����ط���
N==0��M==0��p==0��q==0��p==q�������������
*/
//*********//////////


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int N,M;
    double p,q,rate,k;
    while(cin>>N>>M>>p>>q)
    {
        if(N==0){cout<<"0.00"<<endl;continue;}
        if(M==0){cout<<"1.00"<<endl;continue;}
        if(p==0||q==1){cout<<"0.00"<<endl;continue;}
        if(q==0||p==1){cout<<"1.00"<<endl;continue;}
        if(p==q) rate=1.0*N/(M+N);   //M,N��һ������0.5
        else
        {
            k = q*(1-p)/(p*(1-q));
            rate = (1.0-pow(k,N))/(1.0-pow(k,M+N));      //������
        }
        cout<<fixed<<setprecision(2)<<rate<<endl;    //���ø������������Ч����λ��
    }
    return 0;

}
