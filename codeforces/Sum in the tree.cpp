#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000000005;
vector<int>parent;
vector<long long int>sum;
vector<long long int>val;
vector<bool>visited;

bool DFS(int root , vector<vector<int>>&adj_list)
{
    if(root==1)
    {
        val[root] = sum[root];
        if(sum[root]==-1)
            return false;
    }
    if(val[root]>=0 && sum[root]>=0) // level odd
    {
        for(int i=0;i<adj_list[root].size();i++)
        {
            int cur_node = adj_list[root][i] ;
            if(!visited[cur_node])
            {
                visited[cur_node] = true ;
                bool valid = DFS(cur_node,adj_list);
                if(!valid)
                    return false;
            }
        }
    }
    else if(val[root]<0 && sum[root]<0) // level even
    {
        long long int minimum = MAX ;
        for(int i=0;i<adj_list[root].size();i++)
        {
            if(!visited[adj_list[root][i]])
            {
                minimum = min(minimum , sum[adj_list[root][i]]);
            }
        }
        //cout<<minimum<<" "<<sum[parent[root]]<<endl;
        if(minimum<sum[parent[root]])
            return false;
            
        val[root] = minimum - sum[parent[root]];
        sum[root] = sum[parent[root]] + val[root] ;
        
        if(minimum==MAX)
        {
            val[root] = 0;
            sum[root] = sum[parent[root]];
        }
        
        for(int i=0;i<adj_list[root].size();i++)
        {
            int cur_node = adj_list[root][i] ;
            if(!visited[cur_node])
            {
                visited[cur_node] = true ;
                val[cur_node] = sum[cur_node] - sum[root] ;
                bool valid = DFS(cur_node,adj_list);
                if(!valid)
                    return false;
            }
        }
    }
    else
        return false;
        
    return true;

}

int main()
{
    int node ;
    cin>>node;
    
    parent.resize(node+1,0);
    sum.resize(node+1,0);
    val.resize(node+1,-100);
    visited.resize(node+1,false);
    
    vector<vector<int>>adj_list(node+1);
    
    for(int i=2;i<=node;i++)
    {
        cin>>parent[i];
        adj_list[i].push_back(parent[i]);
        adj_list[parent[i]].push_back(i);
    }
    for(int i=1;i<=node;i++)
        cin>>sum[i];
        
    visited[1] = true ;
    
    bool valid = DFS(1,adj_list);
    if(!valid)
        cout<<"-1";
    else
    {
        long long int ans = 0;
        for(int i=1;i<=node;i++)
            ans+=val[i];
        cout<<ans;
    }
    
    return 0;
}