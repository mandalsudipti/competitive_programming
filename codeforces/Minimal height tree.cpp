#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        vector<pair<int,int>>sibling ;
        sibling.push_back(make_pair(0,0));
        int start = 1 , end = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
                end = i ;
            else
            {
                sibling.push_back(make_pair(start,end));
                start = end = i ;
            }
        }
        sibling.push_back(make_pair(start,end));
        
        vector<int>level(sibling.size(),0);
        int idx = 0 , parent_level = -1 , cur_step = 1 , next_step = 0 ;
        
        while(idx<sibling.size())
        {
            level[idx] = parent_level + 1 ;
            cur_step--;
            next_step+=(sibling[idx].second - sibling[idx].first + 1);
            idx++;
            if(cur_step==0)
            {
                cur_step = next_step ;
                next_step = 0 ;
                parent_level++;
            }
        }
        
        //for(int i=0;i<level.size();i++)
            //cout<<level[i]<<" ";
        cout<<level.back()<<endl;
        
    }
    
    return 0;
}