#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , good , bad , day=0;
        cin>>n>>good>>bad ;
        long long int good_period = ((n/2)+(n%2==1))/ good ;
        day = (good_period*good) ;
        if(((n/2)+(n%2==1))% good!=0 )
        {
            day +=((n/2)+(n%2==1))% good ;
            good_period ++ ;
        }
        day += ((good_period-1)*bad);
        if(n>day)
            day+=(n-day);
        cout<<day<<endl;
    }
    return 0;
}