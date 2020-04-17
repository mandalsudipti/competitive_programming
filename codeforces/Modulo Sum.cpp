#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n , m ;
    cin>>n>>m ;
    int element = min(n,m);
    vector<vector<bool>>dp(element+1,vector<bool>(m,false));
    
    for(int i=1;i<=element;i++)
    {
        int val ;
        cin>>val;
        for(int rem = 0 ;rem<m ;rem++)
        {
            if(dp[i-1][rem]==true)
            {
                int new_rem = (rem + val) % m ;
                dp[i][new_rem]=true;
                dp[i][rem]=true;
            }
        }
        dp[i][val%m]=true ;
    }
    
    
    if(n>m || dp[element][0]==true)
        cout<<"YES";
    else
        cout<<"NO";
    
    return 0;
}
