#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int cust , tmp , low , high , minute ,pre_minute=0, l,h ;
    bool flag=true;
    cin>>cust>>tmp;
    low=high=tmp;
    while(cust--)
    {
        cin>>minute>>l>>h;
        low = (low-(minute- pre_minute));
        high = (high+ (minute- pre_minute));
        pre_minute = minute ;
        if(high<l || low>h)
        {
            //cout<<"NO\n";
            flag=false;
        }
        low = max(l,low);
        high = min(h,high);
    }
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}



