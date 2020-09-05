#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<vector<int>>adj_list(node+1);
    vector<int>parity(node+1);
    vector<bool>visited(node+1,false);
    
    int u , v ;
    for(int i=1;i<=edge;i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    queue<int>Q;
    Q.push(1);
    visited[1] = true ;
    parity[1] = 0 ;
    
    while(!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();
        for(int i=0;i<adj_list[cur_node].size();i++)
        {
            if(!visited[adj_list[cur_node][i]])
            {
                visited[adj_list[cur_node][i]] = true ;
                parity[adj_list[cur_node][i]] = (parity[cur_node] + 1)%2;
                Q.push(adj_list[cur_node][i]);
            }
        }
    }
    
    int cnt_zero = 0 , cnt_one = 0 ;
    for(int i=1;i<=node;i++)
        parity[i]==0 ? cnt_zero++ : cnt_one++;
        
    if(cnt_zero<=(node/2))
    {
        cout<<cnt_zero<<endl;
        for(int i=1;i<=node;i++)
        {
            if(parity[i]==0)
                cout<<i<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<cnt_one<<endl;
        for(int i=1;i<=node;i++)
        {
            if(parity[i]==1)
                cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}