#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n , s ;
        cin>>n>>s;
        
        long long int greater = (n/2) + 1;
        cout<<s/greater<<endl;
    }
    return 0 ;
}