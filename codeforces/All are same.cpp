#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n ;
        
        vector<long long int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end()) ;
        long long int step = 0 ;
        
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] - arr[i-1] == 0)
                continue ;
            else
                step = __gcd(step , arr[i] - arr[i-1]) ;
        }
        
        if(step == 0)
            cout<<"-1"<<endl;
        else
            cout<<step<<endl;
    }
    return 0 ;
}
