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
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(j==0)
                {
                    if(i==0)
                        cout<<grid[i][j]<<" ";
                    else
                    {
                        grid[i-1][j]%2 == grid[i][j]%2 ? grid[i][j]+=1 : grid[i][j]+=0;
                        cout<<grid[i][j]<<" ";
                    }
                }
                else
                {
                    grid[i][j-1]%2 == grid[i][j]%2 ? grid[i][j]+=1 : grid[i][j]+=0;
                    cout<<grid[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
    
    return 0;
}