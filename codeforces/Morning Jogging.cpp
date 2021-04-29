#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , m ;
        cin>>n>>m ;
        
        vector<vector<int>>len(n , vector<int>(m));
        multiset<int>minimum ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                cin>>len[i][j];
                minimum.insert(len[i][j]);
            }
        }
        
        while(minimum.size() > m)
            minimum.erase(--minimum.end());
            
        vector<vector<int>>ans(n , vector<int>(m , 0));
        int idx = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(minimum.size() > 0 && minimum.find(len[i][j]) != minimum.end())
                {
                    minimum.erase(minimum.lower_bound(len[i][j]));
                    ans[i][idx] = len[i][j];
                    len[i][j] = (len[i][j] * (-1));
                    idx++;
                }
            }
            int col = 0 ;
            for(int j = 0 ; j < m ; j++)
            {
                if(len[i][j] < 0)
                    continue ;
                while(ans[i][col] != 0)
                    col++;
                ans[i][col] = len[i][j] ;
            }
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0 ;
}
