#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        
        vector<int>arr(n);
        vector<long long int>prefix_sum(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
            prefix_sum[i] = arr[i];
            if( i > 0)
                prefix_sum[i]+=prefix_sum[i-1];
        }
        
        vector<long long int>inc_ele ;
        vector<int>pos ;
        long long int maximum = prefix_sum.back();
        for(int i = 0 ; i < n ; i++)
        {
            if(prefix_sum[i] > 0 && (inc_ele.size() == 0 || prefix_sum[i] > inc_ele.back() ) )
            {
                inc_ele.push_back(prefix_sum[i]);
                pos.push_back(i);
                maximum = max(maximum , prefix_sum[i]);
            }
        }
        
        while(m--)
        {
            int x ;
            cin>>x ;
            
            int idx = lower_bound(inc_ele.begin(),inc_ele.end(),x) - inc_ele.begin() ;
            if(idx < inc_ele.size())
                cout<<pos[idx]<<" ";
            else
            {
                if(prefix_sum.back() <= 0)
                    cout<<"-1"<<" ";
                else
                {
                    x-=maximum ;
                    long long int entire_round = (x / prefix_sum.back()) + ( x % prefix_sum.back() != 0) ;
                    long long int step = (entire_round * n)  ;
                    x+=maximum;
                    x-=(entire_round * prefix_sum.back());
                    
                    idx = lower_bound(inc_ele.begin() , inc_ele.end() , x) - inc_ele.begin() ;
                    step+=pos[idx];
                    cout<<step<<" ";
                }
            }
        }
        cout<<endl;
    }
    
    return 0;
}


