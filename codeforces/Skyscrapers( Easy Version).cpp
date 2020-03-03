#include<bits/stdc++.h>
using namespace std;

long long int  solve(vector<long long int>arr,int n , int idx)
{
    for(int i=idx-1;i>=0;i--)
        arr[i] = min(arr[i],arr[i+1]);
    for(int i=idx+1;i<n;i++)
        arr[i] = min(arr[i],arr[i-1]);
    long long int sum =0 ;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}

int main()
{
    int n;
    cin>>n;
    int i , idx=-1;
    long long int  maximum=0;
    vector<long long int>arr(n);
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
    {
        long long int sum = solve(arr,n,i);
        if(sum>maximum)
        {
            maximum = sum ;
            idx = i ;
        }
    }
    
    for(int i=idx-1;i>=0;i--)
        arr[i] = min(arr[i],arr[i+1]);
    for(int i=idx+1;i<n;i++)
        arr[i] = min(arr[i],arr[i-1]);
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

