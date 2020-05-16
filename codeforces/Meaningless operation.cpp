#include<bits/stdc++.h>
using namespace std;

long long int make_all_one(long long int n)
{
    int msb = -1 ;
    while(n>0)
    {
        msb++;
        n=n>>1ll;
    }
    long long int ans=0,i;
    for(i=0;i<=msb;i++)
        ans=(ans+(1ll<<i));
    return ans;
}

bool all_one(long long int n)
{
    int msb = 0 , cnt_one = 0 ;
    while(n>0)
    {
        msb++;
        if(n&1ll)
            cnt_one++;
        n=n>>1;
    }
    if(msb==cnt_one)
        return true;
    else
        return false;
}

long long int max_divisor(long long int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return(n/i);
    }
    return 1;
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        long long int n;
        cin>>n;
        if(all_one(n))
        {
            cout<<max_divisor(n)<<endl;
        }
        else
        {
            cout<<make_all_one(n)<<endl;
        }
    }
    return 0;
}

