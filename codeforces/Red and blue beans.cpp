#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int red , blue , diff ;
        cin>>red>>blue>>diff ;
        
        long long int max_packet = min(red , blue) ;
        
        long long int extra = abs(red - blue) ;
        
        if(extra <= max_packet * diff)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}