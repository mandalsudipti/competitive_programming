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
        
        vector<int>arr(n) , B(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        int end = (n%2 == 0 ? n-1 : n - 4) ;
        
        for(int i = 0 ; i <= end ; i+=2)
        {
            B[i] = -arr[i+1] ;
            B[i+1] = arr[i] ;
        }
        
        if(n%2 == 1)
        {
            if(arr[n-1] + arr[n-2] != 0)
            {
                B[n-3] = arr[n-1] + arr[n-2] ;
                B[n-1] = B[n-2] = (-1)*arr[n-3] ;
            }
            else if(arr[n-2] + arr[n-3] != 0)
            {
                B[n-1] = arr[n-2] + arr[n-3] ;
                B[n-2] = B[n-3] = (-1) * arr[n-1] ;
            }
            else
            {
                B[n-2] = arr[n-1] + arr[n-3] ;
                B[n-1] = B[n-3] = (-1) * arr[n-2] ;
            }
        }
        
        for(int i = 0 ; i < n ; i++)
            cout<<B[i]<<" ";
        cout<<endl;
    }
    
    return 0 ;
}

