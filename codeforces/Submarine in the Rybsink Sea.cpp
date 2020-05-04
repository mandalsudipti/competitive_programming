#include<bits/stdc++.h>
using namespace std;

const long long int mod = 998244353;

int main()
{
    int n ;
    cin>>n;
    vector<vector<long long int>>digit(n);
    long long int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        while(val!=0)
        {
            digit[i].push_back(val%10);
            val=val/10;
        }
    }
    vector<int>arr(digit[0].size());
    for(int i=0;i<arr.size();i++)
    {
        long long int sum =0 ;
        for(int j=0;j<n;j++)
            sum+=digit[j][i];
        sum = sum*n;
        arr[i]=sum%mod;
    }
    long long int ans=0 , idx=1;
    for(int i=0;i<arr.size();i++)
    {
        ans = (ans+(arr[i]*idx)%mod)%mod;
        idx=(idx*10)%mod;
        ans = (ans+(arr[i]*idx)%mod)%mod;
        idx=(idx*10)%mod;
    }
    cout<<ans%mod;
    return 0;
}