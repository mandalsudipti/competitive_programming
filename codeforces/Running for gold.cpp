#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n ;
        
        vector<vector<int>>rank(n , vector<int>(5));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < 5 ; j++)
                cin>>rank[i][j] ;
        }
        
        int winner = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            int cnt = 0 ;
            for(int j = 0 ; j < 5 ; j++)
            {
                if(rank[winner][j] < rank[i][j])
                    cnt++ ;
            }
            if(cnt < 3)
                winner = i ;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            int cnt = 0 ;
            for(int j = 0 ; j < 5 ; j++)
            {
                if(rank[i][j] < rank[winner][j])
                    cnt++ ;
            }
            if(cnt >= 3)
            {
                winner = -2 ;
                break;
            }
        }
        
        cout<<winner + 1<<endl;
    }
    return 0 ;
}