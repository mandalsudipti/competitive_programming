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
        
        vector<int>arr(n+1) ;
        
        for(int i = 1 ; i <= n ; i+=2)
        {
            if(i+1 > n)
                continue ;
            arr[i] = i+1 ;
            arr[i+1] = i ;
        }
        
        if(n%2 == 1 )
        {
            arr[n] = arr[n-1] ;
            arr[n-1] = n ;
        }
        
        for(int i = 1 ; i <= n ; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0 ;
}
