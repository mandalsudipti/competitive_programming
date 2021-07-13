#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , k , r;
        cin>>n>>k;
        
        for(int i = 1 ; i <= n ; i++)
        {
            long long int query ;
            if(i == 1)
                query = 0 ;
            else
                query = ((i-2) ^ (i-1)) ;
                
            cout<<query<<endl;
            fflush(stdout) ;
            cin>>r;
            fflush(stdout);
            if(r == 1)
                break;
        }
    }
    return 0 ;
}
