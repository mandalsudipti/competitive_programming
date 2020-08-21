#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n ,  height ;
    cin>>n>>height;
    
    vector<long long int>arr(n);
    long long int total = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }
    
    sort(arr.begin(),arr.end());
    height = min(height,arr[n-1]);
    
    vector<bool>visited(n,false);
    int i=0 , idx = 1 ;
    long long int cnt = 0 ;
    while(i<n && idx<=height)
    {
        if(arr[i]>=idx)
        {
            visited[i] = true ;
            cnt++;
            idx++;
        }
        i++;
        
    }
    if(idx<=height)
    {
        visited[n-1]=true;
        cnt+=(height-idx)+1;
    }
    
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            cnt++;
    }
    
    cout<<total-cnt;
    
    return 0;
}