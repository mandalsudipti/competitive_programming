#include<bits/stdc++.h>
using namespace std;
const int range = 1e6 + 5 ;
vector<bool>is_prime(range,true);
vector<int>prime;

void sieve()
{
    for(int i=2;i*i < range;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<range;j+=i)
                is_prime[j] = false;
        }
    }
    
    for(int i=2;i<range;i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    vector<int>valid_prime_so_far(range,0);
    vector<int>prime_so_far(range,0);
    
    bool flag = true ;
    for(int i=0;i<prime.size();i++)
    {
        prime_so_far[prime[i]]++;
        if(flag)
        {
            long long int x = prime[i] * prime[i] ;
            if(x >= range)
                flag = false ;
            else
                valid_prime_so_far[x]++;
        }
    }
    
    for(int i=1;i<range;i++)
    {
        prime_so_far[i]+=prime_so_far[i-1];
        valid_prime_so_far[i]+=valid_prime_so_far[i-1];
    }
        
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<prime_so_far[n] - valid_prime_so_far[n] + 1<<"\n";
    }
    cout<<endl;
    return 0;
}
