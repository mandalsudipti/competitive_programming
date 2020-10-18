#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int row , col ;
        cin>>row>>col;
        
        vector<vector<int>>grid(row,vector<int>(col));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cin>>grid[i][j];
        }
        
        long long int cnt = 0 ;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==-1)
                    continue;
            
                vector<int>tmp(4);
                tmp[0] = grid[i][j] , tmp[1] = grid[row-1-i][j] , tmp[2] = grid[i][col-1-j] , tmp[3] = grid[row-1-i][col-1-j] ;

                sort(tmp.begin(),tmp.end());
                long long int x = 0 , y = 0;
                
                for(int k=0;k<4;k++)
                    x+=abs(tmp[1]-tmp[k]);

                for(int k=0;k<4;k++)
                    y+=abs(tmp[2]-tmp[k]);
                    
                if( (row%2==1 && row/2==i)||(col%2==1 && col/2==j))
                    cnt+=abs(tmp[0]-tmp[2]);
                else
                    cnt+=min(x,y);
                
                grid[i][j] = grid[row - 1 -i][j] = grid[i][col - 1 - j] = grid[row-1-i][col-1-j] = -1 ;
            }
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}