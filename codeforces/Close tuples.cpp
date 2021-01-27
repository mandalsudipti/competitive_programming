#include<bits/stdc++.h>
using namespace std;

const long long int p = 1e9+7;
vector<long long int>fac;

long long power(unsigned long long x, long long int y, long long int p)
{
    long long int res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1ll)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1ll; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long int n,  long long int p)
{
    return power(n, p - 2, p);
}

long long nCrModPFermat(long long int n , long long int r, long long int p)
{
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;
}

int main()
{
    int T;
    cin>>T;
    
    fac.push_back(1);
    fac.push_back(1);
    
    for(int i=2;i <= 200005 ; i++)
        fac.push_back( (i * fac[i-1])%p );
        
    while(T--)
    {
        int n ;
        long long int len , diff ;
        cin>>n>>len>>diff;
        vector<long long int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        sort(arr.begin() , arr.end());
        
        long long int  ans  = 0;
        int start = 0 , end = 0 ;
        
        while(start < n)
        {
            while(arr[end+1] - arr[start] <= diff && end+1 < n)
                end++;
                
            if(end - start + 1 >= len)
            {
                long long int x = (end - start + 1);
                x--;
                ans+=(nCrModPFermat(x, len-1, p));
                ans = ans % p ;
            }
            start++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
