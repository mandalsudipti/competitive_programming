#include<bits/stdc++.h>
using namespace std;

const long long int mod = 998244353 ;
int main()
{
    long long int n  , k , k1;
    cin>>n>>k;
    k1=n-k;
    long long int sum = ((n*(n+1))/2) - ((k1*(k1+1))/2);
    
    long long int loc[n+1],val ;
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        loc[val]=i;
    }
    vector<int>arr;
    for(int i=n;i>n-k;i--)
        arr.push_back(loc[i]);
    sort(arr.begin(),arr.end());
    long long int cnt=1;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]-arr[i-1]>1)
        {
            cnt=(cnt*(arr[i]-arr[i-1]))%mod;
        }
    }
    
    cout<<sum<<" "<<cnt%mod;
    return 0;
}