#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    vector<set<int>>freq(26);
    for(int i=0;i<S.length();i++)
    {
        freq[S[i]-'a'].insert(i);
    }
    int query;
    cin>>query;
    while(query--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int pos;
            char ch;
            cin>>pos>>ch;
            --pos;
            //cout<<S[pos]<<endl;
            //freq[S[pos]-'a'].erase( freq[S[pos]-'a'].find(pos) );
            //if(freq[S[pos]-'a'].find(pos)==freq[S[pos]-'a'].end())
                //cout<<"YES"<<endl;
            freq[S[pos]-'a'].erase(pos);
            freq[ch-'a'].insert(pos);
            S[pos]=ch;
        }
        else
        {
            int left , right , cnt=0;
            cin>>left>>right;
            left--;
            right--;
            for(int i=0;i<26;i++)
            {
                auto itr=freq[i].lower_bound(left);
                if(itr!=freq[i].end() && *itr<=right)
                   cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}