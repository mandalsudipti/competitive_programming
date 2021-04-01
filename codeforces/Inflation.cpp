#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k ;
        vector<long long int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        long long int prefix_sum = arr[0] ;
        long long int add = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            long long int x = (100 * arr[i])/k + ((100 * arr[i])%k != 0) ;
            if(prefix_sum < x)
            {
                add+=(x - prefix_sum);
                prefix_sum = x ;
            }
            prefix_sum+=arr[i];
        }
        
        cout<<add<<endl;
    }
    
    return 0;
}
