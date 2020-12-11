#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n , m ;
    cin>>n>>m ;
    vector<int>arr(n);
    map<int,vector<int>>occur ;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        occur[arr[i]].push_back(i);
    }
        
    vector<pair<int,int>>segment ;
    vector<int>left_nearest(n,-1);
    vector<int>right_nearest(n,-1);
    
    int start = 0 , end = 0 ;
    for(int i=1;i<n;i++)
    {
        if(arr[i] == arr[start])
            end = i ;
        else
        {
            segment.push_back(make_pair(start , end));
            start = end = i ;
        }
    }
    segment.push_back(make_pair(start , end));
    
    for(int i=0;i<segment.size();i++)
    {
        for(int j=segment[i].first ; j <= segment[i].second ; j++)
        {
            if(i > 0)
                left_nearest[j] = segment[i].first - 1 ;
            if(i < segment.size() -1)
                right_nearest[j] = segment[i].second + 1 ;
        }
    }
    
    
    while(m--)
    {
        int left , right , num ;
        cin>>left>>right>>num;
        
        left--;
        right--;
        
        int idx = lower_bound(occur[num].begin() , occur[num].end() , left) - occur[num].begin() ;
        if(idx >= occur[num].size() || occur[num][idx] > right)
        {
            cout<<left+1<<"\n";
        }
        else
        {
            int tmp = occur[num][idx] ;
            if(right_nearest[tmp] <= right && right_nearest[tmp]!=-1)
            {
                cout<<right_nearest[tmp]+1<<"\n";
            }
            else if(left_nearest[tmp] >= left)
            {
                cout<<left_nearest[tmp]+1<<"\n";
            }
            else
                cout<<"-1"<<"\n";
            
        }
    }
    
    return 0;
}

