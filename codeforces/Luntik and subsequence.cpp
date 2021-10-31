#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , num ;
        long long int zero = 0 , one = 0 ;
        cin>>n;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>num ;
            
            if(num == 0)
                zero++ ;
                
            if(num == 1)
                one++ ;
        }
        
        long long int ans = pow(2 , zero) * one ;
        cout<<ans<<endl;
    }
    return 0 ;
}