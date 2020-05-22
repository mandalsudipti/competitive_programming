#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, mod;
    cin >> n >> mod;
    
    vector <long long> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1]*i)%mod;
    }
    
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        long long int x = n-i+1;
        ans+=( (fact[x]*fact[i])%mod *x)%mod;
        ans = ans%mod;
    }
    cout << ans%mod << "\n";
    return 0;
}