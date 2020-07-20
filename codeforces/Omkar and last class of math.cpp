#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n;
        cin>>n;
        if(n%2==0)
            cout<<(n/2)<<" "<<(n/2)<<endl;
        else
        {
            long long int lcm = n-1 , a = 1 , b = n-1 ;
            for(int i=3;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    long long int s = i , t = n/i;
                    //cout<<s<<" "<<t<<endl;
                    if(s*(t-1)<lcm)
                    {
                        lcm = s*(t-1) ;
                        a = s ;
                        b = s*(t-1) ;
                    }
                    if((s-1)*t<lcm)
                    {
                        lcm = (s-1)*t;
                        a = t ;
                        b = (s-1)*t ;
                    }
                }
            }
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}