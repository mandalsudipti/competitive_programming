#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<vector<char>>grid(n,vector<char>(n));
        int row1 = -1 , row2 = -1 , col1 = -1 , col2 = -1 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                cin>>grid[i][j] ;
                if(grid[i][j] == '*')
                {
                    if(row1 == -1)
                    {
                        row1 = i ;
                        col1 = j ;
                    }
                    else
                    {
                        row2 = i ;
                        col2 = j ;
                    }
                }
            }
        }
        
        if(row1 == row2)
        {
            int tmp_row = (row1 + 1)%n ;
            grid[tmp_row][col1] = grid[tmp_row][col2] = '*' ;
        }
        else if(col1 == col2)
        {
            int tmp_col = (col1 + 1)%n ;
            grid[row1][tmp_col] = grid[row2][tmp_col] = '*' ;
        }
        else
        {
            grid[row1][col2] = grid[row2][col1] = '*' ;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                cout<<grid[i][j];
            cout<<endl;
        }
    }
    
    return 0 ;
}