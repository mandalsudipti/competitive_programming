#include<bits/stdc++.h>
using namespace std;

long long int get_divisor(long long int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return i;
    }
    return n;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k ;
        cin>>n>>k;
        
        if(n%2==0)
        {
            cout<<n+(2*k)<<endl;
        }
        else
        {
            long long int smallest_divisor = get_divisor(n);
            n+=smallest_divisor;
            k--;
            cout<<n+(2*k)<<endl;
        }
    }
    return 0;
}
