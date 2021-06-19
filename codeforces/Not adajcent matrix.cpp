#include<bits/stdc++.h>
using namespace std ;

bool is_valid(vector<vector<int>>& grid)
{
   int n = grid.size() ;
   vector<int>move_x = { 0 , 0 , 1 , -1 } ;
   vector<int>move_y = { 1 , -1 , 0 , 0 } ;
   
   for(int i = 0 ; i < n ; i++)
   {
       for(int j = 0 ; j < n ; j++)
       {
           for(int move = 0 ; move < 4 ; move++)
           {
               int new_x = i + move_x[move] , new_y = j + move_y[move] ;
               if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && abs(grid[i][j] - grid[new_x][new_y]) == 1)
                    return false ;
           }
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
        int n ;
        cin>>n;
        
        int num = 1 ;
        vector<vector<int>>grid(n , vector<int>(n,0));
        
        for(int i = 0 ; i < n ; i++)
        {
            int start ;
            i%2 == 0 ? start = 0 : start = 1 ;
            
            for(int j = start ; j < n ; j+=2)
                grid[i][j] = num++ ;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 0)
                    grid[i][j] = num++;
            }
        }
        
        if(is_valid(grid))
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                    cout<<grid[i][j]<<" ";
                cout<<endl;
            }
        }
        else
            cout<<"-1"<<endl;
    }
    return 0 ;
}