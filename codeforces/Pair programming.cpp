#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int page , n , m;
        cin>>page>>n>>m;
        
        vector<int>arr1(n) , arr2(m) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr1[i] ;
        for(int i = 0 ; i < m ; i++)
            cin>>arr2[i] ;
            
        vector<int>ans ;
        bool possible = true ;
        int idx1 = 0 , idx2 = 0 ;
        
        while(idx1 < n || idx2 < m)
        {
            if(idx1 < n && (arr1[idx1] <= page || arr1[idx1] == 0))
            {
                if(arr1[idx1] == 0)
                    page++ ;
                ans.push_back(arr1[idx1]) ;
                idx1++;
            }
            else if(idx2 < m && (arr2[idx2] <= page || arr2[idx2] == 0))
            {
                if(arr2[idx2] == 0)
                    page++ ;
                ans.push_back(arr2[idx2]);
                idx2++;
            }
            else
            {
                possible = false ;
                break;
            }
        }
        
        if(!possible)
            cout<<"-1"<<endl;
        else
        {
            for(int i = 0 ; i < (n+m) ; i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0 ;
}