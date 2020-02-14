#include<bits/stdc++.h>
using namespace std;

void solve ()
{
    string A,B,C;
    cin>>A>>B>>C;
    for(int i=0;i<A.length();i++)
    {
        if(C[i]!=A[i] && C[i]!=B[i])
        {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
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