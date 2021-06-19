#include<bits/stdc++.h>
using namespace std;

const vector<int>dir_x = {1,-1,0 ,0} ;
const vector<int>dir_y = {0,0,1,-1};

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int row , col ;
        cin>>row>>col;
        
        vector<string>grid(row);
        for(int i = 0 ; i < row ; i++)
            cin>>grid[i];
            
        queue<pair<int,int>>Q ;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(grid[i][j] != '.')
                    Q.push(make_pair(i,j));
            }
        }
        
        bool flag = true ;
        if(Q.size() == 0)
        {
            for(int i = 0 ; i < row ; i++)
            {
                for(int j = 0 ; j < col ; j++)
                {
                    if(i == j && i == 0)
                        grid[i][j] = 'R' ;
                    else
                    {
                        if(j - 1 >= 0)
                            grid[i][j] = (grid[i][j-1] == 'R' ? 'W' : 'R');
                        else
                            grid[i][j] = (grid[i-1][j] == 'R' ? 'W' : 'R');
                    }
                }
            }
        }
        else
        {
            while(Q.size() > 0)
            {
                if(!flag)
                    break ;
                int x = Q.front().first , y = Q.front().second ;
                Q.pop() ;
                for(int i = 0 ; i < 4 ; i++)
                {
                    int new_x = x + dir_x[i] , new_y = y + dir_y[i] ;
                    if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col)
                    {
                        if(grid[new_x][new_y] == '.')
                        {
                            grid[new_x][new_y] = (grid[x][y] == 'R' ? 'W' : 'R');
                            Q.push(make_pair(new_x , new_y));
                        }
                        else if(grid[x][y] == grid[new_x][new_y])
                        {
                            flag = false ;
                            break;
                        }
                    }
                }
            }
        }
        
        if(!flag)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i = 0 ; i < row ; i++)
            {
                for(int j = 0 ; j < col ; j++)
                    cout<<grid[i][j];
                cout<<endl;
            }
        }
    }
    return 0 ;
}