#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , k ;
    cin>>n>>k;
    string S ;
    cin>>S;
    
    string ans = "" ;
    for(int i = 0 ; i < min(n,k) ; i++)
    {
        string prefix = S.substr(0,i+1);
        string tmp = "";
        int idx = 0 ;
        for(int j = 0 ; j < k ; j++)
        {
            tmp+=prefix[idx];
            idx++;
            if(idx >= prefix.length())
                idx = 0 ;
        }
        if(i == 0)
            ans = tmp ;
        else
            ans = min(ans , tmp);
    }
    
    cout<<ans<<endl;
    
    return 0 ;
}