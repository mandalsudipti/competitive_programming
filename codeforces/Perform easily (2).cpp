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
        
    vector<vector<int>>grid(n , vector<int>(6)) ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 6 ; j++)
            grid[i][j] = note[i] - str[j] ;
        sort(grid[i].begin() , grid[i].end());
    }
    
    vector<int>idx(n,0) ;
    multiset< pair<int,int> >cur ;
    
    for(int i = 0 ; i < n ; i++)
        cur.insert(make_pair(grid[i][0],i) ) ;
        
    int diff = ((*cur.rbegin()).first) - ((*cur.begin()).first);
    while(true)
    {
        int minimum =  (*cur.begin()).first , min_row = (*cur.begin()).second ;
        cur.erase(cur.begin());
        idx[min_row]++ ;
        
        cur.insert( make_pair(grid[min_row][idx[min_row]] , min_row) ) ;
        diff = min(diff , ((*cur.rbegin()).first) - ((*cur.begin()).first) );
        
        if(idx[(*cur.begin()).second] == 5)
            break;
    }
    
    cout<<diff<<endl;
    return 0 ;
}
