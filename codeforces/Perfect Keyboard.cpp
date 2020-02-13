#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> letter(27,0);
    vector<char> ans;
    string S;
    cin>>S;
    ans.push_back(S[0]);
    int idx=0;
    letter[S[0]-'a']=1;
    for(int i=1;i<S.length();i++)
    {
        if(idx==0)
        {
            if(letter[S[i]-'a']==0)
            {
                ans.insert(ans.begin(),S[i]);
                letter[S[i]-'a']=1;
            }
            else if (ans.size()>1 && ans[idx+1]==S[i])
                idx=1;
            else
            {
                cout<<"NO\n";
                return ;
            }
        }
        else if (idx==ans.size()-1)
        {
            if(letter[S[i]-'a']==0)
            {
                ans.push_back(S[i]);
                letter[S[i]-'a']=1;
                idx++;
            }
            else if(ans.size()>1 && ans[idx-1]==S[i])
            {
                idx--;
            }
            else
            {
                cout<<"NO\n";
                return ;
            }
        }
        else
        {
            if(ans[idx-1]==S[i])
                idx--;
            else if(ans[idx+1]==S[i])
                idx++;
            else
            {
                cout<<"NO\n";
                return ;
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        if(letter[i]==0)
            ans.push_back(i+'a');
    }
    cout<<"YES\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];
    cout<<endl;
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