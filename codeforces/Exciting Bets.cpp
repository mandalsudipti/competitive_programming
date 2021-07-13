#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int a , b ;
        cin>>a>>b ;
        
        long long int diff = abs(a-b) ;
        if(diff == 0)
            cout<<"0 0\n";
        else
        {
            long long int rem = a%diff , step , gcd ;
            
            if(rem < (diff - rem))
            {
                step = rem ;
                gcd = __gcd(a - rem , b - rem) ;
            }
            else
            {
                step = (diff - rem) ;
                gcd = __gcd(a + (diff - rem) , b + (diff - rem)) ;
            }
            cout<<gcd<<" "<<step<<endl;
        }
    }
    return 0 ;
}