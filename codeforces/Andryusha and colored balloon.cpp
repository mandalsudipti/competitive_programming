#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node ;
    cin>>node;
    int u , v ;
    vector<vector<int>>adj_list(node+1);
    
    for(int i=1;i<node;i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    queue<int>Q;
    vector<int>color(node+1,0);
    map<int,int>parent;
    
    Q.push(1);
    parent[1] = 0 ;
    color[1] = 1 ;
    
    while(!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();
        
        int idx = 1 ;
        for(int i=0;i<adj_list[cur_node].size();i++)
        {
            int child = adj_list[cur_node][i] ;
            if(color[child]==0)
            {
                parent[child] = cur_node ;
                
                if(color[cur_node]==idx || color[parent[cur_node]]==idx)
                    idx++;
                if(color[cur_node]==idx || color[parent[cur_node]]==idx)
                    idx++;
                    
                color[child] = idx++;
                Q.push(child);
            }
        }
    }
    
    int k = 0 ;
    for(int i=1;i<=node;i++)
        k = max(k,color[i]);
        
    cout<<k<<endl;
    for(int i=1;i<=node;i++)
        cout<<color[i]<<" ";
        
    return 0;
}
