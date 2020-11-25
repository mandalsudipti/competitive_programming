#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n,0));
        int start = 0 ;
        
        for(int i=0;i<n;i++)
        {
            grid[i][start] = 1 ;
            grid[i][(start + 1)%n] = 1 ;
            start = (start + 2)%n;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}