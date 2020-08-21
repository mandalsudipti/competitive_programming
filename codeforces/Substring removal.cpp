#include<bits/stdc++.h>
using namespace std;

const long long int mod = 998244353 ;

int main()
{
    int len ;
    string S;
    cin>>len>>S;
    long long int l = 1 , r = 1 ;
    for(int i=1;i<len;i++)
    {
        if(S[i]==S[0])
            l++;
        else
            break;
    }
    
    for(int i=len-2;i>=0;i--)
    {
        if(S[i]==S[len-1])
            r++;
        else
            break;
    }
    
    if(S[0]!=S[len-1])
    {
        cout<<(l+r+1)%mod;
        return 0;
    }
    else
    {
        cout<<((l+1)*(r+1))%mod;
    }
    return 0;
}


