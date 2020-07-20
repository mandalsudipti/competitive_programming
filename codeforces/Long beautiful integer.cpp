#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k ;
    cin>>n>>k;
    
    string S;
    cin>>S;
    vector<char>ch(k);
    for(int i=0;i<k;i++)
        ch[i] = S[i] ;
        
    int compare = 0 ;
    for(int i=k;i<S.length();i++)
    {
        if(S[i]<S[i-k])
        {
            compare = 1 ;
            break;
        }
        else if(S[i]>S[i-k])
        {
            compare = -1 ;
            break ;
        }
    }
    if(compare==-1)
    {
        for(int i=ch.size()-1;i>=0;i--)
        {
            if(ch[i]<'9')
            {
                ch[i]++;
                for(int j=i+1;j<k;j++)
                    ch[j]='0';
                break;
            }
        }
    }
    
    vector<char>ans(S.length());
    for(int i=0;i<k;i++)
    {
        char val = ch[i];
        for(int j=i;j<S.length();j+=k)
            ans[j]=val;
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<S.length();i++)
        cout<<ans[i];
        
    return 0;
}


