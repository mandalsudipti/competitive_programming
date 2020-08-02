#include<bits/stdc++.h>
using namespace std;

long  long int max_diff(vector<long long int>&arr , int end , int left , vector<long long int>&left_max)
{
    int start = end - (2*left) + 1 ;
    long long int max_diff = 0 , tmp = 0;
    for(int i=end;i>=start;i-=2)
    {
        if(i-2<0)
            break;
        tmp+=arr[i] + arr[i-1] ;
        long long int len = (end - i + 2) ;
        long long int diff = left_max[i-2]*(len/2) - tmp ;
        max_diff = max(max_diff,diff);
    }
    return max_diff ;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , move ,left ;
        cin>>n>>move>>left;
        vector<long long int>arr(n);
        vector<long long int>left_max(n-1,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n-1;i++)
        {
            if(i==0)
                left_max[i] = arr[0] + arr[1] ;
            else
                left_max[i] = max(left_max[i-1] , arr[i]+arr[i+1]) ;
        }
        long long int sum = 0 ;

        for(int i=0;i<=move;i++)
            sum+=arr[i];
            
        sum+=max_diff(arr,move,left,left_max);
        cout<<sum<<endl;
    }
    return 0;
}