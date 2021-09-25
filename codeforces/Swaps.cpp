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
        
        vector<int>A(n) , B(n) , closest_small(n) ;
        set<int , greater<int>>arr ;
        
        for(int i = 0 ; i < n ; i++)
            cin>>A[i] ;
        for(int i = 0 ; i < n ; i++)    
        {
            cin>>B[i] ;
            arr.insert(B[i]) ;
        }
            
        int min_idx ;
        for(int i = 0 ; i < n ; i++)
        {
            if(i == 0 || A[min_idx] > A[i])
            {
                min_idx = i ;
                while((*arr.begin()) > A[i])
                {
                    int val = (*arr.begin()) ;
                    arr.erase(arr.begin()) ;
                    closest_small[(val/2)-1] = i ;
                }
            }
        }
        
        int ans = INT_MAX ;
        for(int i = 0 ; i < n ; i++)
        {
            ans = min(ans , i + closest_small[(B[i]/2)-1]) ;
        }
        
        cout<<ans<<endl;
    }
    
    return 0 ;
}
