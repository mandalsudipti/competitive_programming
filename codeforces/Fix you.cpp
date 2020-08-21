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
        vector<string>grid(row);
        for(int i=0;i<row;i++)
            cin>>grid[i];
        int cnt = 0 ;
        if(col==1)
        {
            for(int i=0;i<row-1;i++)
            {
                if(grid[i][0]!='D')
                    cnt++;
            }
            cout<<cnt<<endl;
            continue;
        }
        if(row==1)
        {
            for(int i=0;i<col-1;i++)
            {
                if(grid[0][i]!='R')
                    cnt++;
            }
            cout<<cnt<<endl;
            continue;
        }
        
        for(int i=0;i<row-1;i++)
        {
            if(grid[i][col-1]!='D')
                cnt++;
        }
        for(int j=0;j<col-1;j++)
        {
            if(grid[row-1][j]!='R')
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}