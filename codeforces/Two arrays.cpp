#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
vector<long long int>fac;
void precompute(long long int range)
{
    fac.push_back(1);
    for(int i=1;i<=range;i++)
    {
        fac.push_back(fac.back()*i%mod);
    }
}

long long int power(long long int x, long long int y, long long int p) 
{ 
    long long int res = 1;     
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res%p; 
} 
long long int modInverse(long long int n, long long int p) 
{ 
    return power(n, p-2, p); 
} 

long long int combination(long long int n , long long int r)
{
    return (fac[n]* modInverse(fac[r], mod) % mod * modInverse(fac[n-r], mod) % mod) % mod; 
}

int main()
{
    int n , m;
    cin>>n>>m;
    precompute(n+m+1);
    long long int A , B , ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        A = combination(i+m-2,m-1)%mod;
        B=0;
        for(int j=i;j<=n;j++)
        {
            long long int num = (n-j+1);
            B=(B+combination(num+m-2,m-1)%mod)%mod;
        }
        ans = (ans+(A*B)%mod)%mod;
    }
    cout<<ans;
    return 0;
}