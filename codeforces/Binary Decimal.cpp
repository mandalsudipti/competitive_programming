#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        int ans = 0 ;
        while(n > 0)
        {
            ans = max(ans , n%10) ;
            n = n/10 ;
        }
        cout<<ans<<endl;
    }
    return 0 ;
}