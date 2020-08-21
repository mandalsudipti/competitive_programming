#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n , m ;
    cin>>n>>m;
    vector<vector<int>>grid(m,vector<int>(n));
    vector<vector<int>>pos(m,vector<int>(n+1));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
            pos[i][grid[i][j]] = j;
        }
    }
    
    long long int total_way = 0 ;
    vector<int>len(n,1);
    for(int i=n-1;i>=0;i--)
    {
        bool possible = true ;
        for(int j=1;j<m;j++)
        {
            int position = pos[j][grid[0][i]];
            if(i+1>=n || position+1>=n || grid[j][position+1]!=grid[0][i+1])
                possible = false ;
        }
        if(possible && i+1<n)
            len[i] = len[i+1] + 1  ;
        total_way+=len[i];
    }
    
    cout<<total_way;
    
    return 0;
}



