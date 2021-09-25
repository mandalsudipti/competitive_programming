#include<bits/stdc++.h>
using namespace std ;

void traverse(int root , vector<vector<int>>& adj_list , vector<bool>& visited , vector<bool>& is_leaf , vector<bool>& is_bud)
{
    int count_leaf = 0 , count_bud = 0 , count_child = 0 ;
    visited[root] = true ;
    
    for(int child : adj_list[root])
    {
        if(visited[child])
            continue ;
            
        traverse(child , adj_list , visited , is_leaf , is_bud) ;
            
        count_child++ ;
        if(is_bud[child])
            count_bud++ ;
        if(is_leaf[child])
            count_leaf++;
    }
    
    if( (count_child == 0 || count_child == count_bud) && root != 1)
        is_leaf[root] = true ;
        
    if(count_leaf >= 1 && root != 1)
        is_bud[root] = true ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<vector<int>>adj_list(n+1) ;
        int u , v ;
        
        for(int i = 1 ; i < n ; i++)
        {
            cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        vector<bool>is_bud(n+1,false) , is_leaf(n+1,false) , visited(n+1 , false);
        
        traverse(1 , adj_list , visited , is_leaf , is_bud) ;
        
        int resultant_leaf = 0 ;
        for(int i = 1 ; i <= n ; i++)
        {
            if(is_leaf[i])
                resultant_leaf++ ;
            if(is_bud[i])
                resultant_leaf-- ;
        }
        bool root_has_leaf = false ;
        for(int child : adj_list[1])
        {
            if(is_leaf[child])
            {
                root_has_leaf = true ;
                break;
            }
        }
        
        if(!root_has_leaf)
            resultant_leaf++ ;
            
        cout<<resultant_leaf<<endl;
    }
    
    return 0 ;
}