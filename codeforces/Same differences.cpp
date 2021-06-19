#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        int val ;
        map<int,long long int>freq ;
        
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>val;
            freq[val - i]++;
        }
        
        long long int ans = 0 ;
        for(pair<int,long long int>P : freq)
            ans+=((P.second * (P.second-1))/2) ;
            
        cout<<ans<<endl;
    }
    return 0 ;
}