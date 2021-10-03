#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    
    vector<long long int>suffix_sum(n+1) ;
    for(int i = 1 ; i < n ; i++)
    {
        cout<<"? "<<i<<" "<<n<<endl;
        fflush(stdout);
        cin>>suffix_sum[i] ;
    }
    
    vector<long long int>flamingo(n+1) ;
    long long int prefix_sum = 0 ;
    
    for(int i = 1 ; i+1 < n ; i++)
    {
       flamingo[i] = suffix_sum[i] - suffix_sum[i+1] ;
       prefix_sum+=flamingo[i] ;
    }
    
    int val ;
    cout<<"? "<<(n-2)<<" "<<(n-1)<<endl;
    fflush(stdout) ;
    cin>>val ;
    flamingo[n-1] = val - flamingo[n-2] ;
    flamingo[n] = suffix_sum[1] - prefix_sum - flamingo[n-1] ;
    
    cout<<"! ";
    fflush(stdout) ;
    
    for(int i = 1 ; i <= n ; i++)
    {
        cout<<flamingo[i]<<" ";
        fflush(stdout) ;
    }
    
    return 0 ;
}
