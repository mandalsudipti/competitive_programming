#include<bits/stdc++.h>
using namespace std;

const long long int range = 1e9 ;
void solve()
{
    long long int n;
    cin>>n;
    long long int val ;
    set<long long int>rem;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        rem.insert((val+i+n*range)%n);
    }
    if(rem.size()!=n)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
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