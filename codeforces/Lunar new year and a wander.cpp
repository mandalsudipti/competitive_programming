#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<set<int>>adj_matrix(node+1);
    vector<bool>visited(node+1,false);
    
    for(int i=0;i<edge;i++)
    {
        int x , y ;
        cin>>x>>y;
        if(x!=y)
        {
            adj_matrix[x].insert(y);
            adj_matrix[y].insert(x);
        }
    }
    
    vector<int>path;
    priority_queue<int>Q;
    Q.push(-1);
    visited[1]=true;
    
    while(!Q.empty())
    {
        int x = (Q.top())*(-1);
        //cout<<x<<endl;
        Q.pop();
        path.push_back(x);
        for(auto itr=adj_matrix[x].begin();itr!=adj_matrix[x].end();++itr)
        {
            int y = (*itr);
            if(!visited[y])
            {
                Q.push(y*(-1));
                visited[y]=true;
            }
        }
    }
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<" ";
        
    return 0;
}