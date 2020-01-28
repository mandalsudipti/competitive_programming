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

long long int combination_of_factor(long long int num)
{
    map<long long int , long long int > freq ;
    while(num%2==0)
    {
        freq[2]++;
        num=num/2;
    }
    for(int i=3;i<=sqrt(num);i++)
    {
        while(num%i==0)
        {
            freq[i]++;
            num=num/i;
        }
    }
    if(num>2)
        freq[num]++;
        
    long long int ans=1;
    
    for(auto itr=freq.begin();itr!=freq.end();++itr)
    {
        ans = ans* (itr->second +1) ;
    }
    return ans;
}

int main()
{
    int n ,i ;
    cin>>n;
    long long int val , gcd=0;
    for(i=0;i<n;i++)
    {
        cin>>val;
        gcd = find_gcd (gcd,val);
    }
    cout<<combination_of_factor(gcd);
    return 0;
}

