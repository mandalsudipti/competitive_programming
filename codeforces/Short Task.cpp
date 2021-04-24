#include<bits/stdc++.h>
using namespace std ;

const long long int RANGE = 1e7+5 ;
int ans[RANGE] , sum_factor[RANGE] ;

void precompute()
{
    memset(ans , 0 , sizeof(ans));
    memset(sum_factor , 0 , sizeof(sum_factor));
    
    for(int i = 1 ; i < RANGE ; i++)
    {
        for(int j = i ; j < RANGE ; j+=i)
            sum_factor[j]+=i;
    }
    
    for(int i = 1 ; i < RANGE ; i++)
    {
        if(sum_factor[i] < RANGE && ans[sum_factor[i]] == 0)
            ans[sum_factor[i]] = i ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    
    int T ;
    cin>>T;
    while(T--)
    {
        int c ;
        cin>>c;
        
        if(ans[c] > 0)
            cout<<ans[c]<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0 ;
}
