#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        int one = (n/3) + (n%3 == 1 ? 1 : 0) ;
        int two = (n/3) + (n%3 == 2 ? 1 : 0) ;
        
        cout<<one<<" "<<two<<endl;
    }
    return 0 ;
}