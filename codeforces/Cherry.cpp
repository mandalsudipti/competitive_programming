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
        
        vector<long long int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        long long int ans = 0 ;
        for(int i = 1 ; i < n ; i++)
                ans = max(ans , arr[i] * arr[i-1]) ;
                
        cout<<ans<<endl;
    }
    return 0 ;
}
