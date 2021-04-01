#include<bits/stdc++.h>
using namespace std;

bool valid(long long int n)
{
    long long int tmp = n , sum = 0 ;
    while(n != 0)
    {
        sum+=(n%10);
        n = n / 10 ;
    }
    
    if(__gcd(tmp,sum) != 1)
        return true ;
    else
        return false ;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        
        if(valid(n))
            cout<<n<<endl;
        else if(valid(n+1))
            cout<<(n+1)<<endl;
        else
            cout<<(n+2)<<endl;
    }
    
    return 0 ;
}
