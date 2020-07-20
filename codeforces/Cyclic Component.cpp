#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&adj_list , vector<bool>&visited , int root , vector<int>&component)
{
    component.push_back(root);
    
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i];
        //cout<<cur_node<<" "<<visited[cur_node]<<endl;
        if(!visited[cur_node])
        {
            visited[cur_node] = true;
            //cout<<cur_node<<" "<<visited[cur_node]<<endl;
            DFS(adj_list,visited,cur_node,component);
        }
    }
}

int main()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<vector<int>>adj_list(node+1);
    
    for(int i=1;i<=edge;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    vector<bool>visited(node+1,false);
    int cnt_cycle = 0;
    
    for(int i=1;i<=node;i++)
    {
        if(!visited[i])
        {
            //cout<<i<<endl;
            visited[i] = true;
            vector<int>component;
            DFS(adj_list,visited,i,component);
            
            bool possible = true;
            for(int j=0;j<component.size();j++)
            {
                if(adj_list[component[j]].size()!=2)
                {
                    possible = false;
                    break;
                }
            }
            if(possible)
                cnt_cycle++;
        }
    }
    
    cout<<cnt_cycle;
    
    return 0;
}