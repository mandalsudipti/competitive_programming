#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    string S;
    cin>>n>>S;
    
    map<int,vector<int>> occurrence ;
    occurrence[0].push_back(-1);
    int freq = 0 ;
    for(int i=0;i<n;i++)
    {
        S[i]=='0'?freq--:freq++;
        occurrence[freq].push_back(i);
    }
    
    int max_length = 0 ;
    for(auto itr = occurrence.begin() ; itr!=occurrence.end() ; ++itr)
    {
        vector<int>arr = itr->second ;
        int x = arr.back() - arr[0] ;
        max_length = max( max_length , x);
    }
    cout<<max_length;
    return 0;
}