#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        
        vector<int>num(n) ;
        map<int,set<int>>loc ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>num[i] ;
            loc[num[i]].insert(i) ;
        }
        
        vector<int>ans(n,0);
        int total = 0 ;
        for(auto itr = loc.begin() ; itr != loc.end() ; ++itr)
        {
            while(itr->second.size() > k)
                itr->second.erase(itr->second.begin());
            total+=(itr->second.size());
        }
        
        for(auto itr = loc.begin() ; itr != loc.end() ; ++itr)
        {
            while(total % k != 0 && itr->second.size() > 0)
            {
                total--;
                itr->second.erase(itr->second.begin());
            }
        }
        
        int cur_color = 0 ;
        for(auto itr = loc.begin() ; itr != loc.end() ; ++itr)
        {
            for(int cur_loc : itr->second)
            {
                cur_color++ ;
                if(cur_color > k)
                    cur_color = 1 ;
                    
                ans[cur_loc] = cur_color ;
            }
        }
        
        for(int i = 0 ; i < n ; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0 ;
}