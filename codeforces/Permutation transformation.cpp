#include<bits/stdc++.h>
using namespace std;

void get_level(vector<int>&arr , int left , int right , int cur_level , map<int,int>&level)
{
    int max_idx = left ;
    for(int i = left ; i <= right ; i++)
    {
        if(arr[i] > arr[max_idx])
            max_idx = i ;
    }
    
    cur_level++;
    level[arr[max_idx]] = cur_level ;
    
    if(max_idx - 1 >= left)
        get_level(arr,left,max_idx-1,cur_level,level);
        
    if(max_idx + 1 <= right)
        get_level(arr,max_idx + 1 , right , cur_level , level);
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
            
        map<int,int>level;
        int cur_level = -1 ;
        get_level(arr,0,n-1,cur_level,level);
        
        for(int i = 0 ; i < n ; i++)
            cout<<level[arr[i]]<<" ";
        cout<<endl;
    }
    
    return 0;
}