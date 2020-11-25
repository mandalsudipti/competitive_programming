#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        vector<pair<long long int,int>>factor_freq ;
        
        if(n%2 == 0)
        {
            factor_freq.push_back(make_pair(2,0));
            while(n%2 == 0)
            {
                factor_freq[factor_freq.size() - 1].second++;
                n = n/2;
            }
        }
        
        for(int i=3;i<=sqrt(n);i+=2)
        {
            if(n%i == 0)
            {
                factor_freq.push_back(make_pair(i,0));
                int x = factor_freq.size() -1 ;
                while(n%i == 0)
                {
                    factor_freq[x].second++;
                    n = n/i ;
                }
            }
        }
        if(n >2)
            factor_freq.push_back(make_pair(n,1));
            
        /*for(int i=0;i<factor_freq.size();i++)
            cout<<factor_freq[i].first<<" ";
        cout<<"------------------\n";*/
        int len = 1 ;
        for(int i=0;i<factor_freq.size();i++)
        {
            len = max(len , factor_freq[i].second) ;
        }
        
        vector<long long int>ans(len , 1);
        for(int i=0;i<factor_freq.size();i++)
        {
            int idx = len - factor_freq[i].second ;
            ans[idx] = factor_freq[i].first * ans[idx] ;
        }
        
        for(int i=1;i<ans.size();i++)
            ans[i] = ans[i] * ans[i-1];
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}