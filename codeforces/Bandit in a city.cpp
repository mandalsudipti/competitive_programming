#include<bits/stdc++.h>
using namespace std;

vector<long long int>population;

void solve(int root ,vector<int>&cnt_leaf ,vector<long long int>&maximum ,vector<long long int>&sum ,vector<vector<int>>&adj_list)
{
    if(adj_list[root].size() == 0)
    {
        cnt_leaf[root] = 1 ;
        maximum[root] = population[root] ;
        sum[root] = population[root] ;
        return ;
    }
    
    sum[root] = population[root];
    for(int i=0;i<adj_list[root].size();i++)
    {
        int child = adj_list[root][i] ;
        solve(child,cnt_leaf,maximum,sum,adj_list);
        sum[root]+=sum[child];
        cnt_leaf[root]+=cnt_leaf[child];
        maximum[root] = max(maximum[root] , maximum[child]);
    }
    
    long long int tmp = (sum[root] / cnt_leaf[root]) + (sum[root] % cnt_leaf[root] != 0);
    maximum[root] = max( maximum[root] , tmp );
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj_list(n+1);
    int val;
    for(int i=2;i<=n;i++)
    {
        cin>>val;
        adj_list[val].push_back(i);
    }
    
    population.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>population[i];
        
    vector<int>cnt_leaf(n+1,0);
    vector<long long int>maximum(n+1,0);
    vector<long long int>sum(n+1,0);
    
    solve(1, cnt_leaf , maximum , sum , adj_list);
    
    cout<<maximum[1]<<endl;
    return 0;
}


