#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<vector<char>>grid(n + 1 , vector<char>(n + 1, '=')) ;
        for(int i = 1 ; i <= n ; i++)
            grid[i][i] = 'X' ;
            
        string S ;
        cin>>S ;
        vector<int>win ;
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] == '2')
                win.push_back(i+1) ;
        }
        
        if(win.size() == 1 || win.size() == 2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            int win_candidate = win.size() ;
            
            for(int i = 0 ; i < win.size() ; i++)
            {
                int node1 = win[i] , node2 = win[(i+1)%win_candidate] ;
                grid[node1][node2] = '+' ;
                grid[node2][node1] = '-' ;
            }
            
            for(int i = 1 ; i < grid.size() ; i++)
            {
                for(int j = 1 ; j < grid[i].size() ; j++)
                    cout<<grid[i][j] ;
                cout<<endl;
            }
        }
    }
    
    return 0 ;
}