#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    vector<int>ans;
    int i,j ;
    for(i=0;i<S.length();i++)
    {
        if(S[i]=='(')
        {
            for(j=S.length()-1;j>i;j--)
            {
                if(S[j]==')')
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    S[j]='0';
                    break;
                }
            }
        }
    }
    if(ans.size()>1)
        cout<<"1\n";
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
    return 0;
}
