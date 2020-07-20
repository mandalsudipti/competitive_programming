#include<bits/stdc++.h>
using namespace std;

int get_root(int node , vector<int>&root)
{
    while(root[node]!=node)
    {
        root[node] = root[root[node]];
        node = root[node] ;
    }
    return node ;
}

void w_union(int x , int y , vector<int>&root , vector<int>&size)
{
    int root_x = get_root(x,root);
    int root_y = get_root(y,root);
    
    if(root_y == root_x)
        return ;
    if(size[root_x]>=size[root_y])
    {
        root[root_y] = root[root_x] ;
        size[root_x]+= size[root_y];
    }
    else
    {
        root[root_x] = root[root_y] ;
        size[root_y]+= size[root_x] ;
    }
}

int main()
{
    int node , edge ;
    cin>>node>>edge;
    
    vector<int>cnt_edge(node+1,0);
    vector<int>root(node+1);
    vector<int>size(node+1,1);
    for(int i=1;i<=node;i++)
        root[i]=i;
        
    for(int i=0;i<edge;i++)
    {
        int x , y ;
        cin>>x>>y;
        cnt_edge[x]++;
        cnt_edge[y]++;
        w_union(x,y,root,size);
    }
    
    bool possible = true ;
    for(int i=1;i<=node;i++)
    {
        int x = get_root(i,root) ;
        if(cnt_edge[i]!=size[x]-1)
            possible = false;
    }
    
    if(possible)
        cout<<"YES";
    else
        cout<<"NO";
        
    return 0;
}
