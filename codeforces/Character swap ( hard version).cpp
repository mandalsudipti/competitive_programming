#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string S , T ;
    cin>>S>>T;
    vector<int>freq(26,0);
    for(int i=0;i<n;i++)
    {
        freq[S[i]-'a']++;
        freq[T[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]%2!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    vector<pair<int,int>>ans;
    for(int i=0;i<n;i++)
    {
        if(S[i]==T[i])
            continue;
        for(int j=i+1;j<n;j++)
        {
            if(S[j]==T[j])
                continue;
            if(S[i]==T[j])
            {
                char tmp=S[j];
                S[j]=T[j];
                T[j]=tmp;
                ans.push_back(make_pair(j,j));
            }
            if(S[i]==S[j])
            {
                char tmp = S[j];
                S[j]=T[i];
                T[i]=tmp;
                ans.push_back(make_pair(j,i));
                break;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
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


