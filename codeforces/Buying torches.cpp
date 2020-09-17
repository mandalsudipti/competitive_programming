#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int x , y , k ;
        cin>>x>>y>>k;
        long long int stick = k-1 + (k*y) ;
        
        cout<<(stick/(x-1)) + (stick%(x-1)!=0) + k<<endl;
    }
    return 0;
}
