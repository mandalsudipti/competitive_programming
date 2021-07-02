#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<int>arr(n+1) ;
        for(int i = 1 ; i <= n ; i++)
            cin>>arr[i] ;
            
        long long int count = 0 ; 
        for(int i = 1 ; i <= n ; i++)
        {
            int rem = i%arr[i] ;
            int start = arr[i] - rem ;
            
            for(int j = start ; j <= n ; j+=arr[i])
            {
                if(i == j)
                    continue ;
                if(arr[i]*arr[j] == i+j)
                    count++;
            }
        }
        cout<<(count/2)<<endl;
    }
    return 0 ;
}