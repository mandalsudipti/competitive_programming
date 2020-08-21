#include<bits/stdc++.h>
using namespace std;
const int range = 1e6+5;
const long long int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    vector<vector<long long int>>divisor(range);
    for(int i=1;i<range;i++)
    {
        for(int j=i;j<range;j+=i)
        {
            divisor[j].push_back(i);
        }
    }
    
    vector<long long int>sequence_here(range,0);
    vector<long long int>total_sequence(range,0);
    total_sequence[0] = 1 ;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<divisor[arr[i]].size();j++)
        {
            int d = divisor[arr[i]][j];
            sequence_here[d] = total_sequence[d-1];
        }
        for(int j=0;j<divisor[arr[i]].size();j++)
        {
            int d = divisor[arr[i]][j];
            total_sequence[d] = (total_sequence[d] + sequence_here[d])%mod;
        }
    }
    
    long long int ans = 0 ;
    for(int i=1;i<range;i++)
        ans = (ans+total_sequence[i])%mod;
        
    cout<<ans;
    return 0;
}

