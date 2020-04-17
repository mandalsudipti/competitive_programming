#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int num , n , m;
    cin>>num>>n>>m;
    for(int i=0;i<n;i++)
    {
        int tmp = (num/2)+10;
        if(tmp<num)
            num=tmp;
        else
            break;
    }
    num-=(10*m);
    if(num<=0)
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