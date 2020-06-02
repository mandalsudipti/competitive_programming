#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;

int main()
{
    int n , l , r ;
    cin>>n>>l>>r;
    
    long long int rem_0 = (r-l+1)/3 ;
    if((r-l+1)%3==1 && l%3==0)
        rem_0++;
    if((r-l+1)%3==2 && (l%3==0 || (l+1)%3==0))
        rem_0++;
    long long int rem_1 = rem_0 - 1 , rem_2 = rem_0 - 1;
    if(l%3==1)
    {
        rem_1++;
        rem_2++;
    }
    else if(l%3==2)
        rem_2++;
        
    if(r%3==2)
    {
        rem_2++;
        rem_1++;
    }
    else if(r%3==1)
        rem_1++;
    long long int pre_0 = rem_0 , pre_1 = rem_1 , pre_2 = rem_2 , cur_0 , cur_1 , cur_2 ;
    
    for(int i=1;i<n;i++)
    {
        cur_0 = ((rem_0*pre_0)%mod + (rem_1*pre_2)%mod + (rem_2*pre_1)%mod)%mod;
        cur_1 = ((rem_0*pre_1)%mod + (rem_1*pre_0)%mod + (rem_2*pre_2)%mod)%mod;
        cur_2 = ((rem_0*pre_2)%mod + (pre_0*rem_2)%mod + (rem_1*pre_1)%mod)%mod;
        pre_1=cur_1;
        pre_0=cur_0;
        pre_2=cur_2;
    }
    cout<<pre_0;
    
    return 0;
}

