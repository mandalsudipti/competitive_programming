#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    long long int x = a-b;
    if(x<=0)
    {
        cout<<b<<endl;
        return;
    }
    if(c<=d)
    {
        cout<<"-1"<<endl;
        return;
    }
    long long int cycle = x/(c-d) + (x%(c-d)!=0);
    cout<<(b+cycle*c)<<endl;
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