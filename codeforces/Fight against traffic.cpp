#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&adj_list , vector<long long int>&distance , int root)
{
    int node = adj_list.size();
    vector<bool>visited(node,false);
    queue<int>Q;
    Q.push(root);
    visited[root]=true;
    distance[root] = 0 ;
    
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for(int i=0;i<adj_list[x].size();i++)
        {
            int cur_node = adj_list[x][i] ;
            if(!visited[cur_node])
            {
                visited[cur_node] = true ;
                Q.push(cur_node);
                distance[cur_node] = distance[x] + 1 ;
            }
        }
    }
}

int main()
{
    int node , edge , source , destination ;
    cin>>node>>edge>>source>>destination;
    
    vector<vector<int>>adj_list(node+1);
    vector<set<int>>is_edge(node+1);
    
    for(int i=0;i<edge;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
        is_edge[x].insert(y);
        is_edge[y].insert(x);
    }
    
    vector<long long int>distance_from_source(node+1,0);
    vector<long long int>distance_from_destination(node+1,0);
    
    BFS(adj_list,distance_from_source,source);
    BFS(adj_list , distance_from_destination,destination);
    
    int min_distance = distance_from_source[destination] ;
    
    long long int cnt = 0 ;
    for(int i=1;i<=node;i++)
    {
        for(int j=i+1;j<=node;j++)
        {
            if(is_edge[i].find(j)!=is_edge[i].end())
                continue;
            long long int d1 = distance_from_source[i] + distance_from_destination[j] + 1;
            long long int d2 = distance_from_destination[i] + distance_from_source[j] + 1;
            if(d1>=min_distance && d2>=min_distance)
                cnt++;
        }
    }
    
    cout<<cnt;
    
    return 0;
}



