#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>a(n) , b(n) , prefix_sum(n) ;
    
    for(int i = 0 ; i < n ; i++)
        cin>>a[i] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>b[i] ;
        prefix_sum[i] = a[i] * b [i] ;
        if(i > 0)
            prefix_sum[i]+=prefix_sum[i-1] ;
    }
    
    vector<vector<long long int>>reverse_subarray_sum( n ,vector<long long int>(n,0));
    
    for(int i = 0 ; i < n ; i++)
        reverse_subarray_sum[i][i] = a[i] * b[i] ;
        
    long long int maximum = prefix_sum.back() ;
    
    for(int len = 2 ; len <= n ; len++)
    {
        for(int start = 0 ; start < n ; start++)
        {
            int end = start + len - 1 ;
            if(end >= n)
                break;
                
            reverse_subarray_sum[start][end] = (a[start]*b[end] + b[start]*a[end]) ;
            if(len > 2)
                reverse_subarray_sum[start][end]+=reverse_subarray_sum[start+1][end-1] ;
                
            long long int cur_total = reverse_subarray_sum[start][end] + (start - 1 >= 0 ? prefix_sum[start-1] : 0) ;
            cur_total+=(end + 1 < n ? prefix_sum[n-1] - prefix_sum[end] : 0) ;
            
            maximum = max(maximum , cur_total);
        }
    }
    
    cout<<maximum<<endl;
    
    return 0 ;
}