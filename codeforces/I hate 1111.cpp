#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n ;
        cin>>n ;
        
        long long  int q = n/11 , rem = n%11 ;
        
        if(q >= rem*10)
            cout<<"YES\n" ;
        else
            cout<<"NO\n" ;
    }
    return 0 ;
}