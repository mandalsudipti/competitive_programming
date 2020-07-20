#include<bits/stdc++.h>
using namespace std;

int root(vector<int>&user_root , int node)
{
    while(user_root[node]!=node)
    {
        user_root[node] = user_root[user_root[node]];
        node = user_root[node];
    }
    return node ;
}

void weighted_union(int A , int B , vector<int>&user_root , vector<long long int>&user_size)
{
    int root_A = root(user_root,A);
    int root_B = root(user_root,B);
    
    if(root_A == root_B)
        return;
        
    if(user_size[root_A]<=user_size[root_B])
    {
        user_root[root_A] = user_root[root_B];
        user_size[root_B]+= user_size[root_A];
    }
    else
    {
        user_root[root_B] = user_root[root_A];
        user_size[root_A]+= user_size[root_B];
    }
}

int main()
{
    int n , m ;
    cin>>n>>m;
    
    vector<int>user_root(n+1,0);
    vector<long long int>user_size(n+1,1);
    for(int i=1;i<=n;i++)
    {
       user_root[i]=i; 
    }
    
    for(int i=0;i<m;i++)
    {
        int x ;
        cin>>x;
        vector<int>group(x);
        for(int j=0;j<x;j++)
            cin>>group[j];
        for(int j=1;j<x;j++)
            weighted_union(group[0],group[j],user_root,user_size);
    }
    
    for(int i=1;i<=n;i++)
    {
        int parent  = root(user_root,i);
        cout<<user_size[parent]<<" ";
    }
    return 0;
}

