#include<bits/stdc++.h>
using namespace std;

map<int,int>freq;

bool possible(int no_of_arr , int len , vector<int>&ans)
{
    vector<int>segment;
    for(auto itr=freq.begin();itr!=freq.end() && segment.size()<=len;++itr)
    {
        int cur_freq = (itr->second)/no_of_arr ;
        for(int i=0;i<cur_freq;i++)
            segment.push_back(itr->first);
        
    }
    if(segment.size()>=len)
    {
        ans=segment;
        return true;
    }
    return false;
}

int main()
{
    int n , k ;
    cin>>n>>k;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    vector<int>ans;
    int left=0 , right=n+1 , mid;
    while(right-left>1)
    {
        mid = (right+left)/2 ;
        if(possible(mid,k,ans))
            left=mid;
        else
            right=mid;
    }
    for(int i=0;i<k;i++)
        cout<<ans[i]<<" ";
        
    return 0;
}