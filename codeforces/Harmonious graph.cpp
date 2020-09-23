#include<bits/stdc++.h>
using namespace std;

void DFS(int node , vector<vector<int>>&adj_list , vector<int>&visited , int cnt)
{
    for(int i=0;i<adj_list[node].size();i++)
    {
        int cur_node = adj_list[node][i];
        if(visited[cur_node]==0)
        {
            visited[cur_node] = cnt ;
            DFS(cur_node,adj_list,visited,cnt);
        }
    }
}

int main()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<vector<int>>adj_list(node+1);
    int u , v ;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    vector<int>visited(node+1,0);
    int cnt = 0 ;
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0 && adj_list[i].size()>=1)
        {
            visited[i] = (++cnt);
            DFS(i,adj_list,visited,cnt);
        }
    }
    
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
            visited[i]=(++cnt);
    }
    vector<pair<int,int>>min_max(cnt+1,make_pair(0,0));
    for(int i=1;i<=node;i++)
    {
        min_max[visited[i]].second = i ;
        if(min_max[visited[i]].first==0)
            min_max[visited[i]].first = i ;
    }
    
    //for(int i=1;i<min_max.size();i++)
        //cout<<min_max[i].first<<" "<<min_max[i].second<<endl;
        
    sort(min_max.begin(),min_max.end());
    int left = min_max[1].first , right = min_max[1].second;
    vector<pair<int,int>>component;
    
    for(int i=2;i<min_max.size();i++)
    {
        if(min_max[i].first<right)
            right=max(min_max[i].second,right);
        if(min_max[i].first>right || i==min_max.size()-1)
        {
            component.push_back(make_pair(left,right));
            left = min_max[i].first;
            right = min_max[i].second;
        }
    }
    
    int add_edge = 0 ;
    for(int i=0;i<component.size();i++)
    {
        int left = component[i].first , right = component[i].second ;
        set<int>X;
        for(int j=left;j<=right;j++)
            X.insert(visited[j]);
        add_edge+=(X.size()-1);
    }
    
    cout<<add_edge<<endl;
    
    return 0;
}

