#include<bits/stdc++.h>
using namespace std;

int DFS(int root , vector<vector<int>>&adj_list , vector<bool>&visited , int target)
{
    int x = 1 ;
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i] ;
        if(cur_node==target)
            continue;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            x+=DFS(cur_node,adj_list,visited,target);
        }
    }
    return x;
}

int get_nodes(int root , vector<vector<int>>&adj_list , vector<bool>&visited , int target)
{
    int x = 1 ;
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i];
        if(cur_node==target)
            continue;
        if(!visited[cur_node])
        {
            visited[cur_node] = true;
            x+=get_nodes(cur_node,adj_list,visited,target);
        }
    }
    
    return x;
}

int main()
{
    long long int node , flower , bee ;
    cin>>node>>flower>>bee;
    
    vector<vector<int>>adj_list(node+1);
    int u , v ;
    for(int i=1;i<node;i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    vector<bool>visited(node+1,false);
    visited[flower] = true ;
    int x = DFS(flower,adj_list,visited,bee);
    
    int subtree_size = node - x ;
    
    visited.clear();
    visited.resize(node+1,false);
    visited[bee] = true ;
    int available_nodes = get_nodes(bee,adj_list,visited,flower);
    
    cout<<(node*(node - 1)) - ((node - available_nodes)*subtree_size)<<endl;
    
    return 0;
}