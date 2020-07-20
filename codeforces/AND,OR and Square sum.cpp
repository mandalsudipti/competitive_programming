#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    long long int val ;
    vector<int>bit_freq(23,0);
    vector<long long int>ans(n,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>val;
        for(long long int bit=0;bit<22;bit++)
        {
            if(val & (1ll<<bit))
                bit_freq[bit]++;
        }
    }
    
    for(long long int i=0;i<bit_freq.size();i++)
    {
        for(int j=0;j<bit_freq[i];j++)
            ans[j]|=(1ll<<i);
    }
    
    long long int square_sum = 0 ;
    for(int i=0;i<n;i++)
        square_sum+=(ans[i]*ans[i]);
        
    cout<<square_sum;
    
    return 0;
}
