#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n ;
        cin>>n;
        
        long long int val , sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            sum+=val;
        }
        
        long long int rem = sum % n ;
        if(rem == 0)
            cout<<"0\n" ;
        else
            cout<<(rem * (n-rem))<<endl;
    }
    return 0 ;
}