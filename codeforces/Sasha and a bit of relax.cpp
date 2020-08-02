#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    long long int val , prefix_xor ;
    map<long long int , long long int>even_prefix;
    map<long long int , long long int>odd_prefix;
    
    odd_prefix[0]++;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(i==0)
        {
            prefix_xor = val ;
            even_prefix[prefix_xor]++;
            continue;
        }
        
        prefix_xor = prefix_xor^val;
        //cout<<prefix_xor<<endl;
        i%2==0 ? even_prefix[prefix_xor]++ : odd_prefix[prefix_xor]++;
    }
    
    long long int ans = 0 ;
    for(auto itr = even_prefix.begin();itr!=even_prefix.end();++itr)
    {
        long long int x = itr->second ;
        if(x>1)
            ans+=(x*(x-1))/2;
    }
    for(auto itr=odd_prefix.begin();itr!=odd_prefix.end();++itr)
    {
        long long int x = itr->second;
        if(x>1)
            ans+=(x*(x-1))/2;
    }
    
    cout<<ans<<endl;
    
    return 0;
}


