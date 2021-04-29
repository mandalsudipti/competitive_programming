#include<bits/stdc++.h>
using namespace std ;
const long long int num = 2050 ;
int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int n ;
        cin>>n;
        
        if(n%num != 0)
            cout<<"-1"<<endl;
        else
        {
            n = n / num ;
            int sum = 0 ;
            while(n != 0)
            {
                sum+=n%10 ;
                n = n / 10 ;
            }
            cout<<sum<<endl;
        }
    }
    return 0 ;
}