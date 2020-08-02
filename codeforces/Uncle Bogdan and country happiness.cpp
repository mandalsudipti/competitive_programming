#include<bits/stdc++.h>
using namespace std;

int node , citizen ;
vector<vector<int>>adj_list;
vector<long long int>population;
vector<long long int>happiness;
vector<bool>visited;
vector<int>subtree_size;

void get_subtree_size(int root)
{
    long long int size = population[root] ;
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true ;
            get_subtree_size(cur_node);
            size+=subtree_size[cur_node];
        }
    }
    subtree_size[root] = size ;
}

bool is_valid(int root)
{
    if((subtree_size[root]+happiness[root])%2!=0)
        return false;
        
    long long int good = (subtree_size[root]+happiness[root])/2 , tmp = 0;
    if(good<0 || good>subtree_size[root])
        return false;
        
    for(int i=0;i<adj_list[root].size();i++)
    {
        int cur_node = adj_list[root][i] ;
        if(!visited[cur_node])
        {
            visited[cur_node] = true;
            bool possible = is_valid(cur_node);
            if(!possible)
                return false;
            tmp+=(subtree_size[cur_node]+happiness[cur_node])/2;
        }
    }
    if(tmp<=good)
        return true;
    else
        return false;
}

void solve()
{
    cin>>node>>citizen;
    
    adj_list.resize(node+1);
    population.resize(node+1);
    happiness.resize(node+1);
    visited.resize(node+1,false);
    subtree_size.resize(node+1,0);
    
    for(int i=1;i<=node;i++)
    {
        cin>>population[i];
        citizen-=population[i];
    }
    for(int i=1;i<=node;i++)
        cin>>happiness[i];
        
        
    for(int i=1;i<node;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    if(citizen!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    visited[1] = true;
    get_subtree_size(1);
    
    visited.clear();
    visited.resize(node+1,false);
    visited[1] = true ;
    
    bool possible = is_valid(1) ;
    if(possible)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
    adj_list.clear();
    population.clear();
    happiness.clear();
    visited.clear();
    subtree_size.clear();
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
