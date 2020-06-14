#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int num ;
        cin>>num;
        long long int ans = 0;
        for(long long int i=0;i<63;i++)
        {
            if(num & (1ll<<i))
                ans+=(1ll<<(i+1))-1;
        }
        cout<<ans<<endl;
    }
}