#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node , edge ;
    cin>>node>>edge;
    vector<vector<int>>adj_list(node+1);
    int u , v ;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        adj_list[v].push_back(u);
    }
    int k;
    cin>>k;
    vector<int>path(k);
    for(int i=0;i<k;i++)
        cin>>path[i];
        
    int  destination = path[k-1] ;
    vector<int>min_distance(node+1,-1);
    vector<int>multiple_shortest_path(node+1,0);
    queue<int>Q;
    Q.push(destination);
    min_distance[destination] = 0;
    while(!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();
        for(int i=0;i<adj_list[cur_node].size();i++)
        {
            
            if(min_distance[adj_list[cur_node][i]]==-1)
            {
                //cout<<cur_node<<" "<<adj_list[cur_node][i]<<endl;
                min_distance[adj_list[cur_node][i]] = 1 + min_distance[cur_node];
                Q.push(adj_list[cur_node][i]);
            }
            else if(min_distance[adj_list[cur_node][i]]==min_distance[cur_node]+1)
                multiple_shortest_path[adj_list[cur_node][i]]++;
        }
    }
    int minimum = 0 , maximum = 0 ;

    for(int i=1;i<k;i++)
    {
        if(min_distance[path[i]]!=min_distance[path[i-1]]-1)
            minimum++;
        if(min_distance[path[i]]!=min_distance[path[i-1]]-1 || multiple_shortest_path[path[i-1]]>0)
            maximum++;
    }
    
    cout<<minimum<<" "<<maximum<<endl;
    
    return 0;
}

