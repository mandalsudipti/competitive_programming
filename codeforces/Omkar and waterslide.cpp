#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    long long int total_cost = 0 ;
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]<arr[i-1])
            total_cost+=(arr[i-1] - arr[i]);
    }
    
    cout<<total_cost<<endl;
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}