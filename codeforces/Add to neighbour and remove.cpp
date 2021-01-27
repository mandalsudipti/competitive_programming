#include<bits/stdc++.h>
using namespace std;

int count_op(vector<long long int>&prefix_sum , int find)
{
    int  cnt = 0 , pre = -1 , add = find;
    while(true)
    {
        int idx = lower_bound(prefix_sum.begin() , prefix_sum.end() , find) - prefix_sum.begin() ;
        if( idx > prefix_sum.size() || prefix_sum[idx] != find)
            return INT_MAX ;
            
        if(pre == -1)
            cnt+=idx;
        else
            cnt+=(idx - pre - 1);
            
        pre = idx ;
        find+=add;
        
        if(idx == prefix_sum.size() - 1)
            break;
    }
    
    return cnt ;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<long long int>arr(n);
        vector<long long int>prefix_sum(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
            prefix_sum[i] = arr[i];
            if(i>0)
                prefix_sum[i]+=prefix_sum[i-1];
        }
        
        int min_op = n - 1 ;
        for(int i = 1 ; i<= sqrt(prefix_sum[n-1]) ; i++)
        {
            if(prefix_sum[n-1] % i == 0)
            {
                int x = count_op(prefix_sum , i) , y = count_op(prefix_sum , prefix_sum[n-1]/i) ;
                min_op = min( min_op , min(x,y));
            }
        }
        
        cout<<min_op<<endl;
    }
    
    return 0;
}

