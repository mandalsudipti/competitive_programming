#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a , b , c  ;
    cin>>a>>b>>c;
    long long int x = c*2 + min(a,b)*2 + (a!=b) ;
    cout<<x<<endl;
    return 0;
}