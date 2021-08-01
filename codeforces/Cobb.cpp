#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n , k ;
        cin>>n>>k;
        
        vector<long long int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        int start = max(0ll , n - 2*k - 1) ;
        long long int maximum = INT_MIN ;
        for(long long int i = start ; i < n ; i++)
        {
            for(long long int j = i+1 ; j < n ; j++)
            {
                long long int val = ((i+1)*(j+1)) - (k * (arr[i] | arr[j])) ;
                maximum = max(maximum , val) ;
            }
        }
        
        cout<<maximum<<endl;
    }
    return 0 ;
}
