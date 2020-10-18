#include<bits/stdc++.h>
using namespace std;

const long long int mod = 998244353 ;
const int range = 3e5+10;
vector<long long int>fact;

long long int power(unsigned long long x, int y, int p) 
{ 
    long long int res = 1; 
  
    x = x % p; 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 

long long int modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 

long long int nCr(unsigned long long n, int r, int p) 
{ 
    if (r == 0) 
        return 1; 
  
    long long int x = (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p; 
    
    return x;
} 

int main()
{
    fact.push_back(1);
    for(int i=1;i<=range;i++)
    {
        fact.push_back( (fact.back()*i)%mod);
    }
    
    long long int n , k ;
    cin>>n>>k;
    vector<pair<int,int>>terminal_point;
    int left , right ;
    for(int i=0;i<n;i++)
    {
        cin>>left>>right;
        terminal_point.push_back(make_pair(left,1));
        terminal_point.push_back(make_pair(right+1,0));
    }
    
    sort(terminal_point.begin(),terminal_point.end());
    
    long long int cnt  = 0 , ans = 0 ;
    for(int i=0;i<terminal_point.size();i++)
    {
        if(terminal_point[i].second == 0)
            cnt--;
        else
        {
            if(cnt>=k-1)
            {
                ans = (ans + nCr(cnt,k-1,mod))%mod;
            }
            cnt++;
        }
    }
    
    
    cout<<ans<<endl;
    
    return 0;
}

