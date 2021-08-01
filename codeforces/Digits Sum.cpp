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
        
        int cnt = (n/10) + (n%10 == 9 ? 1 : 0) ;
        cout<<cnt<<endl;
    }
    return 0 ;
}