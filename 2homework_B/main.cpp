//B - Ride to School
//
//Many graduate students of Peking University are living in Wanliu Campus, which is 4.5 kilometers from
// the main campus �C Yanyuan. Students in Wanliu have to either take a bus or ride a bike to go to
// school. Due to the bad traffic in Beijing, many students choose to ride a bike.
//
//We may assume that all the students except "Charley" ride from Wanliu to Yanyuan at a fixed speed.
//Charley is a student with a different riding habit �C he always tries to follow another rider to avoid
// riding alone. When Charley gets to the gate of Wanliu, he will look for someone who is setting off
// to Yanyuan. If he finds someone, he will follow that rider, or if not, he will wait for someone to
//  follow. On the way from Wanliu to Yanyuan, at any time if a faster student surpassed Charley, he
//   will leave the rider he is following and speed up to follow the faster one.
//
//            We assume the time that Charley gets to the gate of Wanliu is zero. Given the set off
//            time and speed of the other students, your task is to give the time when Charley arrives
//             at Yanyuan.
///***input***/
//There are several test cases. The first line of each case is N (1 <= N <= 10000) representing the
//number of riders (excluding Charley). N = 0 ends the input. The following N lines are information
//of N different riders, in such format:
//
//Vi [TAB] Ti
//
//Vi is a positive integer <= 40, indicating the speed of the i-th rider (kph, kilometers per hour).
//Ti is the set off time of the i-th rider, which is an integer and counted in seconds. In any case it
// is assured that there always exists a nonnegative Ti.
//
///****output*****/
//Output one line for each case: the arrival time of Charley. Round up (ceiling) the value when dealing
// with a fraction.



/**
*ֻ����ʱ�����0��
*С�����Ҫô׷����
*Ҫô������
*
*/


#include <iostream>
#include<cmath>
            using namespace std;

int main()
{
    double t,v;
    int N;
    while(cin>>N&&N)
    {
        double min = 10000.0;
        for(int i=0; i<N; i++)
        {
            cin>>v>>t;
            if(t>=0)
            {
                double temp = t+4.5*3600/v;
                if(temp<min)
                    min = ceil(temp);//ֻ�����ڸ�����

            }

        }
        cout<<min<<endl;
    }
    return 0;
}
