#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , i=3 ;
    cin>>n;
    vector<long long int>prime_factor;
    
    if(n%2==0)
        prime_factor.push_back(2);
    while(n%2==0)
    {
        n=n/2;
    }
    while(i<=sqrt(n))
    {
        if(n%i==0)
        {
            prime_factor.push_back(i);
            while(n%i==0)
                n=n/i;
        }
        i+=2;
    }
    if(n>2)
        prime_factor.push_back(n);
    if(prime_factor.size()==1)
        cout<<prime_factor[0];
    else
        cout<<"1";
        
    return 0;
}