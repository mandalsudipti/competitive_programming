#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long int>str(6);
    for(int i=0;i<6;i++)
        cin>>str[i];
    
    int n ;
    cin>>n;
    vector<long long int>note(n);
    for(int i=0;i<n;i++)
        cin>>note[i];
        
    vector<vector<int>>grid(n,vector<int>(6));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
            grid[i][j] = note[i] - str[j];
        sort(grid[i].begin(),grid[i].end());
    }
    
    vector<int>idx(n,0);
    set<pair<int,int>>entry;
    int min_row = 0 , max_row = 0 ;

    for(int i=0;i<n;i++)
    {
        entry.insert(make_pair(grid[i][idx[i]] , i));
        if(grid[i][idx[i]] < grid[min_row][idx[min_row]])
            min_row = i ;
        if(grid[i][idx[i]] > grid[max_row][idx[max_row]])
            max_row = i ;
    }
    
    int min_diff = grid[max_row][idx[max_row]] - grid[min_row][idx[min_row]] ;
    while(idx[min_row] < 5)
    {
        entry.erase(entry.begin());
        idx[min_row]++;
        entry.insert( make_pair(grid[min_row][idx[min_row]] , min_row) );
        min_row = (*entry.begin()).second ;
        max_row = (*entry.rbegin()).second;
        min_diff = min( min_diff , grid[max_row][idx[max_row]] - grid[min_row][idx[min_row]]);
    }
    
    cout<<min_diff<<endl;
    
    return 0;
}






