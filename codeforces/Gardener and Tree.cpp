#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int node , step ;
        cin>>node>>step ;
        
        vector<vector<int>>adj_list(node + 1) ;
        vector<int>degree(node + 1) ;
        vector<bool>visited(node + 1 , false) ;
        
        int u , v ;
        for(int i = 1 ; i < node ; i++)
        {
            cin>>u>>v ;
            adj_list[u].push_back(v) ;
            adj_list[v].push_back(u) ;
            degree[u]++ ;
            degree[v]++ ;
        }
        
        queue<int>Q ;
        for(int i = 1 ; i <= node ; i++)
        {
            if(degree[i] <= 1)
                Q.push(i) ;
        }
        
        while(!Q.empty() && step > 0)
        {
            step-- ;
            int s = Q.size() ;
            for(int i = 0 ; i < s ; i++)
            {
                int cur_node = Q.front() ;
                Q.pop() ;
                visited[cur_node] = true ;
                
                for(int child : adj_list[cur_node])
                {
                    if(!visited[child])
                    {
                        degree[child]-- ;
                        if(degree[child] == 1)
                        {
                            Q.push(child) ;
                        }
                    }
                }
            }
        }
        
        int remaining_nodes = 0 ;
        for(int i = 1 ; i <= node ; i++)
        {
            if(!visited[i])
                remaining_nodes++ ;
        }
        
        cout<<remaining_nodes<<endl;
    }
    
    return 0 ;
}