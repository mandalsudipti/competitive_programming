#include<bits/stdc++.h>
using namespace std ;

void traverse_up(vector<string>& grid , int x , int y , vector<vector<bool>>& visited , int k)
{
    int len = 0 , j1 = y , j2 = y , m = visited[0].size();
    
    for(int i = x-1 ; i >= 0 ; i--)
    {
        j1-- ;
        j2++ ;
        
        if(j1 >= 0 && j2 < m && grid[i][j1] == grid[i][j2] && grid[i][j1] == '*')
        {
            len++ ;
        }
        else
            break;
    }
    
    if(len < k)
        return ;
    //cout<<x<<" "<<y<<" "<<len<<endl;    
    visited[x][y] = true ;
    j1 = y ;
    j2 = y; 
    
    for(int i = x-1 ; i >= x - len ; i--)
    {
        j1-- ;
        j2++ ;
        
        visited[i][j1] = visited[i][j2] = true ;
    }
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , m , k ;
        cin>>n>>m>>k ;
        
        vector<string>grid(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>grid[i] ;
            
        vector<vector<bool>>visited(n , vector<bool>(m , false));
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '*' && i-1 >= 0 && j-1 >= 0 && j+1 < m)
                    traverse_up(grid , i , j , visited , k) ;
                    
            }
        }
        
        bool possible = true ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '*' && !visited[i][j])
                {
                    possible = false ;
                    break;
                }
            }
        }
        
        if(possible)
            cout<<"YES\n" ;
        else
            cout<<"NO\n" ;
    }
    
    return 0 ; 
}