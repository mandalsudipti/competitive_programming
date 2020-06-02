#include<bits/stdc++.h>
using namespace std;

bool check(vector<string>&S)
{
    string cmp = S[0];
    for(int i=1;i<S.size();i++)
    {
        string str = S[i] ;
        int cnt = 0 ;
        for(int j=0;j<cmp.length();j++)
        {
            if(cmp[j]!=str[j])
                cnt++;
        }
        if(cnt>1)
            return false;
    }
    return true;
}

void solve()
{
    int no_of_str , len ;
    cin>>no_of_str>>len;
    vector<string>S(no_of_str);
    
    for(int i=0;i<no_of_str;i++)
        cin>>S[i];
    
    for(int i=0;i<len;i++)
    {
        vector<bool>letter_available(26,true);
        letter_available[S[0][i]-'a']=false;
        bool possible=true;
        
        for(int j=1;j<no_of_str;j++)
        {
            int cnt=0;
            for(int k=0;k<len;k++)
            {
                if(k!=i && S[0][k]!=S[j][k])
                    cnt++;
            }
            if(cnt>=2)
            {
                possible=false;
                break;
            }
            else if(cnt==1)
            {
                for(int k=0;k<26;k++)
                {
                    if(k!=(S[j][i]-'a') )
                        letter_available[k]=false;
                }
                letter_available[S[j][i]-'a']=true;
                break;
            }
        }
        if(possible)
        {
            char ch = S[0][i];
            for(int k=0;k<26;k++)
            {
                if(letter_available[k])
                {
                    S[0][i]=(k+'a');
                    break;
                }
            }
            if(check(S))
            {
                cout<<S[0]<<endl;
                return ;
            }
            else
                S[0][i]=ch;
        }
    }
    if(check(S))
        cout<<S[0]<<endl;
    else
        cout<<"-1"<<endl;
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


