#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;

long long int power(long long int x , long long int y)
{
    long long int tmp = x;
    while(y>1)
    {
        x=(x*tmp)%mod;
        y--;
    }
    return x%mod;
}

void DFS(vector<vector<long long int>>&adj_list,vector<bool>&visited , long long int node , long long int *cnt)
{
    visited[node]=true;
    for(int i=0;i<adj_list[node].size();i++)
    {
        int nxt_node = adj_list[node][i];
        if(!visited[nxt_node])
        {
            (*cnt)++;
            DFS(adj_list,visited,nxt_node,cnt);
        }
    }
}

int main()
{
    long long int n , k;
    cin>>n>>k;
    long long int x , y , color , bad_node=0;
    long long int ans=0;
    vector<vector<long long int>>adj_list(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y>>color;
        if(color==0)
        {
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
    }
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        long long int cnt=0;
        if(!visited[i] && adj_list[i].size()>=1)
        {
            cnt++;
            DFS(adj_list,visited,i,&cnt);
        }
        ans = (ans%mod+power(cnt,k)%mod)%mod;
        bad_node+=cnt;
    }
    ans = (ans%mod+(n-bad_node))%mod;
    cout<<(power(n,k)-ans+mod)%mod<<endl;
    return 0;
}
