#include<bits/stdc++.h>
using namespace std;
long long int find_gcd(long long int a , long long int b)
{
    while(a!=0 && b!=0)
    {
        if(a>b)
            a=a%b;
        else
            b=b%a;
    }
    if(a==0)
        return b;
    else
        return a;
}
long long int count_coprime(long long int n)
{
    long long ans=1;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                ans=ans*i;
                n=n/i;
            }
            ans /= i;
            ans *= (i - 1);
        }
    }
    if(n>1)
    {
       ans *= 1*(n - 1); 
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int a,m ,gcd , cnt=0;
        cin>>a>>m;
        gcd = find_gcd(a,m);
        m=m/gcd ;
        
        cout<<count_coprime(m)<<endl;
    }
    return 0;
}
