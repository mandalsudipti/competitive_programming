#include<bits/stdc++.h>
using namespace std;

int row , col ;
const char BLACK='#' , WHITE='.';
const int move_col[]={1,0,0,-1};
const int move_row[]={0,1,-1,0};

bool inside_grid(int x , int y)
{
    if(x>=0 && x<row && y>=0 && y<col)
        return true;
    else
        return false;
}

void traverse(vector<string>&grid , vector<vector<bool>>&visited, int x , int y )
{
    visited[x][y]=true;
        for(int j=0;j<4;j++)
        {
            int next_x = x+move_row[j];
            int next_y = y+move_col[j];
            if(inside_grid(next_x,next_y) && grid[next_x][next_y]==BLACK && !visited[next_x][next_y])
            {
                traverse(grid,visited,next_x,next_y);
            }
        }
}

int main()
{
    cin>>row>>col;
    vector<string>grid(row);
    for(int i=0;i<row;i++)
        cin>>grid[i];
        
    vector<int>black_in_row(row,0);
    vector<int>black_in_col(col,0);
    
    for(int i=0;i<row;i++)
    {
        int cnt=0;
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==BLACK)
                cnt++;
        }
        black_in_row[i]=cnt;
    }
    
    for(int j=0;j<col;j++)
    {
        int cnt=0;
        for(int i=0;i<row;i++)
        {
            if(grid[i][j]==BLACK)
                cnt++;
        }
        black_in_col[j]=cnt;
    }
    
    bool white_row = false , white_col = false , possible = true ;
    for(int i=0;i<row;i++)
    {
        int cnt=0;
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==BLACK)
            {
                cnt++;
                if(j+1<col && grid[i][j+1]==WHITE && cnt!=black_in_row[i])
                    possible=false;
            }
            
        }
        if(black_in_row[i]==0)
            white_row=true;
    }
    for(int j=0;j<col;j++)
    {
        int cnt=0;
        for(int i=0;i<row;i++)
        {
            if(grid[i][j]==BLACK)
            {
                cnt++;
                if(i+1<row && grid[i+1][j]==WHITE && cnt!=black_in_col[j])
                    possible=false;
            }
        }
        if(black_in_col[j]==0)
            white_col=true;
    }
    
    if(!possible || (white_col && !white_row) || (white_row && !white_col))
    {
        cout<<"-1";
        return 0;
    }
    
    int component = 0 ;
    vector<vector<bool>>visited(row,vector<bool>(col,false));
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==BLACK && !visited[i][j])
            {
                traverse(grid,visited,i,j);
                component++;
            }
        }
    }
    cout<<component;
    return 0;
}