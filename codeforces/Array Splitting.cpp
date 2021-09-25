#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , k ;
    cin>>n>>k;
    
    vector<int>arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i] ;
        
    vector<int>diff ;
    for(int i = 1 ; i < n ; i++)
        diff.push_back(arr[i] - arr[i-1]) ;
        
    sort(diff.begin() , diff.end());
    
    long long int ans= 0 ;
    for(int i = 0 ; i < n - k ; i++)
    {
        ans+=diff[i] ;
        //cout<<diff[i]<<endl;
    }
        
    cout<<ans ;
    return 0 ;
}