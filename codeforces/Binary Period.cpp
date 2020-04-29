#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        int k=1;
        for(int i=1;i<S.length();i++)
        {
            if(S[i]!=S[i-1])
            {
                k=2;
                break;
            }
        }
        if(k==1)
            cout<<S<<endl;
        else
        {
            vector<char>ans;
            ans.push_back(S[0]);
            for(int i=1;i<S.length();i++)
            {
                if(S[i]==ans.back())
                {
                    S[i]=='0'?ans.push_back('1'):ans.push_back('0');
                    ans.push_back(S[i]);
                }
                else
                    ans.push_back(S[i]);
            }
            for(int i=0;i<ans.size();i++)
                cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}