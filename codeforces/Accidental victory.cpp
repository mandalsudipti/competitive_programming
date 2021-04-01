#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<pair<long long int,int>>arr(n);
        vector<long long int>prefix_sum(n,0);
        
        for(int i = 0 ; i < n ; i++)
        {
            int val ;
            cin>>val;
            arr[i] = make_pair(val,i);
        }
        
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < n ; i++)
        {
            prefix_sum[i] = arr[i].first ;
            if(i > 0)
                prefix_sum[i]+=prefix_sum[i-1];
        }
        
        vector<int>winner ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if( i == n-1)
                winner.push_back(arr[i].second);
            else if(prefix_sum[i] >= arr[i+1].first)
                winner.push_back(arr[i].second);
            else
                break;
        }
        
        sort(winner.begin(),winner.end());
        cout<<winner.size()<<endl;
        for(int i = 0 ; i < winner.size() ; i++)
            cout<<winner[i]+1<<" ";
        cout<<endl;
    }
    
    return 0;
}