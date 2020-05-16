#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int arr[n] , cnt =0 ;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i+1<n;i+=2)
    {
        if(arr[i]<arr[i+1])
            cnt+=(arr[i+1]-arr[i]);
    }
    cout<<cnt;
    return 0;
}