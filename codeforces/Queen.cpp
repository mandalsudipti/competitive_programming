#include<bits/stdc++.h>
using namespace std ;

void DFS(vector<vector<int>>& adj_list , int root , set<int>& deleted_nodes , vector<bool>& C , int tree_root)
{
    bool possible = true ;
    for(int child : adj_list[root])
    {
        //cout<<root<<" "<<child<<endl;
        DFS(adj_list , child , deleted_nodes , C , tree_root) ;
        if(C[child] == false)
            possible = false ;
    }
    
    if(possible && C[root] && root != tree_root)
        deleted_nodes.insert(root) ;
}

int main()
{
    int n ;
    cin>>n;
    
    vector<bool>C(n+1,false) ;
    vector<int>parent(n+1,-1) ;
    
    vector<vector<int>>adj_list(n+1);
    int root = -1 ;
    
    for(int i = 1 ; i <= n ; i++)
    {
        int c ;
        cin>>parent[i]>>c ;
        
        if(parent[i] == -1)
            root = i ;
        else
            adj_list[parent[i]].push_back(i) ;
        if(c == 1)
            C[i] = true ;
    }
    
    set<int>deleted_nodes ;
    DFS(adj_list , root , deleted_nodes , C , root) ;
    
    for(int node : deleted_nodes)
        cout<<node<<" ";
        
    if(deleted_nodes.size() == 0)
        cout<<"-1";
        
    return 0 ;
}