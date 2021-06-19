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
            
            
        int min_idx = 0 , max_idx = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] > arr[max_idx])
                max_idx = i ;
            if(arr[i] < arr[min_idx])
                min_idx = i ;
        }
        
        if(min_idx > max_idx)
            swap(min_idx , max_idx);
            
        int move = min( min_idx + 1 + ( n - max_idx) , min( max(min_idx , max_idx) + 1 , n - min(min_idx , max_idx) ) ) ;
        cout<<move<<endl;
    }
    return 0 ;
}