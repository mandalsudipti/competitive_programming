#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , h ;
    cin>>n>>h;
    
    vector<pair<int,int>>segment(n);
    int x , y ;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        segment[i] = make_pair(x,y);
    }
    
    vector<long long int>dist(n);
    vector<long long int>dip(n);
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
            dist[i] = segment[i].second - segment[i].first ;
        else
            dist[i]+= dist[i-1] + (segment[i].second - segment[i].first) ;
    }
    
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
            dip[i] = h + 100 +(i>0 ? dip[i-1] : 0) ;
        else
            dip[i] = segment[i+1].first - segment[i].second +(i>0 ? dip[i-1] : 0) ;
    }
    
    long long int maximum = 0 ;
    for(int i=0;i<n;i++)
    {
        long long int val = h + (i>0 ? dip[i-1] : 0);
        int idx = lower_bound(dip.begin(),dip.end(),val) - dip.begin();
        if(idx>=dip.size())
            idx--;
        maximum = max(maximum , dist[idx]- (i>0 ? dist[i-1] : 0) );
       // cout<<maximum<<" "<<i<<endl;
    }
    
    cout<<maximum+h;
    
    return 0;
}

