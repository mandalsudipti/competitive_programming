#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    
    long long int ans = 1 ;
    for(int i=1;i<n;i++)
        ans = ans * i ;
    ans = (ans * 2)/n; 
    cout<<ans<<endl;
    
    return 0;
}