#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<vector<int>>adj_matrix(node+1);
    vector<bool>visited(node+1,false);
    
    for(int i=0;i<edge;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_matrix[x].push_back(y);
        adj_matrix[y].push_back(x);
    }
    
    int root_node = 1;
    queue<int>Q;
    
    for(int i=1;i<=node;i++)
    {
        if(adj_matrix[i].size()> adj_matrix[root_node].size())
            root_node = i ;
    }
    Q.push(root_node);
    visited[root_node]=true;
    
    vector<pair<int,int>>ans;
    
    while(!Q.empty())
    {
        int x = Q.front() ;
        Q.pop();
        for(int i=0;i<adj_matrix[x].size();i++)
        {
            if(!visited[adj_matrix[x][i]])
            {
                Q.push(adj_matrix[x][i]);
                visited[adj_matrix[x][i]]=true;
                ans.push_back(make_pair(x,adj_matrix[x][i]));
            }
        }
    }
    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
        
    return 0;
}