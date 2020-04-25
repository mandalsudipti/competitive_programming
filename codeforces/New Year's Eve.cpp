#include<bits/stdc++.h>
using namespace std;

int MSB(long long int num)
{
    int cnt=-1;
    while(num>0)
    {
        num=num/2;
        cnt++;
    }
    return cnt;
}

int main()
{
    long long int n , k , i;
    cin>>n>>k;
    if(k==1)
        cout<<n;
    else
    {
        int x = MSB(n);
        long long int ans=0;
        for(i=0;i<=x;i++)
            ans+=(1ll<<i);
        cout<<ans;
    }
    return 0;
}
