#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
        
    vector<vector<int>>adj_list(n+1);
    for(int i=1;i<=n;i++)
    {
        if(i-arr[i]>=1)
            adj_list[i-arr[i]].push_back(i);
        if(i+arr[i]<=n)
            adj_list[i+arr[i]].push_back(i);
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<"--> ";
        for(int j=0;j<adj_list[i].size();j++)
            cout<<adj_list[i][j]<<" ";
        cout<<endl;
    }*/
    vector<bool>visited(n+1,false);
    vector<int>distance_for_even(n+1,0);
    
    queue<int>Q;
    for(int i=1;i<=n;i++)
        if(arr[i]%2)
        {
            Q.push(i);
            visited[i] = true;
        }
            
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i=0;i<adj_list[node].size();i++)
        {
            int cur = adj_list[node][i];
            if(!visited[cur])
            {
                visited[cur] = true ;
                distance_for_even[cur] = distance_for_even[node]+1;
                Q.push(cur);
            }
        }
    }
    
    visited.clear();
    visited.resize(n+1,false);
    vector<int>distance_for_odd(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(arr[i]%2==0)
        {
            Q.push(i);
            visited[i] = true;
        }
    }
    
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i=0;i<adj_list[node].size();i++)
        {
            int cur = adj_list[node][i] ;
            if(!visited[cur])
            {
                //cout<<cur<<" "<<arr[cur]<<endl;
                visited[cur] = true ;
                distance_for_odd[cur] = distance_for_odd[node] + 1 ;
                //cout<<cur<<"--->"<<distance_for_odd[cur]<<endl;
                Q.push(cur);
            }
        }
    }
    
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++)
        ans[i] = max(distance_for_odd[i] , distance_for_even[i]);
        
    for(int i=1;i<=n;i++)
        ans[i]==0 ? cout<<"-1 ":cout<<ans[i]<<" " ;
        
    return 0;
}

