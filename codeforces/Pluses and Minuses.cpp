#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string S;
    cin>>S;
    int prefix[S.length()];
    for(int i=0;i<S.length();i++)
    {
        if(i==0)
        {
            S[i]=='+'?prefix[0]=1 : prefix[0]=-1;
            continue;
        }
        S[i]=='+' ? prefix[i] = prefix[i-1]+1 : prefix[i] = prefix[i-1]-1;
    }
    long long int res = 0 ;
    int find = -1 ;
    for(int i=0;i<S.length();i++)
    {
        if(prefix[i]==find)
        {
            res+=i+1;
            find--;
        }
    }
    res+=S.length();
    cout<<res<<endl;
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