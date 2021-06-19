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
            
        long long int move = 0 , reduce_cur ;
        for(int i = 0 ; i < n ; i++)
        {
            reduce_cur = 0 ;
            if(i+1 < n && i-1 >= 0 && arr[i] > arr[i-1] && arr[i] > arr[i+1])
                reduce_cur = arr[i] - max(arr[i-1] , arr[i+1]);
            else if(i==0 && i+1 < n && arr[i+1] < arr[i])
                reduce_cur = arr[i] - arr[i+1] ;
            else if(i == n-1 && i-1 >= 0 && arr[i] > arr[i-1])
                reduce_cur = arr[i] - arr[i-1] ;
                
            move+=reduce_cur ;
            arr[i]-=reduce_cur;
        }
        //cout<<move<<endl;
        long long int boundary = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(i == 0 || i == n-1)
                boundary+=arr[i] ;
                
            if(i+1 < n && arr[i] > arr[i+1])
                boundary+=(arr[i] - arr[i+1]);
                
            if(i-1 >= 0 && arr[i] > arr[i-1])
                boundary+=(arr[i] - arr[i-1]);
        }
        cout<<boundary + move <<endl;
    }
    return 0 ;
}