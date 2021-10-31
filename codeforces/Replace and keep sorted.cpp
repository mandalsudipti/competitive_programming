#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , q , k ;
    cin>>n>>q>>k ;
    
    vector<int>arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i] ;
        
    vector<long long int>choice(n , 0) , prefix_sum(n , 0);
    for(int i = 1 ; i + 1 < n ; i++)
    {
        choice[i] = arr[i+1] - arr[i-1] - 2 ;
        prefix_sum[i] = choice[i] + prefix_sum[i-1] ;
    }
    if(n >= 2)
        prefix_sum[n-1]+=prefix_sum[n-2] ;
        
    while(q--)
    {
        int left , right ;
        cin>>left>>right ;
        left-- ;  right-- ;
        
        if(right == left)
        {
            cout<<(k-1)<<endl;
            continue ;
        }
        long long int ans = prefix_sum[right-1] - prefix_sum[left] + (arr[left + 1] - 2) + (k - arr[right -1] - 1) ;
        cout<<ans<<endl;
    }
    return 0 ;
}