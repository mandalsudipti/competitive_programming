#include<bits/stdc++.h>
using namespace std;

const long long int mod = 1e9+7;
long long int power(long long int x , long long int y)
{
    long long int res=1;
    while(y>0)
    {
        if(y & 1ll)
            res=(res*x)%mod;
        y=y>>1;
        x=(x*x)%mod;
    }
    return res%mod;
}

int main()
{
    long long int present , box ;
    cin>>present>>box;
    cout<<power(power(2ll,box)-1ll,present)%mod;
    return 0;
}
