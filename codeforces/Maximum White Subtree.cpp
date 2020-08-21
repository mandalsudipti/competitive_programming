#include<bits/stdc++.h>
using namespace std;

vector<int>color;
vector<bool>visited;
vector<vector<int>>adj_list;
vector<int>max_diff;

void DFS(int root)
{
    color[root]==1 ? max_diff[root] = 1 : max_diff[root] = -1 ;
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            DFS(cur_node);
            max_diff[root]+=max(0,max_diff[cur_node]);
        }
    }
}

void assign_val(int root)
{
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            int tmp = max_diff[root] ;
            if(max_diff[cur_node]>=0)
                tmp-=max_diff[cur_node];
            if(tmp>=0)
                max_diff[cur_node]+=tmp;
            assign_val(cur_node);
        }
    }
}
int main()
{
    int node ;
    cin>>node;
    color.resize(node+1);
    for(int i=1;i<=node;i++)
        cin>>color[i];
    adj_list.resize(node+1);
    for(int i=1;i<node;i++)
    {
        int u , v ;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    max_diff.resize(node+1,-10);
    visited.resize(node+1,false);
    
    visited[1] = true ;
    DFS(1);
    //for(int i=1;i<=node;i++)
        //cout<<max_diff[i]<<" ";
    visited.clear();
    visited.resize(node+1,false);
    visited[1] = true;
    assign_val(1);
    
    for(int i=1;i<=node;i++)
        cout<<max_diff[i]<<" ";
        
    return 0;
}