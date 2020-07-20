#include<bits/stdc++.h>
using namespace std;
const string match = "abacaba" ;
string S;

bool get_match(int idx)
{
    string tmp = S;
    for(int i=0;i<7;i++)
    {
        if(tmp[i+idx]==match[i])
            continue;
        else if(tmp[i+idx]=='?')
            tmp[i+idx]=match[i];
        else
            return false;
    }
    int cnt = 0 , n = S.length();
    for(int i=0;i+6<n;i++)
    {
        bool flag = true ;
        for(int j=0;j<7;j++)
        {
            if(tmp[i+j]!=match[j])
                flag = false;
        }
        if(flag)
            cnt++;
    }
    if(cnt==1)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            tmp[i]=='?'? cout<<'z':cout<<tmp[i];
        cout<<endl;
        return true;
    }
    return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        cin>>S;
        int cnt = 0 ;
        for(int i=0;i+6<S.length();i++)
        {
            bool flag = true;
            for(int j=0;j<7;j++)
                if(S[i+j]!=match[j])
                    flag = false;
            if(flag)
                cnt++;
        }
        if(cnt>1)
            cout<<"NO"<<endl;
        else if(cnt==1)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<S.length();i++)
                S[i]=='?' ? cout<<'z':cout<<S[i];
            cout<<endl;
        }
        else if(cnt==0)
        {
            bool flag = false;
            for(int i=0;i+6<S.length();i++)
            {
                if(S[i]=='?'||S[i]=='a')
                {
                    flag = get_match(i);
                    if(flag)
                        break;
                }
            }
            if(!flag)
                cout<<"NO"<<endl;
        }
    }
    return 0;
}

