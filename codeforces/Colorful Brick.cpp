#include<bits/stdc++.h>
using namespace std;
long long int P = 998244353;
vector<long long int>fact;

void find_factor(long long int n , vector<long long int>&fact)
{
    fact.push_back(1);
    for(int i=1;i<=n;i++)
        fact.push_back( (i*fact.back())%P);
}

long long int power(long long int x , long long int y , long long int p)
{
    long long int res = 1; 
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1ll) 
            res = (res*x) % p; 
        y = y>>1ll; 
        x = (x*x) % p; 
    } 
    return res; 
}

long long int modInverse(long long int num , long long int P)
{
    return power(num,P-2,P);
}
long long int nCr(long long int n , long long int r , long long int P)
{
    if(r==0)
        return 1;
    return ((fact[n]*modInverse(fact[r],P))%P*modInverse(fact[n-r],P))%P ;
}

int main()
{
    long long int n , m , k;
    cin>>n>>m>>k;
    find_factor(n,fact);
    cout << (( (nCr(n-1,k,P)*power(m-1,k,P) )%P)*m)%P;
    return 0;
}