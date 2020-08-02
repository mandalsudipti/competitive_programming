#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    string S , T ;
    cin>>S>>T;
    int ans = 0 ;
    for(int i=0;i<n;i++)
    {
        if(S[i]>T[i])
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    
    for(char x='a';x<='t';x++)
    {
        vector<int>pos;
        char ch = 'z';
        for(int i=0;i<n;i++)
            if(S[i]==x && T[i]>S[i])
            {
                pos.push_back(i);
                ch = min(ch,T[i]);
            }
                
        if(pos.size()>0)
            ans++;
        for(int i=0;i<pos.size();i++)
            S[pos[i]]=ch;
    }
    cout<<ans<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
}