#include<bits/stdc++.h>
using namespace std;

long long int fact(long long int n , long long int mod)
{
    long long int ans = 1 ;
    for(int i=n;i>1;i--)
        ans = (ans*i)%mod;
        
    return ans;
}

long long int power(long long int n , long long int mod)
{
    long long int ans = 1;
    while(n>0)
    {
        ans = (ans*2)%mod;
        n--;
    }
    return ans;
}

int main()
{
    long long int n ;
    cin>>n;
    long long int mod = 1e9+7;
    long long int x = fact(n,mod) ,  y = power(n-1,mod) ;
    cout<<(x-y+mod)%mod;
    
    return 0;
}