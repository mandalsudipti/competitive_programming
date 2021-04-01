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
        vector<long long int>arr(2*n);
        for(int i = 0 ; i < 2*n ; i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        
        vector<long long int>distinct;
        bool possible = true ;
        for(int i = 0 ; i < 2*n ; i+=2)
        {
            if(arr[i]!=arr[i+1] || arr[i]%2 == 1)
            {
                possible = false;
                break;
            }
            distinct.push_back(arr[i]);
        }
        if(!possible)
        {
            cout<<"NO"<<endl;
            continue ;
        }
        long long int sum_so_far = 0 ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            distinct[i]-=(sum_so_far * 2);
            if(distinct[i]%(2*(i+1)))
            {
                possible = false;
                break;
            }
            distinct[i] = distinct[i] / (2*(i+1)) ;
            if( ( i+1 < n && distinct[i] >= distinct[i+1] ) || distinct[i] <= 0)
            {
                possible = false;
                break;
            }
            sum_so_far+=distinct[i] ;
        }
        
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}