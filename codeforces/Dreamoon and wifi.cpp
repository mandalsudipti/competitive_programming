#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long>fact(12);
    fact[0]=1;
    for(int i=1;i<=11;i++)
        fact[i]=fact[i-1]*i;
        
    string S , T ;
    cin>>S>>T;
    int diff_s = 0 , diff_t = 0 , extra = 0 ;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='+')
            diff_s++;
        else
            diff_s--;
    }
    for(int i=0;i<T.length();i++)
    {
        if(T[i]=='?')
            extra++;
        else if(T[i]=='+')
            diff_t++;
        else
            diff_t--;
    }
    int diff = abs(diff_s - diff_t) ;
    if(diff>extra || diff%2!=extra%2)
        cout<<"0";
    else
    {
        int x = (diff+extra)/2;
        long double ans = fact[extra]/(fact[x]*fact[extra-x]);
        cout<<fixed<<setprecision(11)<<ans/(1<<extra);
    }
    return 0;
}

