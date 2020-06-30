#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int x , y , n ;
        cin>>x>>y>>n;
        long long int k = (n/x)*x ;
        if(k+y<=n)
            k+=y;
        else
        {
            k-=x;
            k+=y;
        }
        cout<<k<<endl;
    }
    return 0;
}