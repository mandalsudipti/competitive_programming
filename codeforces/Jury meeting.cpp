#include<bits/stdc++.h>
using namespace std ;

const long long int range = 2e5 + 10 , mod = 998244353 ;
vector<long long int>fact ;


long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1; 
 
    x = x % p; 

    while (y > 0)
    {
     
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long int modInverse(long long int n, long long int p)
{
    return power(n, p - 2, p);
}

long long int nCrModPFermat(long long int n, int r, long long int p)
{
    if (n < r)
        return 0;
        
    if (r == 0)
        return 1;
    
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}

int main()
{
    int T ;
    cin>>T;
    
    fact.push_back(1) ;
    for(int i = 1 ; i < range ; i++)
        fact.push_back((fact[i-1] * i)%mod) ;
        
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n) ;
        
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        sort(arr.begin() , arr.end()) ;
        if(arr[n-1] == arr[n-2])
            cout<<fact[n]<<endl;
        else if(arr[n-1] - arr[n-2] > 1)
            cout<<"0"<<endl;
        else
        {
            int second_max = 0 ;
            for(int i = n-2 ; i >= 0 ; i--)
            {
                if(arr[i] == arr[n-2])
                    second_max++;
            }
            
            long long int ans = 0 ;
            long long int other = n - second_max - 1 ;
            for(int boundary = n-1 ; boundary >= 0 ; boundary--)
            {
                int left = boundary , right = n - 1 - boundary ;
                if(right > other)
                    break;
                    
                ans+=( ((second_max * fact[left])%mod) * ((nCrModPFermat(other, right , mod) * fact[right])%mod) )%mod ;
                ans = ans % mod ;
            }
            
            cout<<ans<<endl;
        }
    }
    return 0 ;
}
