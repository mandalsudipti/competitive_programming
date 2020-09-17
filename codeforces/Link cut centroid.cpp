#include<bits/stdc++.h>
using namespace std;

int DFS(int root , vector<vector<int>>&adj_list , vector<bool>&visited , vector<int>&centroid,vector<int>&parent)
{
    int subtree_size = 1 ;
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i];
        if(!visited[cur_node])
        {
            parent[cur_node] = root;
            visited[cur_node] = true ;
            int tmp = DFS(cur_node,adj_list,visited,centroid,parent);
            subtree_size+=tmp;
            centroid[root] = max(centroid[root],tmp);
        }
    }
    
    centroid[root] = max((int)(adj_list.size()-1) - subtree_size  , centroid[root]) ;
    return subtree_size;
}


void cut_leaf(int node1 , int node2 , vector<vector<int>>&adj_list,vector<int>&parent)
{
    
    for(int i=0;i<adj_list[node1].size();i++)
    {
        int cur_node = adj_list[node1][i];
        if(cur_node==parent[node1])
            continue;
        else
        {
            cut_leaf(cur_node,node2,adj_list,parent);
            return;
        }
    }
    
    if(adj_list[node1].size()==1)
    {
        cout<<parent[node1]<<" "<<node1<<endl;
        if(node2!=-1)
            cout<<node1<<" "<<node2<<endl;
        else
            cout<<node1<<" "<<parent[node1]<<endl;
    }
}

void solve()
{
    int node ;
    cin>>node;
    vector<vector<int>>adj_list(node+1);
    int x , y ;
    for(int i=1;i<node;i++)
    {
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    vector<int>centroid(node+1,0);
    vector<bool>visited(node+1,false);
    vector<int>parent(node+1,0);
    visited[1] = true ;
    int  val= DFS(1,adj_list,visited,centroid,parent);
    
    int minimum = node+100 ;
    for(int i=1;i<=node;i++)
        minimum = min(minimum,centroid[i]);
        
    int node1 = -1 , node2 = -1 ;
    for(int i=1;i<=node;i++)
    {
        //cout<<i<<" "<<centroid[i]<<endl;
        if(centroid[i]==minimum)
        {
            if(node1==-1)
                node1 = i ;
            else
                node2 = i ;
        }
    }
    if(node2!=-1)
    {
        int tmp = node2 ;
        while(parent[tmp]!=0)
        {
            tmp = parent[tmp] ;
            if(tmp==node1)
            {
                swap(node1,node2);
                break;
            }
        }
    }
    cut_leaf(node1,node2,adj_list,parent);
    //cout<<"----------------------------"<<endl;
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