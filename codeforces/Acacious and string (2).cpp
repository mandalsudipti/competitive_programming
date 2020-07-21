#include<bits/stdc++.h>
using namespace std;
const string match = "abacaba" ;
string X;

bool get_match(int idx)
{
    string S = X ;
    for(int i=0;i<7;i++)
    {
        if(S[i+idx]==match[i])
            continue;
        else if(S[i+idx]=='?')
            S[i+idx]=match[i];
        else
            return false;
    }
    int cnt = 0 , n = S.length();
    for(int i=0;i+6<n;i++)
    {
        bool flag = true ;
        for(int j=0;j<7;j++)
        {
            if(S[i+j]!=match[j])
                flag = false;
        }
        if(flag)
            cnt++;
    }
    if(cnt==1)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            S[i]=='?'? cout<<'z':cout<<S[i];
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
        cin>>X;
        int cnt = 0 ;
        for(int i=0;i+6<X.length();i++)
        {
            bool flag = true;
            for(int j=0;j<7;j++)
                if(X[i+j]!=match[j])
                    flag = false;
            if(flag)
                cnt++;
        }
        if(cnt>1)
            cout<<"NO"<<endl;
        else if(cnt==1)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<X.length();i++)
                X[i]=='?' ? cout<<'z':cout<<X[i];
            cout<<endl;
        }
        else if(cnt==0)
        {
            bool flag = false;
            for(int i=0;i+6<X.length();i++)
            {
                if(X[i]=='?'||X[i]=='a')
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