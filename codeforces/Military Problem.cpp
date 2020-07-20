#include<bits/stdc++.h>
using namespace std;

int DFS(vector<set<int>>&adj_list , vector<bool>&visited , vector<int>&subtree_size , vector<int>&dfs_path , int root)
{
    subtree_size[root] = 1 ;
    for(auto itr=adj_list[root].begin();itr!=adj_list[root].end();++itr)
    {
        int node = (*itr);
        if(!visited[node])
        {
            visited[node] = true;
            dfs_path.push_back(node);
            subtree_size[root]+= DFS(adj_list,visited,subtree_size,dfs_path,node);
        }
    }
    
    return subtree_size[root];
}

int main()
{
    int node , query ;
    cin>>node>>query;
    
    vector<set<int>>adj_list(node+1) ;
    for(int i=2;i<=node;i++)
    {
        int x;
        cin>>x;
        adj_list[i].insert(x);
        adj_list[x].insert(i);
    }
    
    vector<int>subtree_size(node+1,1);
    vector<int>dfs_path;
    vector<bool>visited(node+1,false);
    
    dfs_path.push_back(1);
    visited[1]=true;

    subtree_size[1] = DFS(adj_list,visited,subtree_size,dfs_path,1);
    
    vector<int>loc_of_node_in_path(node+1);
    for(int i=0;i<dfs_path.size();i++)
    {
        loc_of_node_in_path[dfs_path[i]] = i ;
    }
    
    while(query--)
    {
        int u , k ;
        cin>>u>>k;
        if(subtree_size[u]<k)
            cout<<"-1"<<endl;
        else
        {
            int idx = loc_of_node_in_path[u] + (k-1);
            cout<<dfs_path[idx]<<endl;
        }
    }
        
    return 0;
}
