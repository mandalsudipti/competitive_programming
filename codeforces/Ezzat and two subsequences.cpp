#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<long double>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end()) ;
        long double  a = arr.back() , b = 0 ;
        for(int i = 0 ; i < n-1 ; i++)
            b+=arr[i] ;
            
        long double avg = a + (b / (long double)(n-1)) ;
        cout<<fixed<<setprecision(8)<<avg<<endl;
    }
    return 0 ;
}
