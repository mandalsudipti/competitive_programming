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
            
        vector<vector<long long int>>ans(row,vector<long long int>(col));
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j <col ; j++)
            {
                if(grid[i][j] == '*')
                    ans[i][j] = 1 ;
                else
                    ans[i][j] = 0 ;
            }
        }
        
        for(int i = row-2 ; i>= 0 ; i--)
        {
            for(int j = 0 ; j <col ;j++)
            {
                if(j-1 >= 0 && j+1 < col && ans[i][j] == 1)
                    ans[i][j] = 1 + min(ans[i+1][j] , min(ans[i+1][j-1] , ans[i+1][j+1]) );
            }
        }
        
        long long int sum = 0 ;
        for(int i = 0 ; i <row;i++)
        {
            for(int j = 0 ; j <col ; j++)
                sum+=ans[i][j];
        }
        
        cout<<sum<<endl;
    }
    
    return 0;
}
