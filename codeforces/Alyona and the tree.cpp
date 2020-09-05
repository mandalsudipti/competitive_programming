#include<bits/stdc++.h>
using namespace std;

void DFS(int root,vector<vector<int>>&adj_list,vector<bool>&visited,vector<long long int>&node_cost,map<pair<int,int>,long long int>&edge_cost,long long int total_cost)
{
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i] ;
        if(visited[cur_node] || node_cost[cur_node]<max(total_cost,0ll)+edge_cost[make_pair(root,cur_node)])
            continue;
        visited[cur_node] = true ;
        DFS(cur_node,adj_list,visited,node_cost,edge_cost,edge_cost[make_pair(root,cur_node)]+max(total_cost,0ll) );
    }
}

int main()
{
    int node ;
    cin>>node;
    
    vector<long long int>node_cost(node+1);
    for(int i=1;i<=node;i++)
        cin>>node_cost[i];
        
    map<pair<int,int>,long long int>edge_cost;
    vector<vector<int>>adj_list(node+1);
    
    int u , v , cost ;
    for(int i=1;i<node;i++)
    {
        cin>>v>>cost;
        u = i+1 ;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        edge_cost[make_pair(u,v)] = cost ;
        edge_cost[make_pair(v,u)] = cost ;
    }
    vector<bool>visited(node+1,false);
    visited[1] = true ;
    long long int total_cost = 0 ;
    DFS(1,adj_list,visited,node_cost,edge_cost,total_cost);
    
    int removed_node = 0 ;
    for(int i=1;i<=node;i++)
    {
        if(!visited[i])
            removed_node++;
    }
    
    cout<<removed_node<<endl;
    
    return 0;
}