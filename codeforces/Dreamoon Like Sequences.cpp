#include<bits/stdc++.h>
using namespace std;

int MSB(int num)
{
    int ans = -1;
    while(num>0)
    {
        ans++;
        num/=2;
    }
    return ans;
}
void solve()
{
    long long int num , mod ;
    cin>>num>>mod;
    if(num==1)
    {
        cout<<num%mod<<endl;
        return;
    }
    int msb = MSB(num);
    vector<long long int>bits;
    for(int i=0;i<msb;i++)
        bits.push_back(pow(2,i));
    int tmp = (num^(1<<msb))+1;
    bits.push_back(tmp);
    
    vector<long long int>suffix_sum(bits.size());
    for(int i=bits.size()-1;i>=0;i--)
    {
        if(i==bits.size()-1)
            suffix_sum[i] = bits[i];
        else
        {
            suffix_sum[i] = bits[i] + suffix_sum[i+1];
        }
    }
    vector<vector<long long int>>len(msb+1);
    len[1].push_back(num) ;
    
    if(len.size()>2)
    {
        for(int i=0;i+1<bits.size();i++)
        {
            len[2].push_back( (bits[i]*suffix_sum[i+1])%mod);
        }
    }
    
    for(int i=3;i<len.size();i++)
    {
        for(int j=0;j+i-1<len.size();j++) // start from j 
        {
            //len[i].push_back((bits[j]*len[i-1][j+1])%mod);
            long long int tmp = 0 ;
            for(int k=j+1;k<len[i-1].size();k++)
                tmp =(tmp+len[i-1][k])%mod;
            len[i].push_back( (bits[j]*tmp)%mod);
        }
    }
    
    long long int len_msb = 1 ;
    for(int i=0;i<bits.size();i++)
        len_msb = (len_msb*bits[i])%mod;
     
    long long int sum = 0;
    for(int i=1;i<len.size();i++)
    {
        //cout<<i<<endl;
        for(int j=0;j<len[i].size();j++)
        {
            //cout<<len[i][j]<<" ";
            sum = (sum+len[i][j])%mod;
        }
        //cout<<endl;
    }
    cout<<(sum+len_msb)%mod<<endl;
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
