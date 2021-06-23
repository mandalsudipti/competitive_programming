#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int n , start_interval , duration ;
        cin>>n>>start_interval>>duration ;
        
        long long int spoil_mood = duration / start_interval ;
        long long int last = spoil_mood - 1;
        long long int total = (n - spoil_mood)*spoil_mood +  (last * (last + 1))/2;
        
        if(spoil_mood > (n-1))
            total = (n * (n-1))/2 ;
        cout<<total<<endl;
    }
    return 0 ;
}
