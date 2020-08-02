#include<bits/stdc++.h>
using namespace std;

int main()
{
    long double n , m ;
    cin>>n>>m;
    long double sum = 0 , sum_x = 0;
    long long int x , d ;
    while(m--)
    {
        cin>>x>>d;
        sum_x+=x;
        if(d>=0)
            sum+=((n*(n-1))/2)*d ;
        else
        {
            long long int a = (n-1)/2 , b = (n-1)/2 + ((int)(n-1)%2) ;
            sum+=( (a*(a+1))/2 + (b*(b+1))/2 )*d ;
        }
    }
    long double avg = (sum + (sum_x*n))/n ; 
    cout<<fixed<<setprecision(18)<<avg;
    
    return 0;
}