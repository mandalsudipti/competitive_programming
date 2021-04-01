#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , val ;
        cin>>n;
        map<int,int>freq ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            freq[val]++;
        }
        
        map<int,int>freq_ele ; // how many distinct element in freq K
        for(auto ele : freq)
            freq_ele[ele.second]++;
            
        int minimum_change = INT_MAX ;
        int prefix_sum = 0 ;
        
        for(auto itr = freq_ele.begin() ; itr != freq_ele.end() ; ++itr)
        {
            int cur_change = prefix_sum ;
            prefix_sum+=(itr->second * itr->first);
            
            map<int,int>:: iterator tmp = itr ;
            ++tmp;
            
            while(tmp != freq_ele.end())
            {
                cur_change+=((tmp->first - itr->first) * tmp->second);
                ++tmp;
            }
            minimum_change = min(minimum_change , cur_change);
        }
        
        cout<<minimum_change<<endl;
    }
    return 0;
}