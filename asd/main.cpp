//#include <iostream>
//#include<cstring>
//using namespace std;
////第二题
//char ar1[1000005];
//char ar2[10005];
//int Next[10005];
//
//void nextArray(int N)
//{
//    int i=0,k=-1;
//    Next[0] = -1;
//    while(i<N)
//    {
//        if(k == -1 || ar2[i] == ar2[k])
//        {
//            i++;
//            k++;
//            Next[i] = k;
//        }
//        else
//        {
//            k = Next[k];
//        }
//    }
//}
//
//
//int main()
//{
//    int sameNum=0,num,i=0,j=0;
//    cin>>num;
//    while((num--)>0)
//    {
//        cin>>ar2>>ar1;
//        int d = strlen(ar2);
//        nextArray(d);
//        i=0;
//        j=0;
//        sameNum=0;
//        int d1 = strlen(ar2);
//        int d2 = strlen(ar1);
//        while(j<d1 && i<d2)
//        {
//            if(j==-1 || ar1[i] == ar2[j])
//            {
//                i++;
//                j++;
//            }
//            else
//            {
//                j = Next[j];
//            }
//            if(j == d1)
//            {
//                sameNum++;
//                j = Next[j];
////                i = i-strlen(ar2)+1;
//            }
//        }
//        cout<<sameNum<<endl;
//    }
//    return 0;
//}

#include <iostream>
#include<cstring>
using namespace std;
//第二题
char ar1[1000005];
char ar2;
int Next[10005];

void nextArray(int N)
{
    int i=0,k=-1;
    Next[0] = -1;
    while(i<N)
    {
        if(k == -1 || ar2[i] == ar2[k])
        {
            i++;
            k++;
            Next[i] = k;
        }
        else
        {
            k = Next[k];
        }
    }
}

void find(int a[])
{

}
int main()
{

    int sameNum=0,num,i=0,j=0;
    cin>>num;
    while((num--)>0)
    {
        cin>>ar1;
//        for(int p=0;p<strlen(ar1);p++)
//        {
//            ar2 = ar1[p];
//            nextArray(d);
//        }
        int p=strlen(ar1)/2;
        find()
        i=0;
        j=0;
        sameNum=0;
        int d1 = strlen(ar2);
        int d2 = strlen(ar1);
        while(j<d1 && i<d2)
        {
            if(j==-1 || ar1[i] == ar2[j])
            {
                i++;
                j++;
            }
            else
            {
                j = Next[j];
            }
            if(j == d1)
            {
                sameNum++;
                j = Next[j];
//                i = i-strlen(ar2)+1;
            }
        }
        cout<<sameNum<<endl;
    }
    return 0;
}
