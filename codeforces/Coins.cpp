#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , s ;
    cin>>n>>s;
    long long int x = min(n,s);
    long long int cnt = s/x + (s%x!=0) ;
    cout<<cnt;
    
    return 0;
}