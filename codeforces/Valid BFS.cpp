#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node ;
    cin>>node;
    
    vector<set<int>>adj_list(node+1);
    
    int u , v ;
    for(int i=1;i<node;i++)
    {
        cin>>u>>v;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    
    vector<bool>visited(node+1,false);
    vector<int>arr(node);
    for(int i=0;i<node;i++)
        cin>>arr[i];
    if(arr[0]!=1)
    {
        cout<<"NO";
        return 0;
    }
        
    visited[1] = true ;
    queue<int>Q;
    Q.push(1);
    int idx=1;
    
    while(!Q.empty() && idx<arr.size())
    {
        int root = Q.front();
        Q.pop();
        while(adj_list[root].find(arr[idx])!=adj_list[root].end() && !visited[arr[idx]])
        {
            visited[arr[idx]] = true ;
            Q.push(arr[idx]);
            idx++;
        }
    }
    bool possible =true;
    for(int i=1;i<=node;i++)
    {
        if(!visited[i])
        {
            possible = false;
            break;
        }
    }
    
    if(!possible)
        cout<<"NO";
    else
        cout<<"YES";
        
    return 0;
}
