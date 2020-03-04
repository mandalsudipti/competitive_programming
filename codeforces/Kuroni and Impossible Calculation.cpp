#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , mod , i , j ,ans=1 ;
    cin>>n>>mod;
    long long int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n>mod)
    {
        cout<<"0";
        return 0;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            ans=(ans*(abs(arr[i]-arr[j]))%mod)%mod;
        }
    }
    cout<<ans%mod;
    return 0;
}
