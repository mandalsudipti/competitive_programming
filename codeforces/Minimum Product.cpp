#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int a , b , x , y ,n ;
        cin>>a>>b>>x>>y>>n;
        
        long long int new_a = a - min(n,a-x);
        long long int new_b = b - min(n,b-y);
        
        if(new_a<=new_b)
        {
            n-=(a-new_a);
            a = new_a;
            b = b - min(n,b-y);
        }
        else
        {
            n-=(b-new_b);
            b = new_b;
            a = a - min(n,a-x);
        }
        
        cout<<a*b<<endl;
    }
    
    return 0;
}