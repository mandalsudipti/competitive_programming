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
        vector<long long int>arr(n+1);
        int min_idx = 1 ;
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>arr[i] ;
            if(arr[i] < arr[min_idx])
                min_idx = i ;
        }
        
        if(min_idx == 1)
            cout<<(n-1)<<endl;
        else
        {
            cout<<n<<endl;
            cout<<"1"<<" "<<min_idx<<" "<<arr[min_idx]<<" "<<arr[min_idx]<<endl;
            arr[1] = arr[min_idx] ;
        }
        for(int i = 2 ; i <= n ; i++)
            cout<<"1"<<" "<<i<<" "<<arr[1]<<" "<<arr[1]+(i-1)<<endl;
        
    }
    return 0 ;
}