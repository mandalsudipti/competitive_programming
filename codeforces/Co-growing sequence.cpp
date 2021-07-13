#include<bits/stdc++.h>
using namespace std ;

long long int get_num(long long int pre , long long int cur)
{
    long long int ans = 0 ;
    for(long long int i = 0 ; i < 32 ; i++)
    {
        if( ( (pre & (1<<i)) != 0) && ( (cur & (1<<i)) == 0) )
            ans+=(1<<i);
    }
    return ans ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<long long int> X(n) , Y(n) ;
        
        for(int i = 0 ; i < n ; i++)
            cin>>X[i] ;
            
        Y[0] = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            long long int num = (X[i-1] ^ Y[i-1]) ;
            Y[i] = get_num( num , X[i]) ;
        }
        
        for(int i = 0 ; i < n ; i++)
            cout<<Y[i]<<" ";
        cout<<endl;
    }
    return 0 ;
}