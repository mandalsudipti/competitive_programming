#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    vector<pair<char,int>>suffix;
    for(int i=0;i<S.length();i++)
        suffix.push_back(make_pair(S[i],i));
    sort(suffix.begin(),suffix.end());
    cout<<S.length()<<" ";
    for(int i=0;i<S.length();i++)
        cout<<suffix[i].second<<" ";
    return 0;
}