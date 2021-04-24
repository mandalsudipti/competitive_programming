#include<bits/stdc++.h>
using namespace std ;

void traverse(int root , vector<vector<int>>& adj_list , vector<bool>& visited , vector<int>& leaf_count)
{
    if(adj_list[root].size() == 1 && root != 1)
    {
        leaf_count[root] = 1 ;
        return ;
    }
    
    for(int child : adj_list[root])
    {
        if(!visited[child])
        {
            visited[child] = true ;
            traverse(child , adj_list , visited , leaf_count);
            leaf_count[root]+=leaf_count[child] ;
        }
    }
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    
    int T ;
    cin>>T;
    while(T--)
    {
        long long int n , sum ;
        cin>>n>>sum;
        vector<vector<long long int>>edge_weight ;
        vector<vector<int>>adj_list(n+1) ;
        
        for(int i = 1 ; i < n ; i++)
        {
            int x , y , weight ;
            cin>>x>>y>>weight ;
            edge_weight.push_back({x,y,weight}) ;
            adj_list[x].push_back(y) ;
            adj_list[y].push_back(x) ;
        }
        vector<int>leaf_count(n+1,0);
        vector<bool>visited(n+1,false);
        visited[1] = true ;
        traverse(1,adj_list,visited,leaf_count);
        
        set<pair<long long int,int>>edge_contribution ;
        
        long long int total_cost = 0 ;
        for(int i = 0 ; i < edge_weight.size() ; i++)
        {
            long long int tmp = min(leaf_count[edge_weight[i][0]] , leaf_count[edge_weight[i][1]]) ;
            edge_contribution.insert(make_pair(edge_weight[i][2]*tmp - tmp*(edge_weight[i][2]/2),i));
            total_cost+=(edge_weight[i][2] * tmp);
        }
        
        int move = 0 ;
        while(total_cost > sum)
        {
            move++ ;
            long long int reduce = (*edge_contribution.rbegin()).first ;
            int idx = (*edge_contribution.rbegin()).second ;
            total_cost-=reduce ;
            edge_contribution.erase(--edge_contribution.end());
            edge_weight[idx][2] = edge_weight[idx][2]/2 ;
            long long int tmp = min(leaf_count[edge_weight[idx][0]] , leaf_count[edge_weight[idx][1]]) ;
            edge_contribution.insert(make_pair(edge_weight[idx][2]*tmp - tmp*(edge_weight[idx][2]/2),idx));
        }
        
        cout<<move<<endl;
    }
    
    return 0 ;
}


