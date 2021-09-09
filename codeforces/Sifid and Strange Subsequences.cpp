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
        
        vector<long long int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end());
        int left = 0 , max_len = 1 ;
        multiset<long long int>diff ;
        
        for(int i = 1 ; i < n ; i++)
        {
            diff.insert(arr[i] - arr[i-1]) ;
            while(left < i && (*diff.begin()) < arr[i])
            {
                diff.erase(diff.find(arr[left+1] - arr[left])) ;
                left++ ;
            }
            
            max_len = max(max_len , i - left + 1) ;
        }
        
        cout<<max_len<<endl;
    }
    
    return 0 ;
}