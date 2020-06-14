#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long int ans = 0 ;
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
            ans = max(ans , arr[i]);
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
                ans = max(ans , arr[i]|arr[j]|arr[k]);
            if(j==n-1)
                ans = max (ans , arr[i]|arr[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}