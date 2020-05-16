#include<bits/stdc++.h>
using namespace std;

bool sortbylen(const pair<string,int>&A,const pair<string,int>&B)
{
    return A.first.length()<B.first.length();
}

bool not_fix(string prefix , string suffix)
{
   for(int i=1;i<prefix.length();i++)
   {
       if(prefix[i]!=suffix[i-1])
        return true;
   }
   return false;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<string,int>>S(2*n-2);
    for(int i=0;i<(2*n-2);i++)
    {
        string s;
        cin>>s;
        S[i]=make_pair(s,i);
    }
    sort(S.begin(),S.end(),sortbylen);
    
    int freq=0 , prefix_str = 2*n-3;
    char ch=S[2*n-3].first[0];
    for(int i=0;i+1<(2*n-2);i+=2)
    {
        if(S[i].first[0]==ch || S[i+1].first[0]==ch)
            freq++;
    }
    if(freq<(n-1) || not_fix(S[2*n-3].first,S[2*n-4].first))
    {
        ch=S[2*n-4].first[0];
        prefix_str=2*n-4;
    }
        
    vector<char>ans(2*n-2,'S');
    string prefix;
    for(int i=(2*n-3);i-1>=0;i-=2)
    {
        if(i==(2*n-3))
        {
            if(i==prefix_str)
            {
                ans[S[i].second]='P';
                prefix = S[i].first;
            }
            else
            {
                ans[S[i-1].second]='P';
                prefix=S[i-1].first;
            }
            //cout<<prefix<<endl;
            continue;
        }
        string tmp ;
        for(int j=0;j<prefix.length()-1;j++)
            tmp+=prefix[j];
        if(tmp==S[i].first)
            ans[S[i].second]='P';
        else
            ans[S[i-1].second]='P';
        prefix=tmp;
    }
    //cout<<ch<<endl;
    for(int i=0;i<(2*n-2);i++)
        cout<<ans[i];
    return 0;
}
