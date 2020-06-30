#include<bits/stdc++.h>
using namespace std;

int main()
{
    int blog , reference ;
    cin>>blog>>reference;
    vector<vector<int>>adj_matrix(blog+1);
    for(int i=0;i<reference;i++)
    {
        int x , y ;
        cin>>x>>y;
        adj_matrix[x].push_back(y);
        adj_matrix[y].push_back(x);
    }
    vector<pair<int,int>>color(blog+1);
    for(int i=1;i<=blog;i++)
    {
        int x ;
        cin>>x;
        color[i] = make_pair(x,i);
    }
    bool possible = true ;
    for(int i=1;i<=blog;i++)
    {
        if(!possible)
            break;
        int node_color = color[i].first ;
        set<int>neighbour_color;
        for(int j=0;j<adj_matrix[i].size();j++)
        {
            if(color[adj_matrix[i][j]].first==node_color)
            {
                possible =false ;
                break;
            }
            if(color[adj_matrix[i][j]].first<node_color)
                neighbour_color.insert(color[adj_matrix[i][j]].first);
        }
        if(neighbour_color.size()!=node_color - 1)
        {
            possible =false;
            break;
        }
        
    }
    if(!possible)
        cout<<"-1";
    else
    {
        sort(color.begin(),color.end());
        for(int i=1;i<=blog;i++)
            cout<<color[i].second<<" ";
    }
    return 0;
}


