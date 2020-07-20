#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int x , y , z  ;
        cin>>x>>y>>z;
        long long int a , b ,c ;
        a = b = x ;
        if(y<=x)
        {
            a = y ;
            c = y ;
        }
        else
        {
            c = y ;
        }
        b = min(b,z);
        c = min(c,z);
        
        if(max(a,b)==x && max(a,c)==y && max(b,c)==z)
        {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
