#include<bits/stdc++.h>
using namespace std;

const int incoming = 1 , outgoing = -1 ;

int main()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<vector<int>>arr(edge,vector<int>(2));
    vector<vector<int>>adj_list(node+1);
    vector<bool>visited(node+1,false);
    vector<int>node_type(node+1,0);
    
    for(int i=0;i<edge;i++)
    {
        cin>>arr[i][0]>>arr[i][1] ;
        adj_list[arr[i][0]].push_back(arr[i][1]);
        adj_list[arr[i][1]].push_back(arr[i][0]);
    }
    
    queue<int>Q;
    Q.push(1);
    visited[1] = true ;
    node_type[1] = incoming ;
    
    while(!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();
        
        for(int i=0;i<adj_list[cur_node].size();i++)
        {
            int x = adj_list[cur_node][i] ;
            if(visited[x] && node_type[x]==node_type[cur_node])
            {
                cout<<"NO";
                return 0;
            }
            else if(!visited[x])
            {
                visited[x] = true ;
                Q.push(x);
                node_type[cur_node]==incoming ? node_type[x] = outgoing : node_type[x] = incoming ;
            }
        }
    }
    
    cout<<"YES"<<endl;
    for(int i=0;i<edge;i++)
    {
        int x = arr[i][0] ;
        node_type[x]==outgoing ? cout<<"0" : cout<<"1";
    }
    
    return 0;
}