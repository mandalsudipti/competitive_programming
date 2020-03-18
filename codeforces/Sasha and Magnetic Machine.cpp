#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt=0;
    int n;
    cin>>n;
    int i , arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    long long int sum=0;
    for(i=0;i<n;i++)
        sum+=arr[i];
    long long int minimum = sum ;
    for(i=n-1;i>0;i--)
    {
        for(int k=arr[i];k>1;k--)
        {
            if(arr[i]%k==0 && sum-arr[0]-arr[i]+(arr[0]*k)+(arr[i]/k)<minimum)
            {
                minimum = sum-arr[0]-arr[i]+(arr[0]*k)+(arr[i]/k);
            }
        }
    }

    cout<<minimum;
    return 0;
}
