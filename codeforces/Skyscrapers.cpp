#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row , col ;
    cin>>row>>col;
    vector<vector<int>>grid(row,vector<int>(col));
    vector<vector<int>>R(row,vector<int>(col));
    vector<vector<int>>C(col,vector<int>(row));
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>grid[i][j];
            R[i][j]=grid[i][j];
            C[j][i]=grid[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        sort(R[i].begin(),R[i].end());
        auto itr = unique(R[i].begin(),R[i].end());
        R[i].resize(distance(R[i].begin(),itr));
    }
    for(int j=0;j<col;j++)
    {
        sort(C[j].begin(),C[j].end());
        auto itr = unique(C[j].begin(),C[j].end());
        C[j].resize(distance(C[j].begin(),itr));
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int lesser_row = upper_bound(R[i].begin(),R[i].end(),grid[i][j]) - R[i].begin() - 1 ;
            int lesser_col = upper_bound(C[j].begin(),C[j].end(),grid[i][j]) - C[j].begin() - 1;
            int ans = max(lesser_col,lesser_row) + max( (R[i].size()- lesser_row-1),(C[j].size()- lesser_col-1))+1;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}