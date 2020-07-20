#include<bits/stdc++.h>
using namespace std;

int DFS(vector<vector<int>>&adj_list , vector<bool>&visited , vector<int>&count_leaf , int root)
{
    for(int i=0;i<adj_list[root].size();i++)
    {
        int node = adj_list[root][i];
        if(!visited[node])
        {
            visited[node]=true;
            count_leaf[root]+=DFS(adj_list,visited,count_leaf,node);
        }
    }
    if(count_leaf[root]==0)
        count_leaf[root]=1;
        
    return count_leaf[root];
}

int main()
{
    int node ;
    cin>>node;
    
    vector<vector<int>>adj_list(node+1);
    for(int i=2;i<=node;i++)
    {
        int x;
        cin>>x;
        adj_list[x].push_back(i);
        adj_list[i].push_back(x);
    }
    vector<int>count_leaf(node+1,0);
    vector<bool>visited(node+1,false);
    
    visited[1]=true;
    count_leaf[1] = DFS(adj_list,visited,count_leaf,1);
    
    if(count_leaf[1]==0)
        count_leaf[1]=1;
        
    sort(count_leaf.begin(),count_leaf.end());
    
    for(int i=1;i<=node;i++)
        cout<<count_leaf[i]<<" ";
        
    return 0;
}