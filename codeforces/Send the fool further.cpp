#include<bits/stdc++.h>
using namespace std;

vector<int>cost_at_leaf;

void DFS(vector<vector<pair<int,int>>>&adj_list , vector<bool>&visited , int root , int cost_so_far)
{
    if(adj_list[root].size()==1 && root!=0)
    {
        cost_at_leaf.push_back(cost_so_far);
        return ;
    }
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i].first , cost = adj_list[root][i].second ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            DFS(adj_list,visited,cur_node,cost_so_far+cost);
        }
    }
}

int main()
{
    int node ;
    cin>>node;
    vector<vector<pair<int,int>>> adj_list(node) ;
    
    for(int i=1;i<node;i++)
    {
        int x , y , cost ;
        cin>>x>>y>>cost;
        adj_list[x].push_back(make_pair(y,cost));
        adj_list[y].push_back(make_pair(x,cost));
    }
    
    vector<bool>visited(node,false);
    visited[0] = true ;
    int root = 0 , cost_so_far = 0;
    DFS(adj_list,visited,root,cost_so_far) ;
    
    int max_cost = 0;
    for(int i=0;i<cost_at_leaf.size();i++)
        max_cost = max(max_cost , cost_at_leaf[i]);
        
    cout<<max_cost;
    
    return 0;
}