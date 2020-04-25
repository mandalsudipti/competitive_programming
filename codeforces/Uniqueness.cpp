#include<bits/stdc++.h>
using namespace std;

bool all_zero(map<int,int>&segment)
{
    for(auto itr=segment.begin();itr!=segment.end();++itr)
    {
        if(itr->second>0)
            return false;
    }
    return true;
}

int main()
{
    int n ;
    cin>>n;
    int arr[n];
    map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    map<int,int>segment;
    for(auto itr=freq.begin();itr!=freq.end();++itr)
    {
        if(itr->second>=2)
            segment.insert(make_pair(itr->first,itr->second-1));
    }
    
    if(segment.size()==0)
    {
        cout<<"0";
        return 0;
    }
    
    int min_seg_len=n+5 ;
    queue<int>Q;
    
    for(int i=0;i<n;i++)
    {
        if(freq[arr[i]]>=2)
        {
            Q.push(i);
            segment[arr[i]]--;
            while(all_zero(segment))
            {
                min_seg_len = min(min_seg_len,Q.back()-Q.front()+1 );
                int x = Q.front();
                segment[arr[x]]++;
                Q.pop();
            }
        }
    }
    
    cout<<min_seg_len;
    return 0;
}

