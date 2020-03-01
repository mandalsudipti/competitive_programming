#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int arr[n+1];
    long long int even_sum=0 , odd_sum=0 , cnt=0;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    for(i=1;i<n;i+=2)
    {
        odd_sum+=arr[i];
        if(i+1<n)
            even_sum+=arr[i+1];
    }
    if(even_sum==odd_sum)
        cnt++;
    for(i=n-1;i>=1;i--)
    {
        if(i%2==0)
            even_sum+=(arr[i+1]-arr[i]);
        else
            odd_sum+=(arr[i+1]-arr[i]);
        if(even_sum==odd_sum)
            cnt++;
    }
    cout<<cnt;
    return 0;
}