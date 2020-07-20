#include<bits/stdc++.h>
using namespace std;

void get_cost(vector<vector<int>>&adj_list , vector<vector<int>>&nodes_for_a_color , int idx , vector<vector<int>>&min_cost_from_node)
{
    int node = adj_list.size() , cur_node;
    vector<bool>visited(node+1,false);
    queue<int>Q;
    for(int j=0;j<nodes_for_a_color[idx].size();j++)
    {
        cur_node = nodes_for_a_color[idx][j];
        Q.push(cur_node);
        visited[cur_node] = true;
        min_cost_from_node[cur_node].push_back(0);
    }
    
    while(!Q.empty())
    {
        cur_node = Q.front();
        Q.pop();
        for(int i=0;i<adj_list[cur_node].size();i++)
        {
            if(!visited[adj_list[cur_node][i]])
            {
                visited[adj_list[cur_node][i]] = true;
                Q.push(adj_list[cur_node][i]);
                min_cost_from_node[adj_list[cur_node][i]].push_back( min_cost_from_node[cur_node].back() + 1) ;
            }
        }
    }
}

int main()
{
    int node , edge , k , min_required ;
    cin>>node>>edge>>k>>min_required;
    
    vector<int>color(node+1);
    vector<vector<int>>nodes_for_a_color(105);
    vector<vector<int>>adj_list(node+1);
    
    for(int i=1;i<=node;i++)
    {
        cin>>color[i];
        nodes_for_a_color[color[i]].push_back(i);
    }
        
    for(int i=0;i<edge;i++)
    {
        int x, y ;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    vector<vector<int>>min_cost_from_node(node+1); 
    
    for(int i=0;i<105;i++)
    {
        if(nodes_for_a_color[i].size()>0)
            get_cost(adj_list,nodes_for_a_color,i,min_cost_from_node);
    }
    
    for(int i=1;i<=node;i++)
    {
        sort(min_cost_from_node[i].begin(),min_cost_from_node[i].end());
    }
    for(int i=1;i<=node;i++)
    {
        long long int total_cost = 0 ;
        for(int j=0;j<min_required;j++)
            total_cost+=min_cost_from_node[i][j];
        cout<<total_cost<<" ";
    }
    return 0;
}
