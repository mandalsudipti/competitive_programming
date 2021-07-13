#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n , a , b , x = 1;
        cin>>n>>a>>b ;
        
        bool possible = false ;
        if(a == 1)
        {
            if((n-1)%b == 0)
                possible = true ;
        }
        else
        {
            while(x <= n)
            {
                if((n - x)%b == 0)
                {
                    possible = true ;
                    break;
                }
                x = x * a ;
            }
        }
        
        if(possible)
            cout<<"YES\n" ;
        else
            cout<<"NO\n" ;
    }
    return 0 ;
}



