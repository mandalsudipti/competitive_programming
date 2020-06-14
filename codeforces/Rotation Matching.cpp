#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>a_pos(n+1,0);
    vector<int>b_pos(n+1,0);
    vector<int>rotate(n+1,0);
    int val ;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        a_pos[val]=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>val;
        b_pos[val]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(b_pos[i]>=a_pos[i])
            rotate[i] = b_pos[i] - a_pos[i] ;
        else
            rotate[i] = (n-1- a_pos[i]) + b_pos[i] + 1 ;
    }
    
    map<int,int>freq;
    
    for(int i=1;i<=n;i++)
        freq[rotate[i]]++;
        
    int max_freq = 0 ;
    for(auto itr=freq.begin();itr!=freq.end();++itr)
    {
        if(itr->second>max_freq)
            max_freq = itr->second;
    }
    cout<<max_freq;
    
    return 0;
}