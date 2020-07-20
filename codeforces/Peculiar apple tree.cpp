#include<bits/stdc++.h>
using namespace std;

int get_level(map<int,vector<int>>&nxt_level , vector<int>&cur_level)
{
    vector<int>arr;
    for(int i=0;i<cur_level.size();i++)
    {
        auto itr = nxt_level.find(cur_level[i]);
        if(itr!=nxt_level.end())
        {
            vector<int>x = itr->second;
            for(int j=0;j<x.size();j++)
                arr.push_back(x[j]);
        }
    }
    int x ;
    cur_level.size()%2==0 ? x = 0 : x = 1;
    
    if(arr.size()==0)
        return x;
    else
        return x + get_level(nxt_level,arr);
}

int main()
{
    int n ;
    cin>>n;
    
    map<int,vector<int>>nxt_level ;
    for(int i=2;i<=n;i++)
    {
        int x ;
        cin>>x;
        nxt_level[x].push_back(i);
    }
        
    int cnt_level = 0 ;
    vector<int>cur_level;
    cur_level.push_back(1);
    cnt_level = get_level(nxt_level,cur_level);
    
    cout<<cnt_level;
    
    return 0;
}