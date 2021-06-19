#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int k ;
        cin>>k;
        
        if(k == 100)
            cout<<"1"<<endl;
        else
        {
            int k1 = k , k2 = 100 - k ;
            int g = __gcd(k1,k2) ;
            k1 = k1/g ;
            k2 = k2/g ;
            
            cout<<(k1+k2)<<endl;
        }
    }
    return 0 ;
}