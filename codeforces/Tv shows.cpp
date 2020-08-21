#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;

int main()
{
    long long int n , x ,y ;
    cin>>n>>x>>y;
    
    vector<pair<long long int,long long int>>segment(n);
    long long int left , right ;
    for(int i=0;i<n;i++)
    {
        cin>>left>>right;
        segment[i] = make_pair(left,right);
    }
    sort(segment.begin(),segment.end());
    long long int cost = (x + ((segment[0].second - segment[0].first)*y)%mod )%mod;
    multiset<int>available;
    available.insert(segment[0].second);
    
    for(int i=1;i<n;i++)
    {
        auto itr = available.lower_bound(segment[i].first);
        if(itr==available.begin())
            cost = (cost + (x + y*(segment[i].second-segment[i].first))%mod )%mod;
        else
        {
            itr--;
            int end = (*itr);
            if((segment[i].first - end)*y<x)
            {
                cost = ( cost + ((segment[i].first - end)*y)%mod + ((segment[i].second - segment[i].first)*y)%mod )%mod ;
                available.erase(itr);
            }
            else
                cost = ( cost + (x + y*(segment[i].second - segment[i].first))%mod)%mod ;
        }
        available.insert(segment[i].second);
    }
    cout<<cost%mod<<endl;
    
    return 0;
}
