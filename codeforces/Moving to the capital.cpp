#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&adj_list , int node , vector<bool>&visited ,vector<int>&distance_from_root , vector<int>&ans)
{
    int cur_ans = distance_from_root[node] ;
    for(int i = 0 ; i < adj_list[node].size() ; i++)
    {
        int child = adj_list[node][i] ;
        if(distance_from_root[child] <= distance_from_root[node])
            cur_ans = min(cur_ans , distance_from_root[child]);
        else
        {
            if(visited[child])
                cur_ans = min ( cur_ans , ans[child]);
            else
            {
                visited[child] = true ;
                DFS(adj_list , child , visited , distance_from_root , ans);
                cur_ans = min(cur_ans , ans[child]);
            }
        }
    }
    ans[node] = cur_ans ;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int node , edge  ;
        cin>>node>>edge;
        
        vector<vector<int>>adj_list(node + 1);
        int u , v ;
        for(int i = 1 ; i <= edge ; i++)
        {
            cin>>u>>v ;
            adj_list[u].push_back(v);
        }
        vector<bool>visited(node+1 , false);
        vector<int>distance_from_root(node + 1) ;
        
        visited[1] = true ;
        distance_from_root[1] = 0 ;
        queue<int>Q ;
        Q.push(1) ;
        
        while(!Q.empty())
        {
            int cur_node = Q.front() ;
            Q.pop();
            for(int i = 0 ; i < adj_list[cur_node].size() ; i++)
            {
                int child = adj_list[cur_node][i] ;
                if(!visited[child])
                {
                    visited[child] = true ;
                    distance_from_root[child] = distance_from_root[cur_node] + 1 ;
                    Q.push(child);
                }
            }
        }
        
        visited.clear() ;
        visited.resize(node + 1 , false);
        vector<int>ans(node+1);
        ans[1] = 0 ;
        visited[1] = true;
        
        for(int i = 2 ; i <= node ; i++)
        {
            if(!visited[i])
            {
                visited[i] = true ;
                DFS(adj_list , i , visited , distance_from_root ,ans);
            }
        }
        
        for(int i = 1 ; i <= node ; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}