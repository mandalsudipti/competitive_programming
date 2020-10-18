#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , q ;
        cin>>n>>q;
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        long long int sum = 0  , odd = 0 , even = 0 ;
        for(int i=0;i<n;i++)
        {
            if(odd==0 && (i==n-1||arr[i]>arr[i+1]))
                odd = arr[i];
            if(odd!=0 && i<n-1 && arr[i]<arr[i+1])
                even = arr[i];
                
            if(i==n-1 || (odd!=0 && even!=0))
            {
                sum+=(odd-even);
                odd = even = 0 ;
            }
        }
        
        cout<<sum<<endl;
    }
    
    return 0;
}