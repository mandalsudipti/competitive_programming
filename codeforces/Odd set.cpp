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
        
        int even = 0 , odd = 0 , val ;
        for(int i = 0 ; i < 2*n ; i++)
        {
            cin>>val;
            val % 2 == 0 ? even++ : odd++ ;
        }
        
        if(even == odd)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0 ;
}