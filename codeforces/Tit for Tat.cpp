#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , k ; 
        cin>>n>>k;
        
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(k == 0)
                break;
            else
            {
                int substract = min(k , arr[i]) ;
                arr[i]-=substract ;
                k-=substract ;
                arr[n-1]+=substract ;
            }
        }
        
        for(int i = 0 ; i < n ; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    return 0 ;
}