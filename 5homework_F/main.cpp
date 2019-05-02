/**
C Looooops
https://blog.csdn.net/lyy289065406/article/details/6648546

x=[(B-A+2^k)%2^k] /C




*/
#include<iostream>
#include<cstdio>
using namespace std;

//d=ax+by,�������Լ��d=gcd(a,n)��x��yΪ����ϵ��������ֵΪd��x��y
__int64 EXTENDED_EUCLID(__int64 a,__int64 b,__int64& x,__int64& y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;  //d=a��x=1,y=0,��ʱ��ʽd=ax+by����
	}
	__int64 d=EXTENDED_EUCLID(b,a%b,x,y);
	__int64 xt=x;
	x=y;
	y=xt-a/b*y;  //ϵ��x��y��ȡֵ��Ϊ�����ʽd=ax+by
	return d;
}

int main(void)
{
	__int64 A,B,C,k;
	while(scanf("%I64d %I64d %I64d %I64d",&A,&B,&C,&k))
	{
		if(!A && !B && !C && !k)
			break;

		__int64 a=C;
		__int64 b=B-A;
		__int64 n=(__int64)1<<k;  //2^k
		__int64 x,y;
		__int64 d=EXTENDED_EUCLID(a,n,x,y);  //��a,n�����Լ��d=gcd(a,n)�ͷ���d=ax+by��ϵ��x��y

		if(b%d!=0)  //���� ax=b(mod n) �޽�
			cout<<"FOREVER"<<endl;
		else
		{
			x=(x*(b/d))%n;  //����ax=b(mod n)����С��
			x=(x%(n/d)+n/d)%(n/d);  //����ax=b(mod n)��������С��
			printf("%I64d\n",x);
		}
	}
	return 0;
}

