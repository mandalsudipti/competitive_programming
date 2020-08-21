#include<bits/stdc++.h>
using namespace std;
vector<int>next_cell;
vector<int>cost;
vector<bool>visited;
long long int total_cost = 0 ;

void DFS(int node , vector<bool>&cur_visit)
{
   if(cur_visit[node])// beginning of a cycle
   {
        int min_cost = cost[node] ;
        for(int i=next_cell[node];i!=node;i=next_cell[i])
            min_cost = min(min_cost,cost[i]);
        total_cost+=min_cost;
        return;
   }
   else if(visited[node]) // already visited 
        return ;
        
    cur_visit[node] = true ;
    visited[node] = true;
    DFS(next_cell[node],cur_visit);
    cur_visit[node] = false;
}

int main()
{
    int n ;
    cin>>n;
    next_cell.resize(n+1);
    cost.resize(n+1);
    visited.resize(n+1,false);
    
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    for(int i=1;i<=n;i++)
        cin>>next_cell[i];
     
    vector<bool>cur_visit(n+1,false);   
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            DFS(i,cur_visit);
    }
    
    cout<<total_cost<<endl;
    
    return 0;
}