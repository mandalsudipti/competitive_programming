#include<bits/stdc++.h>
using namespace std;

const long long int mod = 1e9 + 7 ;

long long power_mod(long long x, long long power)
{
    long long result = 1LL;
    
    while(power > 0)
    {
        if(power%2 == 1)
        {
            result = (result*x)%mod;
        }
        
        power = power >> 1;
        x = (x*x)%mod;
    }
    
    return result;
}


long long choose_2(long long n)
{
    return ((n*(n + 1))/2)%mod;
}

int main()
{
    string S;
    cin >> S;
    
    vector <long long> suffix_cost(S.size() + 5);
    for(int i = S.size() - 1, suffix = 0; i >= 0; i--, suffix++)
    {
        suffix_cost[i] = power_mod(10, suffix)*(S[i] - '0');
        
        suffix_cost[i] %=  mod;
        
        suffix_cost[i] *= choose_2(i);
        
        suffix_cost[i] %= mod; 
    }
    
    vector <long long int> multiplier(S.size() + 5, 0);
    for(int i = 1; i <= S.size(); i++)
    {
        multiplier[i] = (multiplier[i - 1] + (i)*power_mod(10, i - 1))%mod;
    }
    
    vector <long long> prefix_cost(S.size() + 1, 0);
    for(int i = 0; i < S.size(); i++)
    {
        prefix_cost[i] = ((multiplier[S.size() - 1 - i])*(S[i] - '0'))%mod ;
    }
    
    long long ans = 0;
    for(int i = 0; i < S.size(); i++)
    {
        ans+= (prefix_cost[i] + suffix_cost[i])%mod;
                
        ans%= mod;
    }

    cout << ans << "\n";
    
    return 0;
}