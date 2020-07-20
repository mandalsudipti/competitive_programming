#include<bits/stdc++.h>
using namespace std;

vector<long double> exp_at_leaf;

void DFS(vector<vector<int>>&adj_list , vector<bool>&visited , int root , int distance , long double prob)
{
    if(adj_list[root].size()==1 && root!=1)
    {
        exp_at_leaf.push_back(prob*distance);
        //cout<<root<<" "<<prob<<" "<<distance<<endl;
        return ;
    }
    
    long double x  = adj_list[root].size() ;
    if(root!=1)
        x-=1;
        
    prob = prob/x ;
    
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i];
        if(!visited[cur_node])
        {
            visited[cur_node]=true;
            DFS(adj_list,visited,cur_node,distance+1,prob);
        }
    }
}

int main()
{
    int node ;
    cin>>node;
    
    vector<vector<int>>adj_list(node+1);
    for(int i=1;i<node;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    if(node==1)
    {
        cout<<"0";
        return 0;
    }
    vector<bool>visited(node+1,false);
    int root = 1 ;
    visited[root] = true;
    long double x = adj_list[root].size() , prob = 1 ;
    DFS(adj_list,visited,root,0,prob);
    
    long double ans = 0 ;
    for(int i=0;i<exp_at_leaf.size();i++)
        ans+=exp_at_leaf[i];
    
    cout<<fixed<<setprecision(12)<<ans;
    
    return 0;
}
