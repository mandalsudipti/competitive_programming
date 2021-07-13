#include<bits/stdc++.h>
using namespace std ;

const int len = 1e5 + 10 ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        vector<int>sorted_arr = arr ;
        sort(sorted_arr.begin() , sorted_arr.end());
        
        vector<vector<int>>loc_parity(len , vector<int>(2,0));
        for(int i = 0 ; i < n ; i++)
            loc_parity[sorted_arr[i]][i%2]++ ;
        
        bool possible = true ;
        for(int i = 0 ; i < n ; i++)
        {
            int parity = i%2 ;
        
            if(loc_parity[arr[i]][parity] == 0)
            {
                possible = false ;
                break;
            }
            else
                loc_parity[arr[i]][parity]-- ;
        }
        
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}