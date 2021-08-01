#include<bits/stdc++.h>
using namespace std ;

const vector<int>dir_x = {1,-1,0} ;
const vector<int>dir_y = {1,-1,0} ;

bool is_valid(int x , int y , vector<vector<int>>& grid)
{
    int row = grid.size() , col = grid[0].size() ;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            int new_x = x + dir_x[i] , new_y = y + dir_y[j] ;
            
            if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && grid[new_x][new_y] == 1)
                return false ;
        }
    }
    return true ;
}

int main()
{
    
    int T ;
    cin>>T;
    
    while(T--)
    {
        int row , col ;
        cin>>row>>col ;
        
        vector<vector<int>>grid(row , vector<int>(col , 0));
        for(int j = 0 ; j < col ; j+=2)
            grid[0][j] = grid[row-1][j] = 1 ;
            
        for(int i = 0 ; i < row ; i++)
        {
            if(is_valid(i,0,grid))
                grid[i][0] = 1 ;
            if(is_valid(i,col-1,grid))
                grid[i][col-1] = 1 ;
        }
        
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
                cout<<grid[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0 ;
}

