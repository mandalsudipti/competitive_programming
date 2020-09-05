#include<bits/stdc++.h>
using namespace std;

void DFS(int source , vector<vector<int>>&adj_list , vector<bool>&visited)
{
    for(int i=0;i<adj_list[source].size();i++)
    {
        int cur_node = adj_list[source][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            DFS(cur_node,adj_list,visited);
        }
    }
}

int main()
{
    int snack , guest ;
    cin>>snack>>guest;
    
    vector<vector<int>>adj_list(snack+1);
    vector<bool>visited(snack+1,false);
    
    int x , y ;
    for(int i=0;i<guest;i++)
    {
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    int component = 0 ;
    for(int i=1;i<=snack;i++)
    {
        if(!visited[i])
        {
            component++;
            visited[i] = true ;
            DFS(i,adj_list,visited);
        }
    }
    
    cout<<guest - (snack - component)<<endl;
    
    return 0;
}