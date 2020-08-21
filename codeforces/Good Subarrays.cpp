#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        string S;
        cin>>n>>S;
        vector<long long int>prefix_sum(n);
        map<long long int , long long int>freq;
        freq[0]++;
        for(int i=0;i<n;i++)
        {
            prefix_sum[i] = S[i] - 48 ;
            if(i>0)
                prefix_sum[i]+=prefix_sum[i-1];
            freq[prefix_sum[i] - (i+1)]++;
        }
        
        long long int combination = 0 ;
        for(auto itr = freq.begin();itr!=freq.end();++itr)
        {
            combination+=((itr->second)*(itr->second - 1))/2 ;
        }
        cout<<combination<<endl;
    }
    
    return 0;
}
