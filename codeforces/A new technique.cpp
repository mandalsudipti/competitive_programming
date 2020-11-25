#include<bits/stdc++.h>
using namespace std;

int match(vector<int>col_start , vector<vector<int>>sorted_row)
{
    for(int i=0;i<sorted_row.size();i++)
    {
        if(col_start == sorted_row[i])
            return i;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int row , col ;
        cin>>row>>col;
        
        vector<vector<int>>row_wise(row,vector<int>(col));
        vector<vector<int>>sorted_row(row);
        map< int , vector<int> >col_wise;
        vector<int>col_start(col);
        vector<int>tmp(row);
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cin>>row_wise[i][j]; 
            sorted_row[i] = row_wise[i];
            
            sort(sorted_row[i].begin(),sorted_row[i].end());
        }
        
        for(int j=0;j<col;j++)
        {
            for(int i=0;i<row;i++)
                cin>>tmp[i];
            col_start[j] = tmp[0];
            col_wise[tmp[0]] = tmp ;
        }
        sort(col_start.begin(),col_start.end());
        
        int start = match(col_start,sorted_row);
        
        vector<vector<int>>grid(row,vector<int>(col));
        
        for(int j=0;j<col;j++)
        {
            tmp = col_wise[row_wise[start][j]];
            for(int i=0;i<row;i++)
                grid[i][j] = tmp[i];
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        
    }
    
    return 0;
}