#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

int ar[105];


int mod(int a,int b)//最大公约数
{
   return b==0?a:mod(b,a%b);
//    if(b==0)
//        return a;
//    else
//    {
//        return (a>b)?mod(b,a-b):mod(a,b-a);
//    }
}

int main()
{
    int n;
    int con;
    scanf("%d",&n);
    char ch;

        getchar();
    for(int i=1; i<=n; i++)
    {
        con=1;
        int p=0;
        while((ch=getchar())!='\n')
        {
            if(ch>='0'&&ch<='9')
            {
                ungetc(ch,stdin);//将数字字符回退
                scanf("%d",&ar[++p]);
//printf("asd\n");
            }
//            cin>>ar[++p];
//            over = getchar();
//            if(over=='\n')
//                break;
        }
//        for(int i=1; i<=p; i++)
//        {
//            printf("%d\n",ar[i]);
////            cout<<ar[i]<<endl;
//        }
        for(int i=1; i<p; i++)
        {
            for(int j=i+1; j<=p; j++)
            {
                    con = max(con,mod(ar[i],ar[j]));
            }
        }
        cout << con << endl;
    }
    return 0;
}
