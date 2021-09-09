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
        
        vector<int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end());
        int count = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] != arr[0])
                count++;
        }
        
        cout<<count<<endl;
    }
    return 0 ;
}