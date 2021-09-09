#include<bits/stdc++.h>
using namespace std ;

void traverse(int node , vector<vector<int>>& adj_list , vector<pair<long long int ,long long int>>& range , vector<long long int>& left_val , vector<long long int>& right_val , vector<bool>& visited)
{
    visited[node] = true ;
    
    for(int child : adj_list[node])
    {
        if(visited[child])
            continue ;
            
        traverse(child , adj_list , range , left_val , right_val , visited) ;
        long long int a = left_val[child] , b = right_val[child] ;
        left_val[node]+=max(abs(range[node].first - range[child].first) + a , abs(range[node].first - range[child].second) + b);
        right_val[node]+=max(abs(range[node].second - range[child].first) + a , abs(range[node].second - range[child].second) + b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<pair<long long int,long long int>>range(n+1 , make_pair(0,0)) ;
        for(int i = 1 ; i <= n ;i++)
            cin>>range[i].first>>range[i].second ;
            
        vector<vector<int>>adj_list(n+1) ;
        for(int i = 1 ; i < n ; i++)
        {
            int u , v ;
            cin>>u>>v;
            
            adj_list[u].push_back(v) ;
            adj_list[v].push_back(u) ;
        }
        
        vector<long long int>left_val(n+1,0) , right_val(n+1,0) ;
        vector<bool>visited(n+1 , false) ;
        
        traverse(1 , adj_list , range , left_val , right_val , visited) ;
        
        long long int sum = max(left_val[1] , right_val[1]) ;
        
        cout<<sum<<endl;
    }
    
    return 0 ;
}