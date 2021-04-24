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
        vector<long long int>arr(n+2) ;
        for(int i = 0 ; i < n+2 ; i++)
            cin>>arr[i] ;
        sort(arr.begin() , arr.end());
        
        long long int prefix_sum1 = 0 , prefix_sum2 = 0 ; 
        for(int i = 0 ; i < n ; i++)
            prefix_sum1+=arr[i] ;
            
        prefix_sum2 = prefix_sum1 + arr[n] ;
        
        if(prefix_sum1 == arr[n])
        {
            for(int i = 0 ; i < n ; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        else
        {
            long long int X = -1 ;
            for(int i = 0 ; i <= n ; i++)
            {
                if(prefix_sum2 - arr[i] == arr[n+1])
                {
                    X = arr[i] ;
                    break;
                }
            }
            
            if(X == -1)
                cout<<"-1"<<endl;
            else
            {
                for(int i = 0 ; i <= n ; i++)
                {
                    if(arr[i] != X)
                        cout<<arr[i]<<" ";
                    else
                        X = -1 ;
                }
                cout<<endl;
            }
        }
    }
    
    return 0 ;
}
