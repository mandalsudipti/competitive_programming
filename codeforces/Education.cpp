#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int n , cost , coin = 0;
        cin>>n>>cost ;
        
        vector<long long int>A(n) , B(n-1) ;
        for(int i = 0 ; i < n ; i++)
            cin>>A[i] ;
        for(int i = 0 ; i < n-1 ; i++)
            cin>>B[i] ;
            
        long long int min_day = LLONG_MAX , cur_day = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(coin >= cost)
                break ;
                
            min_day = min(min_day , cur_day + ((cost - coin)/A[i]) + ( (cost - coin)%A[i] != 0) ) ;
            
            if(i+1 < n)
            {
                cur_day++;
                
                if(coin >= B[i])
                    coin-=B[i] ;
                else
                {
                    long long int day = (B[i] - coin)/A[i] + ((B[i] - coin)%A[i] != 0) ;
                    long long int earn = day * A[i] ;
                    cur_day+=day ;
                    coin = coin + earn - B[i] ;
                }
            }
        }
        
        cout<<min_day<<endl;
    }
    
    return 0 ;
}
