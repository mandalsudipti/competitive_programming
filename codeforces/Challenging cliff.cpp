#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end());
        int min_diff = 0 ;
        for(int i = 1 ; i < n - 1 ; i++)
        {
            if(abs(arr[i] - arr[i+1]) < abs(arr[min_diff] - arr[min_diff + 1]) )
                min_diff = i ;
        }
        vector<int>ans(n) ;
        ans[0] = arr[min_diff] ;
        ans[n-1] = arr[min_diff + 1] ;
        
        int idx = min_diff + 2 ;
        for(int i = 1 ; i < n-1 ; i++)
        {
            if(idx >= n)
                idx = 0 ;
            ans[i] = arr[idx] ;
            idx++;
        }
        for(int i = 0 ; i < n ; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0 ;
}