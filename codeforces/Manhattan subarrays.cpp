#include<bits/stdc++.h>
using namespace std ;

bool is_valid(vector<int>&arr , int idx)
{
    if((arr[idx+1] >= arr[idx] && arr[idx+1] <= max(arr[idx+2] , arr[idx+3])) || (arr[idx+1] <= arr[idx] && arr[idx+1] >= min(arr[idx+2],arr[idx+3])) )
        return false ;
    
    if((arr[idx+2] <= arr[idx+3] && arr[idx+2] >= min(arr[idx],arr[idx+1])) ||(arr[idx+2] >= arr[idx+3] && arr[idx+2] <= max(arr[idx],arr[idx+1])))
        return false ;
        
    return true ;
    
}

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
            cin>>arr[i];
            
        long long int count = n + n - 1 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(i+2 < n && (arr[i+1] < min(arr[i],arr[i+2]) || arr[i+1] > max(arr[i],arr[i+2]) ) )
                count++;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(i+3 < n && is_valid(arr , i))
                count++;
        }
        
        cout<<count<<endl;
    }
    return 0 ;
}