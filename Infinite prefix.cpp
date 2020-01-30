#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int len , diff , cnt ;
    cin>>len>>diff;
    string S ;
    cin>>S;
    vector<int> freq(len);
    
    freq[0]=(S[0]=='0'?1:-1);
    for(int i=1;i<S.length();i++)
    {
        if(S[i]=='0')
            freq[i]=freq[i-1]+1;
        else
            freq[i]=freq[i-1]-1;
    }
    cnt=(diff==0?1:0);
    
   for(int i=0;i<len;i++)
    {
        if(freq[len-1]==0 && freq[i]==diff)
        {
            cout<<"-1\n";
            return ;
        }
        if(freq[len-1]!=0 && (diff-freq[i])%freq[len-1]==0 && (diff-freq[i])/freq[len-1]>=0 )
            cnt++;
    }
    cout<<cnt<<endl;
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