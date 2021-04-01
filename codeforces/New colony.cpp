#include<bits/stdc++.h>
using namespace std;

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
            cin>>arr[i];
        int pos = -1 ;   
        while(k > 0)
        {
            int i = 0 ;
            while(i+1 < n && arr[i] >= arr[i+1])
                i++;
            
            if(i == n-1)
                break;
            
            int add_boulder ;
            i > 0 ? add_boulder = min(arr[i-1]+1 , arr[i+1]) : add_boulder = arr[i+1] ;
            
            add_boulder-=arr[i];
            add_boulder = min(add_boulder , k);
            arr[i]+=add_boulder ;
            k-=add_boulder;
            
            if( k == 0)
                pos = i + 1 ;
        }
        
        cout<<pos<<endl;
    }
    
    return 0;
}