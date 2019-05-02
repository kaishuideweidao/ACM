#include <iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

char ar1[1000];
char ar2[1000];
string ar3,ar4;
int jus[1005][1005];


int main()
{
    while(scanf("%s %s",ar1,ar2)!=EOF)//c语言
//    while(true)//不能使用while（true）时间超限
    {
//        getline(cin,ar3);//c++会把空格输入
//        getline(cin,ar4);
//        strcpy(ar1,ar3.c_str());/////stirng ->char
//        strcpy(ar2,ar4.c_str());
        int len1 = strlen(ar1);
        int len2 = strlen(ar2);

        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(ar2[j]==ar1[i])
                {
                    jus[i+1][j+1] = jus[i][j]+1;
                }
                else
                {
                    jus[i+1][j+1] = max(jus[i][j+1],jus[i+1][j]);
                }
            }
        }
//        for(int i=0;i<=len1;i++)//输出标记数组
//        {
//            for(int j=0;j<=len2;j++)
//            {
//                cout<<jus[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<jus[len1][len2]<<endl;
    }
    return 0;
}
