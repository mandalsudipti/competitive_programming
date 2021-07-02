#include<bits/stdc++.h>
using namespace std ;


int main() 
{
    int T ;
    cin>>T ;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        n = 2*n ;
        vector<int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end());
        vector<int>ans(n);
        int idx = 0 ;
        for(int i = 0 ; i < n ; i+=2)
        {
            ans[i] = arr[idx] ;
            idx++;
        }
        
        for(int i = 1 ; i < n ; i+=2)
        {
            ans[i] = arr[idx] ;
            idx++ ;
        }
        
        for(int i = 0 ; i < n ; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0 ;
}