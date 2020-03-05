#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int len ;
    cin>>len;
    string S;
    cin>>S;
    int letter[26]={0};
    char first ;
    for(int i=0;i<S.length();i++)
        letter[S[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(letter[i]!=0)
        {
            first = i+'a';
            break;
        }
    }
    string pre;
    int k;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]==first)
        {
            string tmp ;
            for(int j=i;j<S.length();j++)
                tmp+=S[j];
            if(tmp.length()%2==1)
            {
                for(int j=i-1;j>=0;j--)
                    tmp+=S[j];
            }
            else
            {
                for(int j=0;j<i;j++)
                    tmp+=S[j];
            }
            if(pre.length()==0)
            {
                pre=tmp;
                k=i+1;
            }
            else if(pre>tmp)
            {
                pre=tmp;
                k=i+1;
            }
            
        }
        
    }
    cout<<pre<<endl;
    cout<<k<<endl;
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