#include<bits/stdc++.h>
using namespace std;

void get_idx(int idx , set<int>&seq,int len,int k)
{
    if(idx<0 || idx>len-1 ||seq.find(idx)!=seq.end())
    {
        return;
    }
    seq.insert(idx);
    get_idx(idx+k,seq,len,k);
    get_idx(len-1-idx,seq,len,k);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ,k;
        int cost=0;
        cin>>n>>k;
        string S;
        cin>>S;
        for(int i=0;i<n;i++)
        {
            if(S[i]!='*')
            {
                int maximum=1;
                set<int>seq;
                get_idx(i,seq,n,k);
                vector<int>letter(26,0);
                for(auto itr=seq.begin();itr!=seq.end();++itr)
                {
                    int x = (*itr);
                    letter[S[x]-'a']++;
                    maximum=max(maximum,letter[S[x]-'a']);
                    S[x]='*';
                }
                cost+= ((int)(seq.size())-maximum) ;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
