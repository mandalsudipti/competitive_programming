#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        vector<long long int>arr(n*k);
        
        for(int i=0;i<(n*k);i++)
            cin>>arr[i] ;
            
        int start = ((n/2) + (n%2) - 1)*k ;
        int p = n - (start / k);
        
        long long int sum = 0 ;
        for(int i=start;i<arr.size();i+=p)
        {
            sum+=arr[i];
        }
        
        cout<<sum<<endl;
    }
    
    return 0;
}