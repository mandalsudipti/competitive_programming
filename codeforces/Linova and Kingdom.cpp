#include<bits/stdc++.h>
using namespace std;

void DFS(long long int parent ,long long int node ,vector<long long int>&depth,vector<vector<long long int>>&tree,vector<long long int>&subtree)
{
    if(depth[node]!=0)
        return;
    depth[node]=depth[parent]+1;
    //cout<<node<<" has depth-> "<<depth[node]<<endl;
    for(int i=0;i<tree[node].size();i++)
    {
        int child = tree[node][i];
        if(child==parent)
            continue;
        DFS(node,child,depth,tree,subtree);
        subtree[node]+=subtree[child]+1;
    }
}

int main()
{
   long long int n , industry_node ;
   cin>>n>>industry_node;
   vector<vector<long long int>>tree(n+1);
   long long int x , y;
   for(int i=0;i<n-1;i++)
   {
       cin>>x>>y;
       tree[x].push_back(y);
       tree[y].push_back(x);
   }
   vector<long long int>depth(n+1);
   vector<long long int>subtree(n+1,0);
   depth[0]=-1;
   
   DFS(0,1,depth,tree,subtree);
   
   vector<long long int>contribution;
   for(int i=1;i<=n;i++)
    {
        contribution.push_back(depth[i]-subtree[i]);
    }
   sort(contribution.begin(),contribution.end(),greater<long long int>());
   long long int sum=0;
   for(int i=0;i<industry_node;i++)
        sum+=contribution[i];
    cout<<sum;
    return 0;
}


