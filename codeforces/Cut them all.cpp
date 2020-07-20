#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&adj_list , vector<bool>&visited , vector<int>&subtree_size , int root)
{
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i];
        if(!visited[cur_node])
        {
            visited[cur_node]=true;
            DFS(adj_list,visited,subtree_size,cur_node);
            subtree_size[root]+=subtree_size[cur_node];
        }
    }
}

int main()
{
    int node ;
    cin>>node ;
    vector<vector<int>>adj_list(node+1);
    
    for(int i=1;i<node;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    if(node%2==1)
    {
        cout<<"-1";
        return 0;
    }
    vector<bool>visited(node+1,false);
    vector<int>subtree_size(node+1,1);
    
    visited[1]=true;
    DFS(adj_list,visited,subtree_size,1);
    
    int cnt = 0 ;
    for(int i=2;i<=node;i++)
    {
        if(subtree_size[i]%2==0)
            cnt++;
    }
    
    cout<<cnt;
    return 0;
}