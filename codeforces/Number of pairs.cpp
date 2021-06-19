#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , l , r ;
        cin>>n>>l>>r ;
        
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
        sort(arr.begin() , arr.end());
        
        long long int count = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            int minimum = l - arr[i] , maximum = r - arr[i] ;
            int idx1 = lower_bound(arr.begin()+i+1 , arr.end() , minimum) - arr.begin() ;
            
            if(idx1 >= arr.size() || arr[idx1] > maximum)
                continue;
                
            int idx2 = upper_bound(arr.begin()+i+1 , arr.end() , maximum) - arr.begin() ;
            if(idx2 >= arr.size() || arr[idx2] > maximum)
                idx2--;
            
            count+=(idx2 - idx1 + 1);
        }
        cout<<count<<endl;
    }
    return 0 ;
}


