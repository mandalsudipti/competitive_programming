#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int x , y ;
        cin>>x>>y ;
        
        long long int count = 0 ;
        for(int i = 1 ; i <= sqrt(x) ; i++)
        {
            long long int cur_pair = min(y , (x/i) - 1) - i;
            count+=max(0ll , cur_pair) ;
        }
        
        cout<<count<<endl;
    }
    return 0 ;
}