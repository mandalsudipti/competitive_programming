#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string S, T;
    cin>>S>>T;
    vector< vector<int> > location(26);
    for(int i=0;i<S.length();i++)
    {
        location[S[i]-'a'].push_back(i) ;
    }
     int operation=1 , last_match=-1;
    for(int i=0;i<T.length();i++)
    {
        if(location[T[i]-'a'].size()==0)
        {
            cout<<"-1\n";
            return;
        }
        auto itr= upper_bound(location[T[i]-'a'].begin(),location[T[i]-'a'].end(),last_match);
        if(itr== location[T[i]-'a'].end())
        {
            operation++;
            last_match=location[T[i]-'a'][0];
        }
        else
        {
            last_match=*itr;
        }
    }
    cout<<operation<<endl;
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