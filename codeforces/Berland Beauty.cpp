#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>beauty(5005,vector<int>(5005,0));

bool sort_by_beauty(const vector<int>&A , const vector<int>&B)
{
    return A[2]<B[2];
}

bool assign_val(int source , int destination , vector<vector<int>>&adj_list , vector<bool>&visited , int min_beauty)
{
    if(source==destination)
        return true;
    for(int i=0;i<adj_list[source].size();i++)
    {
        int cur_node = adj_list[source][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            if(assign_val(cur_node,destination,adj_list,visited,min_beauty))
            {
                beauty[source][cur_node] = beauty[cur_node][source] = min_beauty ;
                return true;
            }
        }
    }
    return false;
}

bool get_path(int source , int destination , vector<vector<int>>&adj_list , vector<bool>&visited , vector<int>&path)
{
    if(source==destination)
    {
        path.push_back(destination);
        return true;
    }
    for(int i=0;i<adj_list[source].size();i++)
    {
        int cur_node = adj_list[source][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            if(get_path(cur_node,destination,adj_list,visited,path))
            {
                path.push_back(source);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int node ;
    cin>>node;
    vector<vector<int>>adj_list(node+1);
    vector<pair<int,int>>edge;
    for(int i=1;i<node;i++)
    {
        int u , v ;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        edge.push_back(make_pair(u,v));
    }
    
    int query;
    cin>>query;
    vector<vector<int>>arr(query,vector<int>(3));
    for(int i=0;i<query;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    sort(arr.begin(),arr.end(),sort_by_beauty);
    
    vector<bool>visited(node+1,false);
    for(int i=0;i<query;i++)
    {
        visited[arr[i][0]] = true ;
        bool flag = assign_val(arr[i][0],arr[i][1],adj_list,visited,arr[i][2]);
        visited.clear();
        visited.resize(node+1,false);
    }
    
    vector<int>path;
    for(int i=0;i<query;i++)
    {
        visited[arr[i][0]] = true ;
        bool flag = get_path(arr[i][0],arr[i][1] ,adj_list,visited,path);
        int cnt = 0 ;
        for(int j=path.size()-1;j>0;j--)
        {
            int l = path[j] ,  r = path[j-1] ;
            if(beauty[l][r]==arr[i][2])
                cnt++;
        }
        if(cnt<1)
        {
            cout<<"-1";
            return 0;
        }
        path.clear();
        visited.clear();
        visited.resize(node+1,false);
    }
    
    for(int i=0;i<node-1;i++)
    {
        beauty[edge[i].first][edge[i].second]==0 ? cout<<"1000000 " : cout<<beauty[edge[i].first][edge[i].second]<<" ";
    }
    
    return 0;
}