#include<bits/stdc++.h>
using namespace std ;

const long long int mod = 1e9 + 7 ;

long long int factorial(long long int num)
{
    long long int ans = 1 ;
    for(int i = 2 ; i <= num ; i++)
        ans = (ans * i)%mod ;
        
    return ans ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<int>arr(n) ;
        int AND = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i] ;
            if(i == 0)
                AND = arr[i] ;
            else
                AND = AND & arr[i] ;
        }
        
        long long int boundary_element = 0 , other_element = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] == AND)
                boundary_element++ ;
        }
        
        other_element = n - 2;
        long long int ans = (boundary_element *(boundary_element - 1))%mod * factorial(other_element) ;
        
        cout<<ans%mod<<endl;
    }
    
    return 0 ;
}